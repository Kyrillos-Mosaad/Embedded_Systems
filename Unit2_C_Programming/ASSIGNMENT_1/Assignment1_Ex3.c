#include "stdio.h"
int main()
{
	int num1=0;
	int num2=0;
	printf("##########Console-output###\r\n");
	printf("Enter two integers : ");
	fflush(stdout);
	scanf("%d",&num1);
	fflush(stdin);
	scanf("%d",&num2);
	fflush(stdin);
	printf("Sum = %d \r\n",num1+num2);
	printf("###########################\r\n");
	return 0;
}
