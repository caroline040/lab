// bubble sorting

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 7

void show(int num[])
{
	int i;
	printf("\t");
	for(i=SIZE; i>0; --i){
	    printf("%4d", num[SIZE-i]);
	}
	printf("\n");
	return;
}

void bubble_sort(int num[])
{
	int i, j;
	for(i=SIZE; i>0; --i)
	{
	    int flag = 0;

		for(j=0; j<i-1; j++)
		{
			int tmp;
	        	if(num[j] > num[j+1])
			{
	               		tmp = num[j];
	                	num[j] = num[j+1];
	                	num[j+1] = tmp;
	                	flag = 1;
	        	}
	         }

	    show(num);
	    if(flag == 0) //nerver been changed
	        break;
	}
	return;
}

int main(void)
{
	/* original data */
	int array[SIZE] = {49, 38, 65, 97, 76, 13, 27};
	printf("the original numbers are:\n");
	show(array);

	/* bubble sorting */
	printf("steps of bubble sorting:\n");
	bubble_sort(array);

	return 0;
}
