//:travel_binary_tree.c -- Traverse a binary tree by using four different orders

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

#include "head.h"

/******************************************
	Visit Binary-Tree(Pre_Order1)
*******************************************/
void travel_pre1(root T)
{
	stack top;
	init_stack(&top);

	while(T != NULL || !is_empty(top)){

		if(T != NULL){

			/********************
			   visit the node
			*********************/
			printf("%c", T->ch);

			/*****************************
			   store the back-trace path
			******************************/
			push(&top, T);

			/***************************
			   follow the lchild path
			****************************/
			T = T->lchild;
		}
		else{
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
void travel_pre2(root T)
{
	if(T == NULL)
		return;

	stack top;
	init_stack(&top);

	push(&top, T);

	datatype x;
	while(!is_empty(top)){

		pop(&top, &x);
		fprintf(stderr, "%c", x->ch);

		if(x->rchild != NULL)
			push(&top, x->rchild);
		if(x->lchild != NULL)
			push(&top, x->lchild);
	}
}

/*******************************************
	Visit Binary-Tree(In_Order)
*******************************************/
void travel_center(root T)
{
	stack top;
	init_stack(&top);

	while(T != NULL || !is_empty(top)){

		if(T != NULL){
			push(&top, T);
			T = T->lchild;
		}
		else{
			pop(&top, &T);
			printf("%c", T->ch);
			T = T->rchild;
		}
	}
}

/*******************************************
	Visit Binary-Tree(Post_Order)
	imitate recurse arithmetic
*******************************************/
void travel_post(root T)
{
	stack top;
	init_stack(&top);

	if(T == NULL)
		return;

	push(&top, T);

	while(!is_empty(top)){

		datatype x;
		pop(&top, &x);

		if(x->pushed)
			fprintf(stderr, "%c", x->ch);
		else{
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

			x->pushed = true;
		}
	}
}

/*******************************************
	Visit Binary-Tree(Level_Order)
*******************************************/
void travel_level(root t)
{
	linkqueue q;
	queue_init(&q);

	while(t != NULL){
		fprintf(stderr, "%c", t->ch);

		if(t->lchild != NULL)
			en_queue(q, t->lchild);
		if(t->rchild != NULL)
			en_queue(q, t->rchild);

		if(!out_queue(q, &t))
			return;
	}
}

/************************************
	free memeries in heap
************************************/
void free_tree(root T)
{
	if(T != NULL){
		free_tree(T->lchild);
		free_tree(T->rchild);
		free(T);
	}
}

void travel(const char *info, void (*function)(datatype), datatype T)
{
	fputs(info, stderr);
	function(T);
	printf("\n");
}
