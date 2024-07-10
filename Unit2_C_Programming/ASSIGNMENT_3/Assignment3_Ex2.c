#include "stdio.h"
#include "math.h"
int fact(int num)
{
	if(num==0 || num==1)
		return 1;
	else
		return (num*fact(num-1));
}
int main()
{
	int num;
	do{
		printf("Enter a positive integer: ");
		fflush(stdout);
		scanf("%d",&num);
	}while(num<0);

	printf("Factorial of %d = %d",num,fact(num));
	fflush(stdout);
	return 0;
}
