#include "stdio.h"
#include "string.h"
int main()
{
	char alphabets[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *ptr=alphabets;
	do{
		printf("%c\t",*ptr++);
	}while(*ptr!=0 );
	return 0;
}
