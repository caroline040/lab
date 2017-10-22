#ifndef _HEAD4TREE_H_
#define _HEAD4TREE_H_

/*
 * Any application applying this linked-tree data structure should
 * define the macro "TREE_NODE_DATATYPE" before include this head
 * file, otherwise, the macro will be defined to 'int' as follow.
 *
*/

#ifndef TREE_NODE_DATATYPE
#define TREE_NODE_DATATYPE int
#endif

#include "commonheader.h"

#define MAX(a, b) ({ \
		typeof(a) _a = a; \
		typeof(b) _b = b; \
		(void)(&_a == &_b);\
		_a > _b? _a : _b; \
		})

typedef TREE_NODE_DATATYPE tn_datatype;

#ifdef RB
#define RED 0
#define BLACK 1
#endif

typedef struct _tree_node
{
	tn_datatype data;
	struct _tree_node *lchild;
	struct _tree_node *rchild;

#ifdef AVL
	int height;
#endif

#ifdef RB
	struct _tree_node *parent;
	struct _tree_node *uncle;
	int color;
#endif
}treenode, *linktree;

static int height(linktree root)
{
	if(root == NULL)
		return 0;

	#ifdef AVL
	return root->height;
	#else
	return MAX(height(root->lchild), height(root->rchild)) + 1;
	#endif
}

void pre_travel(linktree, void (*handler)(linktree));
void mid_travel(linktree, void (*handler)(linktree));
void post_travel(linktree, void (*handler)(linktree));
void level_travel(linktree, void (*handler)(linktree));

// Binary Search Tree
linktree bst_insert(linktree root, linktree new);
linktree bst_remove(linktree root, tn_datatype data);
linktree bst_find(linktree root, tn_datatype data);

// AVL Tree
linktree avl_insert(linktree root, linktree new);
linktree avl_remove(linktree root, tn_datatype data);

linktree left_rotate(linktree root);
linktree right_rotate(linktree root);
linktree left_right_rotate(linktree root);
linktree right_left_rotate(linktree root);

static linktree new_node(tn_datatype data)
{
	linktree new = malloc(sizeof(treenode));
	if(new != NULL)
	{
		new->data = data;
		new->lchild = NULL;
		new->rchild = NULL;

		#ifdef AVL
		new->height = 1;
		#endif

		#ifdef RB
		new->parent = NULL;
		new->uncle = NULL;
		new->color = RED;
		#endif
	}
	return new;
}

#endif
