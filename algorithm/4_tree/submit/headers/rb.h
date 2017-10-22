#ifndef _RB_H_
#define _RB_H_

inline linktree grandparent(linktree n)
{
	if(n == NULL || n->parent == NULL)
		return NULL;

	return n->parent->parent;
}

static linktree uncle(linktree n)
{
	if(grandparent(n) == NULL)
		return NULL;

	linktree gp = grandparent(n);
	return n->parent == gp->lchild ?
		gp->rchild : gp->lchild;
}

static bool sibling(linktree n, linktree *s)
{
	if(n == NULL)
	{
		*s = NULL;
		return false;
	}
	

	if(n->parent == NULL)
		*s = NULL;
	else
	{
		if(n == n->parent->lchild)
			*s = n->parent->rchild;
		else
			*s = n->parent->lchild;
	}
	return true;
}

void rotate_left(linktree *proot, linktree n);
void rotate_right(linktree *proot, linktree n);

void fixup(linktree *proot, linktree new);
void insert_case1(linktree *proot, linktree new);
void insert_case2(linktree *proot, linktree new);
void insert_case3(linktree *proot, linktree new);
linktree bst_insert(linktree root, linktree new);
void rb_insert(linktree *proot, linktree new);

void delete_case1(linktree *proot, linktree n);
void delete_case2(linktree *proot, linktree n);
void delete_case3(linktree *proot, linktree n);
void delete_case4(linktree *proot, linktree n);
void delete_case5(linktree *proot, linktree n);
void delete_case6(linktree *proot, linktree n);
void delete_one_child(linktree *proot, linktree n);
void rb_remove(linktree *proot, tn_datatype data);

#endif
