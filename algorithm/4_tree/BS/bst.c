#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#include "head4tree.h"
#include "head4stack.h"

linktree new_treenode(tn_datatype data, linktree l, linktree r)
{
	linktree new = (linktree)malloc(sizeof(treenode));
	new->data = data;
	new->lchild = l;
	new->rchild = r;

	return new;
}

linktree bst_insert(tn_datatype n, linktree root)
{
	if(root == NULL)
		return new_treenode(n, NULL, NULL);

	if(n < root->data)
		root->lchild = bst_insert(n, root->lchild);
	else if(n > root->data)
		root->rchild = bst_insert(n, root->rchild);
	else
		printf("%d is already exist.\n", n);

	return root;
}

linktree bst_remove(linktree root, tn_datatype n)
{
	if(root == NULL)
		return NULL;
	
	if(n < root->data)
		root->lchild = bst_remove(root->lchild, n);
	else if(n > root->data)
		root->rchild = bst_remove(root->rchild, n);
	else
	{
		if(root->lchild != NULL)
		{
			linktree p;
			for(p=root->lchild; p->rchild != NULL; p=p->rchild){;}
			root->data = p->data;
			root->lchild = bst_remove(root->lchild, p->data);
		}
		else if(root->rchild != NULL)
		{
			linktree p;
			for(p=root->rchild; p->lchild != NULL; p=p->lchild){;}
			root->data = p->data;
			root->rchild = bst_remove(root->rchild, p->data);
		}
		else
		{
			free(root);
			return NULL;
		}
	}
	return root;
}

int main(void)
{
	linktree root = NULL;
	srand(time(NULL));

	int i;
	for(i=0; i<10; i++)
	{
		root = bst_insert(rand()%100, root);
		DO_TREE_MAP(root, treenode, lchild ,rchild, draw);
	}

	travel(root);

	while(1)
	{
		scanf("%d", &i);
		root = bst_remove(root, i);
		system("rm *html");
		DO_TREE_MAP(root, treenode, lchild ,rchild, draw);
	}

	return 0;
}
