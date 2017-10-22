// Binary insertion sort

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 7

void show(int num[])
{
        int i;
        printf("\t");
        for(i=SIZE; i>0; --i)
		printf("%4d", num[SIZE-i]);

        printf("\n");
        return;
}

void binary_insertion_sort(int num[])
{
        int i, j;
        int tmp, low, high, m;

        for(i=1; i<SIZE; ++i)
        {
                tmp = num[i];
                low = 0; high = i-1;

                /* find the position for inserting */
                while(low <= high)
                {
                	m = (low + high)/2;
                	if(tmp < num[m])
                		high = m-1;
                	else
                		low = m+1;
                }

                /* moves the records */
                for(j=i-1; j >= high+1; --j)
                	num[j+1] = num[j];

                num[high+1] = tmp;
                show(num);
        }
}

int main(void)
{
        /* original data */
        int array[SIZE] = {49, 38, 65, 97, 76, 13, 27};
        printf("the original numbers are:\n");
        show(array);

        /* binary insertion sorting */
        printf("steps of insertion sorting:\n");
        binary_insertion_sort(array);

        return 0;
}
