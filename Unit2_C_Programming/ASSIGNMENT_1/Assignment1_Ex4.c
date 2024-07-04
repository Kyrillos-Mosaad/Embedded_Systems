#include "stdio.h"
int main ()
{
	float num1=0;
	float num2=0;
	printf("##########Console-output###\r\n");
	printf("###########################\r\n");
	fflush(stdout);
	printf("Enter two numbers : ");
	fflush(stdout);
	scanf("%f",&num1);
	scanf("%f",&num2);
	printf("Product =%f",num1*num2);
	fflush(stdout);
	return 0;
}
