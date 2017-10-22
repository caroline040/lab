#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAXSIZE 10

typedef int datatype;

typedef struct 
{
	datatype data[MAXSIZE];
	int top;
}seqstack;

void init_stack(seqstack **ps)
{
	*ps = (seqstack *)malloc(sizeof(seqstack));
	
	(*ps)->top = -1;
}

bool is_empty(seqstack *s)
{
	return s->top == -1;
}

bool is_full(seqstack *s)
{
	return s->top >= MAXSIZE-1;
}

bool push(seqstack *s, datatype n)
{
	if(is_full(s))
		return false;

	s->data[++s->top] = n;
	return true;
}

bool pop(seqstack *s, datatype *loc)
{
	if(is_empty(s))
		return false;

	*loc = s->data[s->top--];
	return true;
}

int main(void)
{
	seqstack *s;
	init_stack(&s);

	datatype n;
	int ret;
	while(1){
		ret = scanf("%d", &n);

		if(ret != 1)
			break;
		else{
			if(!push(s, n)){
				printf("push falied.\n");
				break;
			}
		}
	}

	while(!is_empty(s)){
		pop(s, &n);
		printf("%d\t", n);
	}
	printf("\n");

	return 0;
}
