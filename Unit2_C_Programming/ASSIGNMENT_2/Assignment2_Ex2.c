#include "stdio.h"
int main()
{
	int num =0;
	float data[10];
	float sum =0;
	printf("Enter the numbers of data ");
	fflush(stdout);
	scanf("%d",&num);
	int i;
	for(i=1;i<=num;i++)
	{
		printf("%d. Enter number: ",i);
		fflush(stdout);
		scanf("%f",&data[i]);
		sum+=data[i];
	}

	printf("Average = %.2f",sum/num);
	fflush(stdout);
	return 0;
}
