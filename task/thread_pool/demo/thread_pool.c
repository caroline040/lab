///////////////////////////////////////////////////////////
//
//  Copyright(C), 2013-2017, GEC Tech. Co., Ltd.
//
//  文件: lab/tpool/demo/thread_pool.c
//  日期: 2017-9
//  描述: 线程池实现模板
//
//  作者: Vincent Lin (林世霖)   微信公众号：秘籍酷
//  技术微店: http://weidian.com/?userid=260920190
//  技术交流: 260492823（QQ群）
//
///////////////////////////////////////////////////////////

#include "thread_pool.h"

void handler(void *arg)
{
	printf("[%u] is ended.\n",
		(unsigned)pthread_self());

	pthread_mutex_unlock((pthread_mutex_t *)arg);
}

void *routine(void *arg)
{
	thread_pool *pool = (thread_pool *)arg;
	struct task *p;

	while(1)
	{
		/*
		** push a cleanup functon handler(), make sure that
		** the calling thread will release the mutex properly
		** even if it is cancelled during holding the mutex.
		**
		** NOTE:
		** pthread_cleanup_push() is a macro which includes a
		** loop in it, so if the specified field of codes that 
		** paired within pthread_cleanup_push() and pthread_
		** cleanup_pop() use 'break' may NOT break out of the
		** truely loop but break out of these two macros.
		** see line 61 below.
		*/
		//================================================//
		pthread_cleanup_push(handler, (void *)&pool->lock);
		pthread_mutex_lock(&pool->lock);
		//================================================//

		// 1, no task, and is NOT shutting down, then wait
		while(pool->waiting_tasks == 0 && !pool->shutdown)
		{
			pthread_cond_wait(&pool->cond, &pool->lock);
		}

		// 2, no task, and is shutting down, then exit
		if(pool->waiting_tasks == 0 && pool->shutdown == true)
		{
			pthread_mutex_unlock(&pool->lock);
			pthread_exit(NULL); // CANNOT use 'break';
		}

		// 3, have some task, then consume it
		p = pool->task_list->next;
		pool->task_list->next = p->next;
		pool->waiting_tasks--;

		//================================================//
		pthread_mutex_unlock(&pool->lock);
		pthread_cleanup_pop(0);
		//================================================//

		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
		(p->do_task)(p->arg);
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

		free(p);
	}

	pthread_exit(NULL);
}

bool init_pool(thread_pool *pool, unsigned int threads_number)
{
	pthread_mutex_init(&pool->lock, NULL);
	pthread_cond_init(&pool->cond, NULL);

	pool->shutdown = false;
	pool->task_list = malloc(sizeof(struct task));
	pool->tids = malloc(sizeof(pthread_t) * MAX_ACTIVE_THREADS);

	if(pool->task_list == NULL || pool->tids == NULL)
	{
		perror("allocate memory error");
		return false;
	}

	pool->task_list->next = NULL;

	pool->max_waiting_tasks = MAX_WAITING_TASKS;
	pool->waiting_tasks = 0;
	pool->active_threads = 0;

	int i;
	for(i=0; i<threads_number; i++)
	{
		if(pthread_create(&((pool->tids)[i]), NULL,
					routine, (void *)pool) != 0)
		{
			perror("create threads error");
			return false;
		}

		pool->active_threads++;
		pool->max_index = i;

		#ifdef DEBUG
		printf("[%u]:[%s] ==> tids[%d]: [%u] is created.\n",
			(unsigned)pthread_self(), __FUNCTION__,
			i, (unsigned)pool->tids[i]);
		#endif
	}

	return true;
}

bool add_task(thread_pool *pool,
	      void *(*do_task)(void *arg), void *arg)
{
	struct task *new_task = malloc(sizeof(struct task));
	if(new_task == NULL)
	{
		perror("allocate memory error");
		return false;
	}
	new_task->do_task = do_task;
	new_task->arg = arg;
	new_task->next = NULL;

	//============ LOCK =============//
	pthread_mutex_lock(&pool->lock);
	//===============================//

	if(pool->waiting_tasks >= MAX_WAITING_TASKS)
	{
		pthread_mutex_unlock(&pool->lock);

		fprintf(stderr, "too many tasks.\n");
		free(new_task);

		return false;
	}
	
	struct task *tmp = pool->task_list;
	while(tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new_task;
	pool->waiting_tasks++;

	//=========== UNLOCK ============//
	pthread_mutex_unlock(&pool->lock);
	//===============================//

	pthread_cond_signal(&pool->cond);
	return true;
}

int add_thread(thread_pool *pool, unsigned additional_threads)
{
	if(additional_threads == 0)
		return 0;

	unsigned total_threads =
			pool->active_threads + additional_threads;

	int i, actual_increment = 0;
	for(i = pool->active_threads;
	    i < total_threads && i < MAX_ACTIVE_THREADS;
	    i++)
	{
		if(pthread_create(&((pool->tids)[i]),
					NULL, routine, (void *)pool) != 0)
		{
			perror("add threads error");

			// no threads has been created, return fail
			if(actual_increment == 0)
				return -1;

			break;
		}
		actual_increment++; 
		pool->max_index = i;

		#ifdef DEBUG
		printf("[%u]:[%s] ==> tids[%d]: [%u] is created.\n",
			(unsigned)pthread_self(), __FUNCTION__,
			i, (unsigned)pool->tids[i]);
		#endif
	}

	pool->active_threads += actual_increment;
	return actual_increment;
}

int remove_thread(thread_pool *pool, unsigned int removing_threads)
{
	if(removing_threads == 0)
		return pool->active_threads;

	int remaining_threads = pool->active_threads - removing_threads;
	remaining_threads = remaining_threads > 0 ? remaining_threads : 1;

	int i;
	for(i=pool->active_threads-1; i>remaining_threads-1; i--)
	{
		errno = pthread_cancel(pool->tids[i]);

		if(errno != 0)
			break;

		#ifdef DEBUG
		printf("[%u]:[%s] ==> cancelling tids[%d]: [%u]...\n",
			(unsigned)pthread_self(), __FUNCTION__,
			i, (unsigned)pool->tids[i]);
		#endif
	}

	if(i == pool->active_threads-1)
		return -1;
	else
	{
		pool->active_threads = i+1;
		return i+1;
	}
}

bool destroy_pool(thread_pool *pool)
{
	// 1, activate all threads
	pool->shutdown = true;
	pthread_cond_broadcast(&pool->cond);

	// 2, wait for their exiting
	int i;
	for(i=0; i<pool->max_index; i++)
	{
		errno = pthread_join(pool->tids[i], NULL);
		if(errno != 0)
		{
			printf("join tids[%d] error: %s\n",
					i, strerror(errno));
		}
		else
			printf("[%u] is joined\n", (unsigned)pool->tids[i]);
		
	}

	// 3, free memories
	free(pool->task_list);
	free(pool->tids);
	free(pool);

	return true;
}