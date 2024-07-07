#include "stdio.h"
int main()
{
	float Matrix_A[2][2];
	float Matrix_B[2][2];
	/*------------------------Assignment------------------------*/
	printf("Enter the elements of 1st matrix \n");
	fflush(stdout);
	printf("a11 =  ");
	fflush(stdout);
	scanf("%f",&Matrix_A[0][0]);
	printf("a12 =  ");
	fflush(stdout);
	scanf("%f",&Matrix_A[0][1]);
	printf("a21 =  ");
	fflush(stdout);
	scanf("%f",&Matrix_A[1][0]);
	printf("a22 =  ");
	fflush(stdout);
	scanf("%f",&Matrix_A[1][1]);
	printf("Enter the elements of 2nd matrix \n");
	fflush(stdout);
	printf("b11 =  ");
	fflush(stdout);
	scanf("%f",&Matrix_B[0][0]);
	printf("b12 =  ");
	fflush(stdout);
	scanf("%f",&Matrix_B[0][1]);
	printf("b21 =  ");
	fflush(stdout);
	scanf("%f",&Matrix_B[1][0]);
	printf("b22 =  ");
	fflush(stdout);
	scanf("%f",&Matrix_B[1][1]);
	/*------------------------Operation-------------------------*/
	printf("Sum Of Matrix \n");
	fflush(stdout);
	printf("%f \t",Matrix_A[0][0]+Matrix_B[0][0]);
	fflush(stdout);
	printf("%f \n",Matrix_A[0][1]+Matrix_B[0][1]);
	fflush(stdout);
	printf("%f \t",Matrix_A[1][0]+Matrix_B[1][0]);
	fflush(stdout);
	printf("%f \n",Matrix_A[1][1]+Matrix_B[1][1]);
	fflush(stdout);


	return 0;
}
