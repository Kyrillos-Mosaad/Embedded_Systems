#include "stdio.h"
int main()
{
	float a=0;
	float b=0;
	float temp=0;
	printf("##########Console-output###\r\n");
	fflush(stdout);
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("\r\nEnter value of b: ");
	fflush(stdout);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %f \r\n",a);
	fflush(stdout);
	printf("After swapping, value of b = %f",b);
	fflush(stdout);
	printf("\r\n###########################\r\n");
	fflush(stdout);
	return 0;
}
