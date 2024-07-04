#include "stdio.h"
#include "math.h"
float a=0;
float b=0;
int n=0;

int main()
{
	printf("##########Console-output###\r\n");
	fflush(stdout);
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("\r\nEnter value of b: ");
	fflush(stdout);
	scanf("%f",&b);
	/*---------------------------Swapping----------------------------------*/

	do{
		b/=10.0;
		n++;
	}while(floor(b)!=0);
	a=floor(a)+b;
	b=floor(a);
	a=(a-floor(a));
	for(int i=1;i<=n;i++)
		a*=10;
	/*---------------------------------------------------------------------*/
	printf("After swapping, value of a = %f \r\n",a);
	fflush(stdout);
	printf("After swapping, value of b = %f",b);
	fflush(stdout);
	printf("\r\n###########################\r\n");
	fflush(stdout);
	return 0;
}
