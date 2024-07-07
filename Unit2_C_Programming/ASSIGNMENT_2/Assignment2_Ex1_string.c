#include "stdio.h"
int main()
{
	char string[50];
	char ch;
	printf("Enter a string :  ");
	fflush(stdout);
	gets(string);
	printf("\n");
	printf("Enter the character to find freqency : ");
	fflush(stdout);
	scanf("%c",&ch);
	printf("\n");
	int i;
	int sum=0;
	for(i=0;i<strlen(string);i++)
	{
		if(string[i]==ch)
		{
			sum++;
		}
	}
	printf("frequency of %d",sum);
	fflush(stdout);
	return 0;
}
