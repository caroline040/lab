#include <stdio.h>

int main(void)
{
	int size;
	printf("pls input the size of the diamond(odd number): ");

	int ret1, ret2;
	while((ret1=scanf("%d", &size)) != 1 || // input don't match the format
			size % 2 == 0 || size < 1 || // invalid input
			(ret2=getchar()) != '\n') // don't match the format
	{
		if(ret1 != 1 || ret2 != '\n')
			while(getchar() != '\n');

		printf("input invalid!\n");
		printf("pls input the size of the diamond(odd number): ");
	}

	int i=1, space, star;
	while(i<=((size/2)+1)) // upper half
	{
		for(space=0; space<((size/2)-i+1); space++)
		{
			printf(" ");
		}
		for(star=0; star<((2*i)-1); star++)
		{
			printf("*");
		}
		printf("\n");
		i++;
	}

	int j = 1;
	i -= 2;
	while(j<((size/2))+1) // lower half
	{
		for(space=0; space<j; space++)
		{
			printf(" ");
		}
		for(star=0; star<((2*(i--))-1); star++)
		{
			printf("*");
		}

		j++;
		printf("\n");
	}
	return 0;
}
