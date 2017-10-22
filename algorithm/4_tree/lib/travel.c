#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define ACCESS_FLAG
#include "head4tree.h"

#define QUEUE_NODE_DATATYPE linktree
#include "head4queue.h"

void pre(linktree t)
{
	if(t == NULL)
		return;
	
	printf("%d ",t->data);
	pre(t->lchild);
	pre(t->rchild);
}


void mid_travel(linktree t)
{
	if(t == NULL)
		return;
	
	mid(t->lchild);
	printf("%d ",t->data);
	mid(t->rchild);
}

void pos(linktree t)
{
	if(t == NULL)
		return;

	pos(t->lchild);
	pos(t->rchild);
	printf("%d ",t->data);
}

void lel(linktree t)
{
	if(t == NULL)
		return;

	linkqueue q;
	q = init_queue();

	en_queue(q, t);

	linktree tmp;
	while(1)
	{
		if(!out_queue(q, &tmp))
			break;
		printf("%d ", tmp->data);

		if(tmp->lchild != NULL)
			en_queue(q, tmp->lchild);
		if(tmp->rchild != NULL)
			en_queue(q, tmp->rchild);
	}
}

void travel(linktree t)
{
	printf("pre: "); pre(t); printf("\n");
	printf("cen: "); cen(t); printf("\n");
	printf("pos: "); pos(t); printf("\n");
	printf("lel: "); lel(t); printf("\n");
}


/*
 * travel binary trees by Applying non_recursive method 
*/

#define STACK_NODE_DATATYPE linktree
#include "head4stack.h"

void travel_pre1(linktree T)
{
	linkstack top;
	top = init_stack();

	while(T != NULL || !is_empty_s(top))
	{
		if(T != NULL)
		{
			/********************
			   visit the node
			*********************/
			printf("%d\t", T->data);

			/*****************************
			   store the back-trace path
			******************************/
			push(&top, T);

			/***************************
			   follow the lchild path
			****************************/
			T = T->lchild;
		}
		else
		{
			/*************************************
			   hits a leaf-node, so pop up its
			   parent and visite the right child
			**************************************/
			pop(&top, &T);
			T = T->rchild;
		}
	}
}

/******************************************
	Visit Binary-Tree(Pre_Order2)
	imitate recurse arithmetic
*******************************************/
void travel_pre2(linktree T)
{
	if(T == NULL)
		return;

	linkstack top;
	top = init_stack();

	push(&top, T);

	sn_datatype x;
	while(!is_empty_s(top))
	{
		pop(&top, &x);
		fprintf(stderr, "%d", x->data);

		if(x->rchild != NULL)
			push(&top, x->rchild);
		if(x->lchild != NULL)
			push(&top, x->lchild);
	}
}

/*******************************************
	Visit Binary-Tree(In_Order)
*******************************************/
void travel_center(linktree T)
{
	linkstack top;
	top = init_stack();

	while(T != NULL || !is_empty_s(top))
	{
		if(T != NULL)
		{
			push(&top, T);
			T = T->lchild;
		}
		else
		{
			pop(&top, &T);
			printf("%c", T->data);
			T = T->rchild;
		}
	}
}

/*******************************************
	Visit Binary-Tree(Post_Order)
	imitate recurse arithmetic
*******************************************/
#if 0
void travel_post(linktree T)
{
	linkstack top;
	top = init_stack();

	if(T == NULL)
		return;

	push(&top, T);

	while(!is_empty_s(top))
	{

		sn_datatype x;
		pop(&top, &x);

		if(x->af)
			fprintf(stderr, "%d", x->data);
		else
		{
			/*************************************
			   push tree nodes of the opposite
			   sequence as POST order into stack:
			**************************************/

			// 1.push parent(be visited last)
			push(&top, x);

			// 2.push right child(be visited secondly)
			if(x->rchild != NULL)
				push(&top, x->rchild);

			// 3.push left child(be visited firstly)
			if(x->lchild != NULL)
				push(&top, x->lchild);

			x->af = true;
		}
	}
}
#endif

/************************************
	free memeries in heap
************************************/
void free_tree(linktree T)
{
	if(T != NULL)
	{
		free_tree(T->lchild);
		free_tree(T->rchild);
		free(T);
	}
}
