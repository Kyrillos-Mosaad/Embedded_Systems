#include "stdio.h"
int main()
{
	char string[50];
	int i;
	printf("Enter the string : ");
	fflush(stdout);
	gets(string);
	printf("\n");
	fflush(stdout);
	printf("Reverse string is : ");
	fflush(stdout);
	for(i=strlen(string)-1;i>=0;i--)
	{
		printf("%c",string[i]);
		fflush(stdout);
	}
	return 0;
}
