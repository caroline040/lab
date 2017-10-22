#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TREE_NODE_DATATYPE int
#include "head4tree.h"

struct rb_root;
{
	linktree rb_node;
}*root = {NULL};

static char *draw(void *node)
{
	linktree cur = (linktree)node;
	char *buf = malloc(64);
	snprintf(buf, 64, "%d  ", cur->data);
	snprintf(buf+3, 60, "%c", cur->color == RB_BLACK ? 'b' : ' ');
	return buf;
}

void new_node(datatype data, linktree parent, linktree *proot)
{
	linktree new = (linktree)malloc(sizeof(treenode));
	new->data = data;
	new->parent = parent;
	new->lchild = new->rchild = NULL;
	new->color = RB_RED;

	*proot = new;
}

linktree LL(linktree root)
{
	linktree p = root->lchild;
	root->lchild = p->rchild;
	p->rchild = root;

	return p;
}

linktree RR(linktree root)
{
	linktree p = root->rchild;
	root->rchild = p->lchild;
	p->lchild = root;

	return p;
}

#if 0
linktree rb_insert(linktree parent, linktree root, datatype n)
{
	if(root == NULL)
		return new_node(n, parent, NULL, NULL, 0);

	if(n < root->data)
	{
		root->lchild = rb_insert(root, root->lchild, n);

		if(root->lchild->color == RB_RED)
		{
			if(root->rchild->color == RB_RED)
			{
				root->lchild->color = root->rchild->color = RB_BLACK;
				root->color = RB_RED;
			}
			else if(root->rchild->color == RB_BLACK)
			{
				if(n <  root->lchild->data)
				{
					root = LL(root);
					int c = root->rchild->color;
					root->rchild->color = root->color;
					root->color = c;
				}
				else if(n > root->lchild->data)
				{
					root->lchild = RR(root->lchild);
					int c = root->lchild->color;
					root->lchild->color = root->color;
					root->color = c;
				}
			}
		}
	}
	else if(n > root->data)
	{
		root->rchild = rb_insert(root, root->rchild, n);

		if(root->rchild->color == RB_RED)
		{
			if(root->lchild->color == RB_RED)
			{
				root->lchild->color = root->rchild->color = RB_BLACK;
				root->color = RB_RED;
			}
			else if(root->lchild->color == RB_BLACK)
			{
				if(n > root->rchild->data)
				{
					root = RR(root);
					int c = root->lchild->color;
					root->lchild->color = root->color;
					root->color = c;
				}
				else if(n < root->rchild->data)
				{
					root->rchild = RR(root->rchild);
					int c = root->rchild->color;
					root->rchild->color = root->color;
					root->color = c;
				}
			}
		}
	}
	else
	{
		printf("%d is already exist, omit it.\n", n);
		return root;
	}

	return root;
}
#endif

linktree rb_search(linktree root, datatype n)
{
	if(root == NULL)
		return NULL;

	if(n < root->data)
		root = rb_search(root->lchild, n);
	else if(n > root->data)
		root = rb_search(root->rchild, n);

	return root;
}

void rb_rebalance(linktree *proot, datatype n)
{
	linktree node = rb_search(*proot, n);

	linktree parent, gparent;

	while(((parent=node->parent) != NULL) && (parent->color == RB_RED))
	{
		gparent = parent->parent;
		if(parent == gparent->lchild)
		{
			linktree uncle = gparent->rchild;
			if(uncle != NULL && uncle->color == RB_RED) // RED-right-uncle
			{
				parent->color = uncle->color = RB_BLACK;
				gparent->color = RB_RED;

				node = gparent;
				continue;
			}

			if(uncle != NULL && uncle->color == RB_BLACK)// BLACK-right-uncle
			{
				if(parent->lchild == node)
				{
					rb_rotate_right(gpareng, root);
				}
			}
		}
	}
}

void __rb_insert(linktree *proot, datatype n)
{
	if(*proot == NULL)
	{
		new_node(n, NULL, proot);
		return;
	}

	if(n < (*proot)->data)
		rb_insert(&((*proot)->lchild), n);
	else if(n > (*proot)->data)
		rb_insert(&((*proot)->rchild), n);
	else
		printf("%d exist.\n", n);
}

void rb_insert(struct rb_root *root, datatype n)
{
	__rb_insert(root, n);
	rb_insert_color(root);
}

int main(void)
{
	srand(time(NULL));
	printf("%p\n", root->rb_node);
#if 0	
	int i, n;
	for(i=0; i<10; i++)
	{
		printf("%d\n", n=rand() % 100);
		rb_insert(root, n);
		root->color = RB_BLACK;
		DO_TREE_MAP(root, treenode, lchild, rchild, draw);
	}
#endif

	return 0;
}
