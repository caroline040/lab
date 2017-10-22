#define BALANCE_FACTOR
#include "head4tree.h"

height(linktree root)
{
	return root==NULL ? -1 : root->bf;
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

linktree RL(linktree root)
{
	root->rchild = RR(root->rchild);
	return LL(root);
}

linktree avl_insert(linktree root, int n)
{
	if(root == NULL)
		return new_node(n, NULL, NULL);

	if(n < root->data)
	{
		root->lchild = avl_insert(root->lchild, n);

		if(height(root->lchild)-height(root->rchild) == 2)
		{
			linktree p;
			if(n < root->lchild->data)
				root = RR(root);
			else if(n > root->lchild->data)
				root = LR(root);
		}
	}
	else if(n > root->data)
	{
		root->rchild = avl_insert(root->rchild, n);

		if(height(root->rchild)-height(root->lchild) == 2)
		{
			linktree p;
			if(n > root->rchild->data)
				root = LL(root);
			else if(n < root->rchild->data)
				root = RL(root);
		}
	}
	else
	{
		printf("%d exist.\n", n);
		return root;
	}
	
	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	return root;
}

linktree avl_remove(linktree root, int n)
{
	if(root == NULL)
		return NULL;

	if(n < root->data)
		root->lchild = avl_remove(root->lchild, n);
	else if(n > root->data)
		root->rchild = avl_remove(root->rchild, n);
	else
	{
		linktree p;
		
		if(root->lchild != NULL)
		{
			p = root->lchild;
			for(;p->rchild != NULL; p=p->rchild){;}
			root->data = p->data;
			root->lchild = avl_remove(root->lchild, p->data);
		}
		else if(root->rchild != NULL)
		{
			p = root->rchild;
			for(;p->lchild != NULL; p=p->lchild){;}
			root->data = p->data;
			root->rchild = avl_remove(root->rchild, p->data);
		}
		else
		{
			free(root);
			return NULL;
		}
	}

	if((height(root->lchild) - height(root->rchild)) == 2)
	{
		if(height(root->lchild->lchild) - height(root->lchild->rchild) == 0 ||
				height(root->lchild->lchild) - height(root->lchild->rchild) == 1)
			root = RR(root);
		else if(height(root->lchild->rchild) -height(root->lchild->lchild) == 1)
			root = LR(root);
	}
	else if((height(root->rchild) - height(root->lchild)) == 2)
	{
		if(height(root->rchild->rchild) - height(root->rchild->lchild) == 0 ||
				height(root->rchild->rchild) - height(root->rchild->lchild) == 1)
			root = LL(root);
		else if(height(root->rchild->lchild) -height(root->rchild->rchild) == 1)
			root = RL(root);
	}
	
	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	return root;
}

int main(void)
{
	linktree root = NULL;
	srand(time(NULL));

	int i, n;
	for(i=0; i<16; i++)
	{
		printf("%d\n", n=rand()%100);
		root = avl_insert(root, n);
		DO_TREE_MAP(root, treenode, lchild, rchild, draw);
	}

	while(1)
	{
		scanf("%d", &n);
		root = avl_remove(root, n);
		system("rm *html");
		DO_TREE_MAP(root, treenode, lchild, rchild, draw);
	}

	return 0;
}
