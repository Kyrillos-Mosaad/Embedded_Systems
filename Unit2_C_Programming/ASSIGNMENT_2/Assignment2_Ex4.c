#include "stdio.h"
int main()
{
	int array[100];
	int num;
	int i;
	int inserted_num;
	int idx;
	printf("Enter no of elements : ");
	fflush(stdout);
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("\n");
	printf("Enter the element to be inserted : ");
	fflush(stdout);
	printf("\n");
	scanf("%d",&inserted_num);
	printf("Enter the location : ");
	fflush(stdout);
	printf("\n");
	scanf("%d",&idx);
	idx--;
	for(i=num-1;i>=idx;i--)
	{
		array[i+1]=array[i];
	}
	array[idx]=inserted_num;
	for(i=0;i<num+1;i++)
	{
		printf("%d \t",array[i]);
	}
	return 0;
}
