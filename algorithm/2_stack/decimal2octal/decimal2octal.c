// :decimal2octal.c
//--converse a decimal number to an octal number applying linked-list stack

#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_head.h"

int main(int argc, char **argv)
{
	stack top;
	init_stack(&top);

	int val, abs_val;

	printf("Dec: ");
	if(!scanf("%d", &val))
	{
		printf("we need a integer, sorry.\n");
		return -1;
	}
	abs_val = val<0 ? val*(-1) : val; 

	/*************************************************
	   applying do...while to ensure 0 can be pushed
	   into the stack when N==0
	**************************************************/
	do{
		node new_node;
		new_node.data = abs_val%8;

		push(&top, new_node);
		abs_val /= 8;

	}while(abs_val != 0);

	printf("Oct: %s", val<0 ? "-0": "0");

	node x;
	while(!is_empty(top))
	{
		pop(&top, &x);
		printf("%d", x.data);
	}
	printf("\n");

	return 0;
}
