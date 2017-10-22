#include <stdio.h>
#include <time.h>
#include "head4tree.h"

#define MAX(a, b) ((a)>(b) ? (a) : (b))

int height(linktree root)
{
	if(root == NULL)
		return 0;

	return MAX(height(root->lchild), height(root->rchild)) + 1;
}

linktree LL(linktree root)
{
	linktree p = root->rchild;
	root->rchild = p->lchild;
	p->lchild = root;

	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	p->bf = MAX(root->bf, height(p->rchild)) + 1;

	return p;
}

linktree RR(linktree root)
{
	linktree p = root->lchild;
	root->lchild = p->rchild;
	p->rchild = root;

	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	p->bf = MAX(height(p->lchild), root->bf) + 1;

	return p;
}

linktree LR(linktree root)
{
	root->lchild = LL(root->lchild);
	return RR(root);
}

linktree LR(linktree root)
{
	root->lchild = LL(root->lchild);
	return RR(root);
}

linktree avl_insert(linktree root, tn_datatype data)
{
	if(root == NULL)
	{
		return new_node(data, NULL, NULL);
	}

	if(data < root->data)
		root->lchild = avl_insert(root->lchild, data);
	else
		root->rchild = avl_insert(root->rchild, data);

	if(height(root->lchild) - height(root->rchild) >= 2)
	{
		if(data < root->lchild->data) // LL
		{
			root = RR(root);
		}
		else if(data > root->rchild->data) // LR
		{
			root = RL(root);
		}
	}
	else if(height(root->rchild) - height(root->lchild) >= 2)
	{
		if(data > root->rchild->data) // RR
		{
			root = LL(root);
		}
		else if(data < root->lchild->data) // RL
		{
			root = LR(root);
		}
	}

	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	return root;
}

int main(void)
{
	linktree root = NULL;
	srand(time(NULL));

	int i;
	for(i=0; i<10; i++)
	{
		root = avl_insert(root, rand() % 100);
		DO_TREE_MAP(root, treenode, lchild, rchild, draw);
	}

	return 0;
}
