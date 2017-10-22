//:travel_binary_tree.c -- Traverse a binary tree by using four different orders

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

#include "head.h"

/********************************************
	Creat Binary-Tree(Pre_Order)
********************************************/
void creat_btree(root *p2r)
{
	char ch;
	scanf("%c", &ch);
	if(ch == '#'){ //empty treenode;
		*p2r = NULL;
	}
	else{
		*p2r = (root)malloc(sizeof(treenode));
		if(*p2r == NULL){ //malloc fail!
			perror("malloc failed");
			exit(1);
		}
		(*p2r)->ch = ch;
		(*p2r)->pushed = false;

		// creat the left child
		creat_btree(&((*p2r)->lchild));

		// creat the right child
		creat_btree(&((*p2r)->rchild));
	}
}

/***************************
	MAIN function
***************************/
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
	travel("Traverse in pre_order 1:   ", travel_pre1, T);
	travel("Traverse in pre_order 2:   ", travel_pre2, T);
	travel("Traverse in in_order:    ", travel_center, T);
	travel("Traverse in post_order:  ", travel_post, T);
	travel("Traverse in level_order: ", travel_level, T);

	return 0;
}
