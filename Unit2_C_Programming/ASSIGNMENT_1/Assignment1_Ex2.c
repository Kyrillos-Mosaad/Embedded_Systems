#include "stdio.h"
int main()
{
	int num = 0;
	printf("##########Console-output###\r\n");
	printf("Enter a integer: ");
	fflush(stdout);
	scanf("%d",& num);
	printf("\r\n");
	printf("you entered %d \r\n",num);
	return 0;
}
