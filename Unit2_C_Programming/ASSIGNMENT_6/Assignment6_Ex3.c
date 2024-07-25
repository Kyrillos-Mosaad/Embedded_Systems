#include "stdio.h"
int main()
{
	char st[20];
	printf("Input a string : ");
	fflush(stdout);
	gets(st);
	char *ptr=st;
	ptr+=strlen(st)-1;
	int i;
	printf("Reverse of the string is : ");
	for(i=strlen(st)-1;i>=0;i--)
	printf("%c",*ptr--);
	return 0;
}
