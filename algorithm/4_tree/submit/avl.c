#include "head4tree.h"
#include "drawtree.h"

linktree right_rotate(linktree root)
{
	linktree tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	
	root->height = MAX(height(root->lchild), height(root->rchild)) + 1;
	tmp->height = MAX(height(tmp->lchild), root->height) + 1;

	return tmp;
}

linktree left_rotate(linktree root)
{
	linktree tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	
	root->height = MAX(height(root->lchild), height(root->rchild)) + 1;
	tmp->height = MAX(root->height, height(tmp->rchild)) + 1;

	return tmp;
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

// 在一棵root中，插入节点new
linktree avl_insert(linktree root, linktree new)
{
	if(root == NULL)
		return new;

	// 1：按照BST的规则，插入新节点new
	if(new->data < root->data)
		root->lchild = avl_insert(root->lchild, new);
	else if(new->data > root->data)
		root->rchild = avl_insert(root->rchild, new);
	else
	{
		printf("%d is already exist.\n", new->data);
	}

	// 2：判断插入新节点new之后，左右子树高度差有没有超标

	// 2.1：左腿太长
	if(height(root->lchild) - height(root->rchild) == 2)
	{
		// A) 左左不平衡
		if(new->data < root->lchild->data)
			root = right_rotate(root);

		// B) 左右不平衡
		else if(new->data > root->lchild->data)
			root = left_right_rotate(root);
	}

	// 2.2 右腿太长
	else if(height(root->rchild) - height(root->lchild) == 2)
	{
		// A) 右右不平衡
		if(new->data > root->rchild->data)
			root = left_rotate(root);

		// B) 右左不平衡
		else if(new->data < root->rchild->data)
			root = right_left_rotate(root);
	}


	root->height = MAX(height(root->lchild), height(root->rchild)) + 1;
	return root;
}

int main(void)
{
	linktree root = NULL;

	int n;
	while(1)
	{
		scanf("%d", &n);

		if(n > 0)
		{
			linktree new = new_node(n);
			root = avl_insert(root, new);
		}
		else
			break;
	}
	draw(root);

	return 0;
}
