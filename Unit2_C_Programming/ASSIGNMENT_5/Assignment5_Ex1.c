#include "stdio.h"
struct student {
	char name[30];
	int roll;
	float mark;
};
int main()
{
	struct student std1;
	printf("Enter information of students: \n");
	fflush(stdout);
	printf("Enter name: ");
	fflush(stdout);
	gets(std1.name);
	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d",&std1.roll);
	printf("Enter marks: ");
	fflush(stdout);
	scanf("%f",&std1.mark);
	printf("name: %s \n",std1.name);
	fflush(stdout);
	printf("name: %d \n",std1.roll);
	fflush(stdout);
	printf("name: %.2f \n",std1.mark);
	fflush(stdout);
	return 0;
}
