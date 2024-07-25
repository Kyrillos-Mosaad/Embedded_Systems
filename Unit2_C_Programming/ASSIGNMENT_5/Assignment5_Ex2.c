#include "stdio.h"
struct distance {
	int foot;
	float inch;
};
int main()
{
	struct distance dist1 ,dist2,sum;
	printf("Enter information for 1st distance: \n");
	fflush(stdout);fflush(stdin);
	printf("Enter foot: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&dist1.foot);
	printf("Enter inch: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&dist1.inch);
	printf("Enter information for 1st distance: \n");
	fflush(stdout);fflush(stdin);
	printf("Enter foot: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&dist2.foot);
	printf("Enter inch: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&dist2.inch);
	sum.foot=dist1.foot+dist2.foot;
	sum.inch=dist1.inch+dist2.inch;
	if(sum.inch>=12)
	{
		sum.inch=sum.inch-12;
		sum.foot++;
	}
	printf("sum of distances= %d'-%.1f\" ",sum.foot,sum.inch);
	fflush(stdout);fflush(stdin);
	return 0;
}
