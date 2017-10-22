#include "head4sort.h"

void binary_insertion_sort(int num[], int size)
{
	int i, j;
	int tmp, low, high, m;

	for(i=1; i<size; ++i)
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
	}
}

int partition(int num[], int low, int high)
{
        int pivotloc = num[low];

        while(low < high)
	{
		while(low<high && num[high]>=pivotloc)
			--high;
		num[low] = num[high];
        
		while(low<high && num[low]<=pivotloc)
			++low;
		num[high] = num[low];
        }

        num[low] = pivotloc;

        return low; //return the pivot's location
}

void quick_sort(int num[], int low, int high)
{
        int pivotloc;
        if(low < high)
	{
		pivotloc = partition(num, low, high);

		quick_sort(num, low, pivotloc-1);
		quick_sort(num, pivotloc+1, high);
        }
        return;
}

// bubble sorting
void bubble_sort(int num[], int size)
{
	int i, j;
	for(i=size; i>0; --i)
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

		if(flag == 0) //nerver been changed
	        	break;
	}
	return;
}


// insertion sort
void insertion_sort(int num[], int size)
{
	int i, j;
	int tmp;

	for(i=1; i<size; i++)
	{
		if(num[i-1] < num[i])
			continue;

		tmp = num[i];
		for(j=i-1; tmp<num[j] && j>= 0; j--)
			num[j+1] = num[j];

		num[j+1] = tmp;
	}
}


// shell sorting
void shell_insert(int num[], int size, int dk)
{
	int i, j;

	for(i=dk+1; i<size; ++i)
	{
		if(num[i] < num[i-dk])
		{
			num[0] = num[i];
			for(j=i-dk; j>0&&(num[0]<num[j]); j-=dk)
				num[j+dk] = num[j];

			num[j+dk] = num[0];
		}
	}
}

void shell_sort(int num[], int size, int dlta[], int t)
{
	int k;
	for(k=0; k<t; ++k)
		shell_insert(num, size, dlta[k]);
}
