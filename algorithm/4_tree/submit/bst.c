#include "head4tree.h"
#include "drawtree.h"

// 在一棵二叉搜索树root中，插入一个新节点new
linktree bst_insert(linktree root, linktree new)
{
	if(new == NULL)
		return root;

	// 如果根为空，则new为新的根节点
	// 注意：这里的root可以是任意一个节点（因为任意节点都可以是根）
	if(root == NULL)
		return new;

	// 1：如果新节点比根节点要大，则插入到右子树中
	if(new->data > root->data)
	{
		root->rchild = bst_insert(root->rchild, new);
	}

	// 2：如果新节点比根节点要小，则插入到左子树中
	else if(new->data < root->data)
	{
		root->lchild = bst_insert(root->lchild, new);
	}

	// 3：相等的情况不处理
	else
	{
		printf("%d is already exist.\n", new->data);
	}

	return root;
}

linktree bst_find(linktree root, tn_datatype data)
{
	if(root == NULL)
		return NULL;

	if(data < root->data)
		return bst_find(root->lchild, data);
	else if(data > root->data)
		return bst_find(root->rchild, data);
	else
		return root;
}

// 在一棵二叉树root中，将节点n删除
linktree bst_remove(linktree root, tn_datatype n)
{
	// 1：如果树为空，则直接返回
	if(root == NULL)
		return NULL;

	// 2：如果要删除的节点比根节点要小，那么就去左子树中删除
	if(n < root->data)
		root->lchild = bst_remove(root->lchild, n);

	// 3：如果要删除的节点比根节点要大，那么就去右子树中删除
	else if(n > root->data)
		root->rchild = bst_remove(root->rchild, n);

	// 4：要删除的节点既不比根节点大又不比根节点不小，即：根节点root就是我们要删除的节点！
	// 再提醒一句：所谓的根节点，可以是任意一个节点
	else
	{
		linktree tmp;

		// 4.1：如果根节点有左孩子，那么将左子树中最大的节点x替代根节点，然后再将x删除
		if(root->lchild != NULL)
		{
			// A) 找到左子树中最大的节点x
			for(tmp=root->lchild; tmp->rchild!=NULL;
			    tmp=tmp->rchild);

			// B) 替代根节点
			root->data = tmp->data;

			// C) 将节点x删除
			root->lchild = bst_remove(root->lchild, tmp->data);
		}

		// 4.2：否则，如果根节点有右孩子，那么将右子树中最小的节点x替代根节点，然后再将x删除
		else if(root->rchild != NULL)
		{
			for(tmp=root->rchild; tmp->lchild!=NULL;
			    tmp=tmp->lchild);

			root->data = tmp->data;
			root->rchild = bst_remove(root->rchild, tmp->data);
		}

		// 4.3：否则，根节点就是叶子，那么直接删除
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
	linktree root;
	root = NULL;

	int n;
	while(1)
	{
		scanf("%d", &n);

		if(n > 0)
		{
			linktree new = new_node(n);
			root = bst_insert(root, new);
		}
		else if(n < 0)
		{
			//root = bst_remove(root, -n);
		}
		if(n == 0)
			break;
	}
	draw(root);

	return 0;
}
