#include "stdio.h"
#include "string.h"
void reverse(char sent[],int len)
{
	static int i=0;
	char temp;
	if(i<(strlen(sent)/2))
	{temp=sent[i];
	sent[i++]=sent[len-1];
	sent[len-1]=temp;
	len--;
	reverse(sent,len);
	}
}
int main()
{
	char sent[20];
	printf("Enter a sentence : ");
	fflush(stdout);
	gets(sent);
	reverse(sent,strlen(sent));
	printf("%s",sent);
	fflush(stdout);
	return 0;
}
