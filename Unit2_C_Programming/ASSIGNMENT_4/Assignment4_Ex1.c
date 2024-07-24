#include "stdio.h"
void Prime_Numbers(int num1,int num2)
{
	int i,sum;
	printf("Prime numbers between %d and %d are: ",num1,num2);
	fflush(stdout);
	for(num1;num1<=num2;num1++)
	{
		sum=0;
		for(i=2;i<=10;i++)
		{
			if(num1%i==0)
			sum++;
		}
		if(num1<10 && sum==1)
		{
			printf("%d \t",num1);
			fflush(stdout);
		}
		if(num1>10 && sum==0)
		{
			printf("%d \t",num1);
			fflush(stdout);
		}

	}
}
int main()
{
	int num1,num2;
	printf("Enter two numbers(intervals) :");
	fflush(stdout);
	scanf("%d",&num1);
	scanf("%d",&num2);
	Prime_Numbers(num1,num2);
	return 0;
}
