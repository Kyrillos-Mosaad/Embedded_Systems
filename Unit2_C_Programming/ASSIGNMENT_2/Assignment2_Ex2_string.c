#include "stdio.h"
int main()
{
	char string[50];
	printf("Enter a string : ");
	fflush(stdout);
	gets(string);
	printf("\n");
	fflush(stdout);
	int i=0;
	while(string[i]!=0)
	{
		i++;
	}
	printf("Length of string : %d",i);
	fflush(stdout);
	return 0;
}
