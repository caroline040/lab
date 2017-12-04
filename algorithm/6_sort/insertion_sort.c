#include <time.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#include <pthread.h>
#include <semaphore.h>

#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

void show(int numbers[], int len)
{
	int i;
	for(i=0; i<len; ++i)
	{
		printf("%d\t", numbers[i]);
	}
	printf("\n");
}

void insertion_sort(int numbers[], int len)
{
	int tmp[len];


}

int main(int argc, char **argv)
{
	// generate some random numbers
	srand(time(NULL));

	int i, numbers[10];
	for(i=0; i<10; ++i)
	{
		numbers[i] = rand() % 1000;
	}
	printf("排序前的随机数：\n");
	show(numbers, 10);

	// insertion sort
	insertion_sort(numbers, 10, ASC);
	printf("插入排序后：\n");
	show(numbers, 10);

	return 0;
}
