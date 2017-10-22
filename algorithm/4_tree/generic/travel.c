//:travel_binary_tree.c -- Traverse a binary tree by using four different orders

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <errno.h>
#include <malloc.h>

#include "head.h"

/*******************************************
	Visit Binary-Tree(Pre_Order)
*******************************************/
void travel_pre(root T)
{
	if(T != NULL){
		printf("%c",T->ch);
		travel_pre(T->lchild);
		travel_pre(T->rchild);
	}
}

/*******************************************
	Visit Binary-Tree(In_Order)
*******************************************/
void travel_center(root T)
{
	if(T != NULL){
		travel_center(T->lchild);
		printf("%c",T->ch);
		travel_center(T->rchild);
	}
}

/*******************************************
	Visit Binary-Tree(Post_Order)
*******************************************/
void travel_post(root T)
{
	if(T != NULL){
		travel_post(T->lchild);
		travel_post(T->rchild);
		printf("%c",T->ch);
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
		printf("%c", t->ch);

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

void travel(const char *info, void (*function)(root), root T)
{
	fputs(info, stderr);
	function(T);
	printf("\n");
}
