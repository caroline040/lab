#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "head.h"

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
bool push(stack *ps, datatype x)
{
	stack new = (stack)malloc(sizeof(node));
	if(new == NULL)
		return false;

	new->data = x;

	new->next = *ps;
	*ps = new;

	return true;
}

/*****************************
   POP element out of stack
******************************/
bool pop(stack *ps, datatype *loc)
{
	if(is_empty(*ps))
		return false;

	stack p = *ps;
	*ps = (*ps)->next;

	*loc = p->data;
	free(p);

	return true;
}
