#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

#define TREE_NODE_DATATYPE int
#define BALANCE_FACTOR
#include "head4tree.h"

#define QUEUE_NODE_DATATYPE linktree
#include "head4queue.h"

#define MAX(a, b) \
		({ \
		typeof(a) _a = a; \
		typeof(b) _b = b; \
		(void)(&_a == &_b); \
		_a > _b ? _a : _b; \
		})

int height(linktree root)
{
	return ((root==NULL)? -1 : root->bf);
}

linktree LL(linktree root)
{
	linktree p = root->lchild;
	root->lchild = p->rchild;
	p->rchild = root;

	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	p->bf = MAX(height(p->lchild), root->bf) + 1;

	return p;
}

linktree RR(linktree root)
{
	linktree p = root->rchild;
	root->rchild = p->lchild;
	p->lchild = root;

	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	p->bf = MAX(root->bf, height(p->rchild)) + 1;

	return p;
}

linktree LR(linktree root)
{
	root->lchild = RR(root->lchild);
	return LL(root);
}

linktree RL(linktree root)
{
	root->rchild = LL(root->rchild);
	return RR(root);
}

linktree AVLinsert(tn_datatype n, linktree root)
{
	if(root == NULL)
		return new_node(n, NULL, NULL);

	if(n < root->data)
	{
		root->lchild = AVLinsert(n, root->lchild);

		if(height(root->lchild) - height(root->rchild) == 2)
		{
			if(n < root->lchild->data) // LL
				root = LL(root);
			else if(n > root->lchild->data) // LR
				root = LR(root);
		}
	}
	else if(n > root->data)
	{
		root->rchild = AVLinsert(n, root->rchild);

		if(height(root->rchild) - height(root->lchild) == 2)
		{
			if(n > root->rchild->data) // RR
				root = RR(root);
			else if(n < root->rchild->data) // RL
				root = RL(root);
		}
	}
	else
		printf("%d is already exist.\n", n);

	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	return root;
}

linktree AVLremove(tn_datatype n, linktree root)
{
	if(root == NULL)
		return NULL;

	if(n < root->data)
		root->lchild = AVLremove(n, root->lchild);
	else if(n > root->data)
		root->rchild = AVLremove(n, root->rchild);
	else
	{
		if(root->lchild != NULL)
		{
			linktree p;
			for(p=root->lchild; p->rchild!=NULL; p=p->rchild){;}
			root->data = p->data;
			root->lchild = AVLremove(p->data, root->lchild);
		}
		else if(root->rchild != NULL)
		{
			linktree p;
			for(p=root->rchild; p->lchild!=NULL; p=p->lchild){;}
			root->data = p->data;
			root->rchild = AVLremove(p->data, root->rchild);
		}
		else
		{
			free(root);
			return NULL;
		}
	}

	if(height(root->lchild) - height(root->rchild) == 2)
	{
		printf(":-)\n");
		if(height(root->lchild->lchild)-height(root->lchild->rchild) == 1 ||
			height(root->lchild->lchild)-height(root->lchild->rchild) == 0) //LL
			root = LL(root);
		else if(height(root->lchild->rchild)-height(root->lchild->lchild) == 1) //LR
			root = LR(root);
	}
	else if(height(root->rchild) - height(root->lchild) == 2)
	{
		printf(":-)\n");
		if(height(root->rchild->rchild)-height(root->rchild->lchild) == 1 ||
			height(root->rchild->rchild)-height(root->rchild->lchild) == 0) //RR
			root = RR(root);
		else if(height(root->rchild->lchild)-height(root->rchild->rchild) == 1) //RL
			root = RL(root);
	}

	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	return root;
}

static char *output_node(void *node)
{
	linktree cur = (linktree)node;
	char *buf = malloc(64);
	snprintf(buf, 64, "%d,%d", cur->data, cur->bf);
	//snprintf(buf, 64, "%d", cur->data);
	
	return buf;
}

int main(void)
{
	linktree root = NULL;
	srand(time(NULL));

	int i, n;
	for(i=0; i<16; i++)
	{
		printf("%d\n", n=rand() % 100);
		root = AVLinsert(n, root);
		DO_TREE_MAP(root, treenode, lchild, rchild, output_node);
	}

	while(1)
	{
		scanf("%d", &n);
		if((root=AVLremove(n, root)) == NULL)
			break;
		system("rm *html");
		DO_TREE_MAP(root, treenode, lchild, rchild, output_node);
	}
	return 0;
}
