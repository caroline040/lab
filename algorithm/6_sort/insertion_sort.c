// insertion sort
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

void insertion_sort(int num[])
{
	int i, j;
	int tmp;

	for(i=1; i<SIZE; i++)
	{
		if(num[i-1] < num[i])
		{
			show(num);
			continue;
		}
		else
		{
			tmp = num[i];
			for(j=i-1; tmp<num[j] && j>= 0; j--)
				num[j+1] = num[j];

			num[j+1] = tmp;
		}
		show(num);
	}//for
}

int main(void)
{
	/* original data */
	int array[SIZE] = {49, 38, 65, 97, 76, 13, 27};
	printf("the original numbers are:\n");
	show(array);

	/* insertion sorting */
	printf("steps of insertion sorting:\n");
	insertion_sort(array);

	return 0;
}
