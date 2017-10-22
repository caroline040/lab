#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#include "head4tree.h"

/* set a empty queue, front and rear
pointer both point to a head node */
void queue_init(linkqueue *pq)
{
	assert(pq);
	*pq = (linkqueue)malloc(sizeof(linknode) * 2);
	(*pq)->front = (*pq)->rear = (linklist)malloc(sizeof(linknode));
	(*pq)->rear->next = NULL;
}

/* check the queue is empty or not */
bool isempty(linkqueue q)
{
	assert(q);
	if(q->front == q->rear)
		return true;
	return false;
}

/* delete elements from the queue */
bool out_queue(linkqueue q, root *p2t)
{
	assert(q);
	if(isempty(q)){
		return false;
	}

	linklist p = q->front;

	q->front = q->front->next;
	free(p);
	*p2t= q->front->t;

	return true;
}

/* add element into the queue */
bool en_queue(linkqueue q, root t)
{
	assert(q);
	linklist pnew;
	pnew = (linklist)malloc(sizeof(linknode));
	if(pnew == NULL){
		perror("malloc failed");
		return false;
	}
	pnew->t = t;
	pnew->next = NULL;

	q->rear->next = pnew;
	q->rear = pnew;

	return true;
}

#if 1
/* show all elements in the current queue */
void show(linkqueue q)
{
	assert(q);
	if(isempty(q)){
		fprintf(stderr, "the queue is empty.\n");
		return;
	}

	linklist p;
	p = q->front->next;

	int i = 1;
	do{
		fprintf(stderr, "[%d]: %c\n", i++, p->t->ch);
		p = p->next;
	}while(p != NULL);

	return;
}

/* safely scanf */
bool s_scanf(const char *format, int *ele_loc)
{
	int ret1, ret2;
	while((ret1=scanf(format, ele_loc)) != 1 || \
		(ret2=getchar()) != '\n'){

		//if((ret1 != 1) && (errno == EINTR))
		if((ret1 != 1) )
			continue;

		while(getchar() != '\n'); // discards invalid inputs

		fprintf(stderr, "input invalid!\n");
		//fprintf(stderr, "pls insert an integer: ");
	}
	return true;
}
#endif
