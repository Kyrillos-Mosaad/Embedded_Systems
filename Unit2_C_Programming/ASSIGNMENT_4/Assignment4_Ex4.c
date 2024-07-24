#include "stdio.h"
int Pow(int base,int power)
{
	if(power!=0)
		return (base*Pow(base,power-1));
	else
		return 1;
}
int main()
{
	int base,power;
	printf("Enter base number: ");
	fflush(stdout);
	scanf("%d",&base);
	printf("Enter power number(positive integer): ");
	fflush(stdout);
	scanf("%d",&power);
	int res = Pow(base,power);
	printf("%d^%d = %d",base,power,res);
	fflush(stdout);
	return 0;
}
