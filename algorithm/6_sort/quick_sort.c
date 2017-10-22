// quick sorting

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

int partition(int num[], int low, int high)
{
        int pivotloc = num[low];

        while(low < high)
	{
        /* move the data which is SMALLER than the PIVOT forward */
            while(low<high && num[high]>=pivotloc)
                --high;
            num[low] = num[high];
        
            /* move the data which is LARGER than the PIVOT backward */
            while(low<high && num[low]<=pivotloc)
                ++low;
            num[high] = num[low];
        }
        num[low] = pivotloc;
        show(num);

        return low; //return the pivot's location
}

void quick_sort(int num[], int low, int high)
{
        int pivotloc;
        if(low < high)
	{
        	/*********
        	 sampling
        	**********/
            pivotloc = partition(num, low, high);
            /* recurs sorting sub-table */
            quick_sort(num, low, pivotloc-1);
            quick_sort(num, pivotloc+1, high);
        }
        return;
}

int main(void)
{
        /* original data */
        int array[SIZE] = {49, 38, 65, 97, 76, 13, 27};
        printf("the original numbers are:\n");
        show(array);

        /* quit sorting */
        int low=0, high=SIZE-1;
        printf("steps of quick sorting:\n");
        quick_sort(array, low, high);

        return 0;
}
