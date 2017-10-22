#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "stack_head.h"

/********************
   initialize stack
*********************/
void init_stack(stack *ptop)
{
	*ptop = NULL;
}

/*******************
   is empty or not
********************/
bool is_empty(stack s)
{
	return (s == NULL);
}

/***************************
   PUSH element into stack
****************************/
bool push(stack *ps, node x)
{
	stack new = (stack)malloc(sizeof(node));
	if(new == NULL)
		return false;

	*new = x;
	new->next = *ps;
	*ps = new;

	return true;
}

/*****************************
   POP element out of stack
******************************/
bool pop(stack *ps, node *loc)
{
	if(is_empty(*ps))
		return false;

	stack p = *ps;
	*ps = (*ps)->next;

	*loc = *p;
	free(p);

	return true;
}
