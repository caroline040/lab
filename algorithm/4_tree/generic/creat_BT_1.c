//:travel_binary_tree.c -- Traverse a binary tree by using four different orders

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

#include "head4tree.h"

/*
** Creat Binary-Tree(Pre_Order)
*/
void creat_btree(root *p2r)
{
	char ch;
	scanf("%c", &ch);

	if(ch == '#') //empty treenode;
		*p2r = NULL;
	else
	{
		*p2r = (root)malloc(sizeof(treenode));
		if(*p2r == NULL) //malloc fail!
		{
			perror("malloc failed");
			exit(1);
		}
		(*p2r)->ch = ch;
		creat_btree(&((*p2r)->lchild)); // creat the left child
		creat_btree(&((*p2r)->rchild)); // creat the right child
	}
}

/*
** MAIN function
*/
int main(void)
{
	/***********************
		CREATION
	***********************/
	root T;
	printf("Pls input elements in pre_order:\n");
	printf("-------------------\n");
	creat_btree(&T);
	printf("-------------------\n");

	/**********************************
		travel in varous means
	**********************************/
	pre(T);
	mid(T);
	pos(T);

	return 0;
}
