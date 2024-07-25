#include "stdio.h"
struct complex_num {
	float real;
	float imag;
};
int main()
{
	struct complex_num N1,N2,sum;
	printf("For 1st Number \n");
	fflush(stdout);
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f",&N1.real);
	scanf("%f",&N1.imag);
	printf("For 2nd Number \n");
	fflush(stdout);
	printf("Enter real and imaginary respectively: ");
	fflush(stdout);
	scanf("%f",&N2.real);
	scanf("%f",&N2.imag);
	sum.real=N1.real+N2.real;
	sum.imag=N1.imag+N2.imag;
	printf("Sum=%.1f+%.1fi",sum.real,sum.imag);
	fflush(stdout);
	return 0;
}
