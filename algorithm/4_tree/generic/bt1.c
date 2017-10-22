//:travel_binary_tree.c -- Traverse a binary tree by using four different orders

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <malloc.h>

#include "head4tree.h"

linktree creat_btree(void)
{
	char ch;
	scanf("%c", &ch);

	if(ch != '#')
	{
		linktree new = (linktree)malloc(sizeof(treenode));
		new->data = ch;
		new->lchild = creat_btree();
		new->rchild = creat_btree();

		return new;
	}
	return NULL;
}

int main(void)
{
	linktree root;
	root = creat_btree();

	DO_TREE_MAP(root, treenode, lchild, rchild, draw);

	return 0;
}
