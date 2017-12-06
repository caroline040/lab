#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

typedef struct
{
	int *data;
	int len;
	int last;
}heap;

void show(int num[], int len)
{
	int i;
	for(i=0; i<len; ++i)
	{
		printf("%d\t", num[i]);
	}

	printf("\n");
	return;
}

heap *init_heap(int len)
{
	heap *maxheap = calloc(1, sizeof(heap));
	if(maxheap != NULL)
	{
		maxheap->data = calloc(len+1, sizeof(int));
		if(maxheap->data == NULL)
		{
			perror("分配最大堆内存失败！\n");
			free(maxheap);
			exit(0);
		}

		maxheap->len  = len;
		maxheap->last = 0;
	}
	else
	{
		printf("初始化最大堆失败.\n");
		exit(0);
	}

	return maxheap;
}

bool is_full(heap *maxheap)
{
	return maxheap->last >= maxheap->len;
}

bool maxheap_add(heap *maxheap, int len, int element)
{
	if(is_full(maxheap))
		return false;

	int pos = maxheap->last + 1;

	while(pos > 1 && element > maxheap->data[pos/2])
	{
		maxheap->data[pos] = maxheap->data[pos/2];
		pos /= 2;
	}

	maxheap->data[pos] = element;
	maxheap->last++;

	return true;
}

heap *create_heap(int num[], int len)
{
	// 初始化最大堆
	heap *maxheap = init_heap(len);

	// 将元素依次插入最大堆
	int i;
	for(i=0; i<len; ++i)
	{
		maxheap_add(maxheap, len, num[i]);
	}

#ifdef DEBUG
	printf("最大堆：\n");
	show(maxheap->data+1, maxheap->last);
#endif

	return maxheap;
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

// num  ：最大堆基地址
// index：当前要调整的元素的下标
// last ：最大堆最后一个元素的下标
void adjust(int num[], int index, int last)
{
	printf("AAAA: ");
	show(num+1, last);
	int tmp = num[index];

	int k;
	for(k=2*index; k<=last; k=2*k+1)
	{
		if(k+1 <= last && num[k] < num[k+1])
			k = k+1;

		if(tmp < num[k])
		{
			num[index] = num[k];
			index = k;
		}

		else 
			break;
	}

	num[index] = tmp;
	printf("BBBB: ");
	show(num+1, last);
}

// 最大堆序列：num[0、1、2、3、…… last]
void heap_sort(int num[], int last)
{
	if(last <= 1)
		return;

	int i;
	for(i=last; i>1; --i)
	{
		// 将最大元素放到末尾
		swap(&num[1], &num[i]);
	
		// 调整最大堆结构
		adjust(num, 1, i);
	}
}

int main(void)
{
	srand(time(NULL));

	printf("请输入随机数个数：");
	int n;
	scanf("%d", &n);

	// 1，产生随机节点
	int i, numbers[n];
	for(i=0; i<n; i++)
	{
		int exp = (int)pow(10, rand()%5+1);
		numbers[i] = rand()%exp;
	}
	printf("随机序列：\n");
	show(numbers, n);

	// 2，由随机节点构建最大堆
	heap *maxheap = create_heap(numbers, n);

	// 3，对最大堆进行排序（以升序为例）
	heap_sort(maxheap->data, maxheap->last);

	printf("\n堆排序后：\n");
	show(maxheap->data+1, maxheap->last);

	return 0;
}
