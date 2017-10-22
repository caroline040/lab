/*
 * CreazyProgramming/DataStructure/Tree/head4tree.h
 *
 * Copyright (C) 2009 Vincent Lin: <260656483@qq.com>
 *
*/

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

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) ({ \
		typeof(a) _a = a; \
		typeof(b) _b = b; \
		(void)(&_a == &_b);\
		_a > _b? _a : _b; \
		})

typedef TREE_NODE_DATATYPE tn_datatype;

typedef struct _tree_node
{
	tn_datatype data;
	struct _tree_node *lchild;
	struct _tree_node *rchild;
#ifdef BALANCE_FACTOR
	int bf; // 0, 1, 2
#endif

#ifdef ACCESS_FLAG
	bool af; // for non-recursive travel by applying post-order
#endif
}treenode, *linktree;

void pre(linktree);
void cen(linktree);
void pos(linktree);
void lel(linktree);

static linktree new_node(tn_datatype data, linktree l, linktree r)
{
	linktree newnode = (linktree)malloc(sizeof(treenode));
	newnode->data = data;
	newnode->lchild = l;
	newnode->rchild = r;
#ifdef BALANCE_FACTOR
	newnode->bf = 0;
#endif
	return newnode;
}

// Binary Search Tree
linktree bst_insert(linktree, tn_datatype);
linktree bst_remove(linktree, tn_datatype);

// AVL Tree
linktree AVL_insert(linktree, tn_datatype);
linktree AVL_remove(linktree, tn_datatype);

/*
 * the following codes were downloaded from the Internet, the author is
 * xuediao : <xuediao@eyou.com>
 *
 * Applying the macro 'DO_TREE_MAP' to draw the map for any B-tree.
*/

#include <stddef.h>

static char *draw(void *node)
{
	char *buf = malloc(64);
#ifdef DEBUG
	snprintf(buf, 64, "%d, %d",
		((linktree)node)->data, ((linktree)node)->bf);
#else
	snprintf(buf, 64, "%d", ((linktree)node)->data);
#endif
	return buf;
}
typedef char *(*print_node)(void *);

#define DO_TREE_MAP(root, structure, lfield, rfield, printf_func) \
	do_tree_map(root, offsetof(structure, lfield), \
		offsetof(structure, rfield), printf_func)

void do_tree_map(void *, long, long, print_node);

#endif
