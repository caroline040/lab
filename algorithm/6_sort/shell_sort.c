// shell sorting

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE  10

void show(int num[])
{
	int i;
	printf("\t");

	for(i=1; i<SIZE; ++i)
	{
		printf("%4d", num[i]);
	}

	printf("\n");
	return;
}

void shell_insert(int num[], int dk)
{
	int i, j;

	for(i=dk+1; i<SIZE; ++i)
	{
		if(num[i-dk] > num[i])
		{
			num[0] = num[i];

			for(j=i-dk; j>0&&(num[0]<num[j]); j-=dk)
				num[j+dk] = num[j];

			num[j+dk] = num[0];
		}
	}
}

void shell_sort(int num[], int dlta[], int t)
{
	int k;
	for(k=0; k<t; ++k)
	{
		shell_insert(num, dlta[k]);
		show(num);
	}
}

int main(void)
{
	/**************************************************
	   original data, array[0] for temperary storage
	***************************************************/
	int array[SIZE] = {0, 49, 38, 65, 97, 76, 13, 27, 49, 55};
	printf("the original numbers are:\n");
	show(array);

	/*****************************************
	   dlta is the increment serials numbers
	   the last number must be 1.
	******************************************/
	int dlta[4] = {5, 3, 2, 1};
	printf("steps of shell sorting:\n");

	/* shell sorting */
	shell_sort(array, dlta, 4);
	show(array);

	return 0;
}
