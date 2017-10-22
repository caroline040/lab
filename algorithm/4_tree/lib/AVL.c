#define BALANCE_FACTOR
#include "head4tree.h"

int height(linktree root)
{
	return (root == NULL) ? -1 : root->bf;
}

linktree right_rotate(linktree root)
{
	linktree p = root->lchild;
	root->lchild = p->rchild;
	p->rchild = root;
	
	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	p->bf = MAX(height(p->lchild), root->bf) + 1;

	return p;
}

linktree left_rotate(linktree root)
{
	linktree p = root->rchild;
	root->rchild = p->lchild;
	p->lchild = root;
	
	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	p->bf = MAX(root->bf, height(p->rchild)) + 1;

	return p;
}

linktree left_right_rotate(linktree root)
{
	root->lchild = left_rotate(root->lchild);
	return right_rotate(root);
}

linktree right_left_rotate(linktree root)
{
	root->rchild = right_rotate(root->rchild);
	return left_rotate(root);
}

linktree AVL_insert(linktree root, tn_datatype data)
{
	if(root == NULL)
		return new_node(data, NULL, NULL);

	if(data < root->data)
		root->lchild = AVL_insert(root->lchild, data);
	else if(data > root->data)
		root->rchild = AVL_insert(root->rchild, data);
	else
	{
		printf("%d is already exist.\n", data);
	}

	if(height(root->lchild) - height(root->rchild) == 2)
	{
		if(data < root->lchild->data) // LL
			root = right_rotate(root);
		else if(data > root->lchild->data) //LR
			root = left_right_rotate(root);
	}
	else if(height(root->rchild) - height(root->lchild) == 2)
	{
		if(data > root->rchild->data) // RR
			root = left_rotate(root);
		else if(data < root->rchild->data) //RL
			root = right_left_rotate(root);
	}

	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	return root;
}

linktree AVL_remove(linktree root, tn_datatype data)
{
	if(root == NULL)
		return NULL;

	if(data < root->data)
		root->lchild = AVL_remove(root->lchild, data);
	else if(data > root->data)
		root->rchild = AVL_remove(root->rchild, data);
	else
	{
		linktree p;

		if(root->lchild != NULL)
		{
			for(p=root->lchild; p->rchild!=NULL; p=p->rchild){;}
			root->data = p->data;
			root->lchild = AVL_remove(root->lchild, p->data);
		}
		else if(root->rchild != NULL)
		{
			for(p=root->rchild; p->lchild!=NULL; p=p->lchild){;}
			root->data = p->data;
			root->rchild = AVL_remove(root->rchild, p->data);
		}
		else
		{
			free(root);
			return NULL;
		}
	}

	if(height(root->lchild) - height(root->rchild) == 2)
	{
		if(height(root->lchild->rchild)-height(root->lchild->rchild) == 1)
			root = left_right_rotate(root);
		else
			root = right_rotate(root);
	}
	else if(height(root->rchild) - height(root->lchild) == 2)
	{
		if(height(root->rchild->lchild)-height(root->rchild->rchild) == 1)
			root = right_left_rotate(root);
		else
			root = left_rotate(root);
	}

	root->bf = MAX(height(root->lchild), height(root->rchild)) + 1;
	return root;
}
