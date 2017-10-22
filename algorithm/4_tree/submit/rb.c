#include "head4tree.h"
#include "drawtree.h"
#include "rb.h"

void rotate_left(linktree *proot, linktree n)
{
	linktree gp = grandparent(n);
	linktree p = n->parent;


	p->rchild = n->lchild;
	if(n->lchild != NULL)
		n->lchild->parent = p;


	n->lchild = p;
	p->parent = n;


	if(*proot == p)
		*proot = n;


	n->parent = gp;
	if(gp != NULL)
	{
		if(p == gp->lchild)
			gp->lchild = n;
		else
			gp->rchild = n;
	}
}


void rotate_right(linktree *proot, linktree n)
{
	linktree gp = grandparent(n);
	linktree p = n->parent;

	p->lchild = n->rchild;
	if(n->rchild != NULL)
		n->rchild->parent = p;

	n->rchild = p;
	p->parent = n;

	if(*proot == p)
		*proot = n;

	n->parent = gp;

	if(gp != NULL)
	{
		if(p == gp->lchild)
			gp->lchild = n;
		else
			gp->rchild = n;
	}
}

void fixup(linktree *proot, linktree new)
{
	if(new->parent == NULL)
	{
		new->color = BLACK;
		*proot = new;
		return;
	}

	if(new->parent->color == BLACK)
		return;
	else
		insert_case1(proot, new);
}

void insert_case1(linktree *proot, linktree new)
{
	if(uncle(new) != NULL && uncle(new)->color == RED)
	{
		new->parent->color = BLACK;
		uncle(new)->color = BLACK;
		grandparent(new)->color = RED;

		fixup(proot, grandparent(new));
	}
	else
		insert_case2(proot, new);
}


void insert_case2(linktree *proot, linktree new)
{

	if(new == new->parent->rchild &&
			new->parent == grandparent(new)->lchild)
	{
		rotate_left(proot, new);
		new = new->lchild;
	}

	else if(new == new->parent->lchild &&
			new->parent == grandparent(new)->rchild)
	{
		rotate_right(proot, new);
		new = new->rchild;
	}

	insert_case3(proot, new);
}


void insert_case3(linktree *proot, linktree new)
{
	new->parent->color = BLACK;
	grandparent(new)->color = RED;

	if(new == new->parent->lchild &&
			new->parent == grandparent(new)->lchild)
	{
		rotate_right(proot, new->parent);
	}
	else
		rotate_left(proot, new->parent);
}

linktree bst_insert(linktree root, linktree new)
{
	if(root == NULL)
		return new;

	new->parent = root;
	if(new->data < root->data)
	{
		root->lchild = bst_insert(root->lchild, new);
	}

	else if(new->data > root->data)
	{
		root->rchild = bst_insert(root->rchild, new);
	}
	else
	{
		printf("%d exist.\n", new->data);
	}

	return root;
}

linktree rb_find(linktree root, tn_datatype data)
{
	if(root == NULL)
		return NULL;

	if(data < root->data)
		return rb_find(root->lchild, data);
	else if(data > root->data)
		return rb_find(root->rchild, data);

	return root;
}

void rb_insert(linktree *proot, linktree new)
{
	*proot = bst_insert(*proot, new);
	fixup(proot, new);
}


////////////////////////////////////////////////////////////

int Color(linktree n)
{
	if(n != NULL && n->color == RED)
		return RED;

	return BLACK;
}

void delete_case1(linktree *proot, linktree n)
{
	printf("%s\n", __FUNCTION__);

	if(n == NULL || n->parent != NULL)
		delete_case2(proot, n);
}

void delete_case2(linktree *proot, linktree n)
{
	printf("%s\n", __FUNCTION__);

	linktree s;
	sibling(n, &s);

	if(Color(s) == RED)
	{
		n->parent->color = RED;
		s->color = BLACK;

		if(n == n->parent->lchild)
			rotate_left(proot, n->parent);
		else
			rotate_right(proot, n->parent);
	}

	delete_case3(proot, n);
}

