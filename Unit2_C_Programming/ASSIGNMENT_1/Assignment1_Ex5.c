#include "stdio.h"
int main()
{
	char ch;
	printf("##########Console-output###\r\n");
	fflush(stdout);
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&ch);
	printf("ASCII value of G = %d",ch);
	fflush(stdout);
	printf("\r\n###########################\r\n");
	fflush(stdout);
	return 0;
}
