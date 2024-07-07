#include "stdio.h"
int main()
{
	int i,N;
	int j,M;
	int array[100][100];
	int Matrix[100][100];
	printf("Enter the number of rows and columns of matrix: ");
	fflush(stdout);
	scanf("%d",&N);
	scanf("%d",&M);
	printf("Enter elements of matrix \n");
	fflush(stdout);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			printf("Enter elements a%d%d: ",i,j);
			fflush(stdout);
			scanf("%d",& array[i][j]);
			Matrix[i][j]=array[i][j];
		}
	}
	printf("Entered Matrix \n");
	fflush(stdout);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
		{
			printf("%d \t",array[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			array[i][j]=Matrix[j][i];
		}
	}
	printf("Transpose Matrix \n");
	fflush(stdout);
	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			printf("%d \t",array[i][j]);
			fflush(stdout);
		}
		printf("\n");
	}
	return 0;
}
