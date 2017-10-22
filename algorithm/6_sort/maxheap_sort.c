#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 1024 
#define SIZE 7

typedef struct
{
	int heap[MAX_SIZE];
	int size;
}maxheap;

void init_heap(maxheap *pheap)
{
	pheap->size = 0;
}

bool is_full(maxheap *p)
{
	return (p->size == MAX_SIZE);
}


bool is_empty(maxheap *p)
{
	return (p->size == 0);
}

void add_max(maxheap *p, int x)
{
	if(is_full(p))
	{
		fprintf(stderr, "overflow!\n");
		return;
	}

	int i = ++(p->size);

	/****************************************
	   find an appropriate position for x:
	   seaching from the last leaf-node up
	   stream trend to the root
	*****************************************/
	while((i != 1) && (x > p->heap[i/2]))
	{
		p->heap[i] = p->heap[i/2];
		i /= 2;
	}

	p->heap[i] = x;
}

void del_max(maxheap *p, int *loc)
{
	if(is_empty(p))
	{
		printf("underflow!\n");
		return;
	}

	*loc = p->heap[1]; // store the max value

	/******************************
		reconstruct heap
	*******************************/
	int tmp = p->heap[p->size--];

	int i = 1, ci = 2;;

	while(ci <= p->size)
	{
		/**************************************
		   ci points to the larger child of i
		***************************************/
		if((ci < p->size) &&
			(p->heap[ci] < p->heap[ci+1]))
			ci++;

		if(tmp >= p->heap[ci])
			break;

		/****************************************
		   find an appropriate position for tmp:
		   seaching from the root down stream
		   trend to the last leaf-node.
		*****************************************/
		p->heap[i] = p->heap[ci];
		i = ci;
		ci *= 2;
	}
	
	p->heap[i] = tmp;
}

void show(maxheap *p)
{
	if(is_empty(p))
		return;

	int num = 1;
	while(num <= p->size)
		printf("%d ", p->heap[num++]);

	printf("\n");
}

void ascending_order(int a[], int size)
{
	maxheap heap;
	init_heap(&heap);

	int i;
	for(i=0; i<size; i++)
		add_max(&heap, a[i]);

	/*****************************
		ascending order
	******************************/
	for(i=0; i<size; i++)
		del_max(&heap, &a[i]);
}

void descending_order(int a[], int size)
{
	maxheap heap;
	init_heap(&heap);

	int i;
	for(i=0; i<size; i++)
		add_max(&heap, a[i]);

	/*****************************
		descending order
	******************************/
	for(i=size; i>0; i--)
		del_max(&heap, &a[i-1]);

}

void show_data(int a[])
{
	int i;
	for(i=0; i<SIZE; i++)
		printf("%d ", a[i]);

	printf("\n");
}

int main(void)
{
	int a[SIZE] = {7, 1, 3, 2, 4, 6, 5};
	int b[SIZE] = {7, 1, 3, 2, 4, 6, 5};

	ascending_order(a, SIZE);
	show_data(a);

	descending_order(b, SIZE);
	show_data(b);

	return 0;
}