void delete_case3(linktree *proot, linktree n)
{
	if(n == NULL)
		return;

	printf("%s\n", __FUNCTION__);

	linktree s;
	sibling(n, &s);

	if(Color(n->parent) == BLACK &&
		Color(s) == BLACK &&
		Color(s->lchild) == BLACK &&
		Color(s->rchild) == BLACK)
	{
		s->color = RED;
		delete_case1(proot, n->parent);
	}
	else
		delete_case4(proot, n);
}

void delete_case4(linktree *proot, linktree n)
{
	if(n == NULL)
		return;

	printf("%s\n", __FUNCTION__);

	linktree s;
	sibling(n, &s);
	if(Color(n->parent) == RED && s == NULL)
	{
		n->parent->color = BLACK;
		return;
	}

	if(Color(n->parent) == RED &&
		Color(s) == BLACK &&
		Color(s->lchild) == BLACK &&
		Color(s->rchild) == BLACK)
	{
		s->color = RED;
		n->parent->color = BLACK;
	}
	else
		delete_case5(proot, n);
}

void delete_case5(linktree *proot, linktree n)
{
	if(n == NULL)
		return;

	printf("%s\n", __FUNCTION__);

	linktree s;
	sibling(n, &s);

	if(Color(s) == BLACK)
	{
		if(n == n->parent->lchild &&
			Color(s->lchild) == RED &&
			Color(s->rchild) == BLACK)
		{
			s->color = RED;
			s->lchild->color = BLACK;
			rotate_right(proot, s);
		}
		else if(n == n->parent->rchild &&
			Color(s->lchild) == BLACK &&
			Color(s->rchild) == RED)
		{
			s->color = RED;
			s->rchild->color = BLACK;
			rotate_left(proot, s);
		}
	}

	delete_case6(proot, n);
}

void delete_case6(linktree *proot, linktree n)
{
	if(n == NULL)
		return;

	printf("%s\n", __FUNCTION__);

	linktree s;
	sibling(n, &s);

	s->color = n->parent->color;
	n->parent->color = BLACK;

	if(n == n->parent->lchild)
	{
		s->rchild->color = BLACK;
		rotate_left(proot, n->parent);
	}
	else
	{
		s->lchild->color = BLACK;
		rotate_right(proot, n->parent);
	}
}

void replace_node(linktree n, linktree child)
{
	printf("%s\n", __FUNCTION__);

	if(n->parent != NULL)
	{
		if(n == n->parent->lchild)
			n->parent->lchild = child;
		else
			n->parent->rchild = child;

		n->parent = NULL;
	}
	if(child != NULL)
		child->parent = n->parent;
}

void delete_one_child(linktree *proot, linktree n)
{
	linktree child = n->lchild ? n->lchild : n->rchild;

	replace_node(n, child);

	if(Color(n) == BLACK)
	{
		if(Color(child) == RED)
			child->color = BLACK;
		else
			delete_case1(proot, child);
	}
	
	free(n);
}

void rb_remove(linktree *proot, tn_datatype data)
{
	linktree tmp = rb_find(*proot, data);
	if(tmp == NULL)
	{
		printf("%d is NOT exist.\n", data);
		return;
	}

	linktree n = tmp;
	if(tmp->lchild != NULL)
	{
		n = tmp->lchild;
		for(;n->rchild != NULL; n = n->rchild);
		tmp->data = n->data;
	}
	else if(tmp->rchild != NULL)
	{
		n = tmp->rchild;
		for(;n->lchild != NULL; n = n->lchild);
		tmp->data = n->data;
	}

	delete_one_child(proot, n); // n has ONE child at most
}

int main(void)
{
	linktree root = NULL;

	int i;
	srand(time(NULL));
	for(i=0; i<10; i++)
	{
		linktree new = new_node(rand() % 100);
		if(root == NULL)
		{
			new->color = BLACK;
			root = new;
			continue;
		}
		rb_insert(&root, new);
	}
	draw(root);

	int n;
	while(1)
	{
		scanf("%d", &n);

		if(n < 0)
			rb_remove(&root, -n);
		else if(n > 0)
		{
			linktree new = new_node(n);
			rb_insert(&root, new);
		}
		else
			break;

		draw(root);
	}

	system("rm *html");

	return 0;
}
