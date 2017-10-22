#include "head4tree.h"

linktree bst_insert(linktree root, tn_datatype data)
{
	if(root == NULL)
		return new_node(data, NULL, NULL);

	if(data < root->data)
		root->lchild = bst_insert(root->lchild, data);
	else if(data > root->data)
		root->rchild = bst_insert(root->rchild, data);
	else
	{
		printf("%d is already exist.\n", data);
		return root;
	}
	return root;
}

linktree bst_remove(linktree root, tn_datatype data)
{
	if(root == NULL)
		return NULL;

	if(data < root->data)
		root->lchild = bst_remove(root->lchild, data);
	else if(data > root->data)
		root->rchild = bst_remove(root->rchild, data);
	else
	{
		if(root->lchild != NULL)
		{
			linktree p;
			for(p=root->lchild; p->rchild!=NULL; p=p->rchild){;}
			root->data = p->data;
			root->lchild = bst_remove(root->lchild, p->data);
		}
		else if(root->rchild != NULL)
		{
			linktree p;
			for(p=root->rchild; p->lchild!=NULL; p=p->lchild){;}
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
