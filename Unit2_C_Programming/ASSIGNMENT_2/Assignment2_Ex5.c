#include "stdio.h"
int main()
{
	int num;
	int array[10];
	int searched_num;
	int i;
	printf("Enter no of elements : ");
	fflush(stdout);
	scanf("%d",&num);
	printf("\n");
	fflush(stdout);
	for(i=0;i<num;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("\n");
	fflush(stdout);
	printf("Enter the elements to be searched : ");
	fflush(stdout);
	scanf("%d",&searched_num);
	printf("\n");
	fflush(stdout);
	for(i=0;i<num;i++)
	{
		if(array[i] == searched_num)
		{
			printf("number found at the location %d",i+1);
			fflush(stdout);
			break;
		}
	}
	return 0;
}
