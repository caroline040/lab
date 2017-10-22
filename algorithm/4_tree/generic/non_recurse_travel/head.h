#ifndef  __HEAD__
#define  __HEAD__

#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

/**************
   tree node
***************/
typedef struct tree_node
{
	char ch;
	struct tree_node *lchild;
	struct tree_node *rchild;
	bool pushed;
}treenode, *root;

typedef root datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}node, *stack;

void init_stack(stack *);
bool is_empty(stack);
bool push(stack *, datatype);
bool pop(stack *, datatype *);

/* queue */
typedef struct queue_node
{
	struct node *front;
	struct node *rear;
}queue_node, *linkqueue;

/* thread function */
bool isempty(linkqueue);
bool out_queue(linkqueue, root *);
bool en_queue(linkqueue, root);
void queue_init(linkqueue *);

/* travel means */
void travel_pre(root);
void travel_center(root);
void travel_post(root);
void travel_level(root);

void travel(const char *, void (*)(root), root);

#endif
#if 1
#define  _MY_HEAD__

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

/* travel means */
void travel_pre1(root);
void travel_pre2(root);
void travel_center(root);
void travel_post(root);
void travel_level(root);

void travel(const char *, void (*)(root), root);

#endif
