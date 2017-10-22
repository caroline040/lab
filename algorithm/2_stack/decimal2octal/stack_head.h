#ifndef _STACK_HEAD_H
#define _STACK_HEAD_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 64

typedef int datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}node, *stack;

void init_stack(stack *);
bool is_empty(stack);
bool push(stack *, node);
bool pop(stack *, node *);

#endif
