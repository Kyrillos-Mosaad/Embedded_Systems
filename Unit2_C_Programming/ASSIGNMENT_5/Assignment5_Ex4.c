#include "stdio.h"
struct data {
	int mark;
	char name[20];
};
int main()
{
	struct data student[10];
	printf("Enter information of students \n\n");
	fflush(stdout);
	int i;
	for(i=0;i<10;i++)
	{
		printf("For roll number %d \n",i+1);
		fflush(stdout);
		printf("Enter name: ");
		fflush(stdout);
		scanf("%s",&student[i].name);
		printf("Enter mark: ");
		fflush(stdout);
		scanf("%d",&student[i].mark);
	}
	printf("Displaying information of students: \n\n");
	fflush(stdout);
	for(i=0;i<10;i++)
	{
		printf("Information For roll number %d: \n",i+1);
		fflush(stdout);
		printf("Name: %s \n",student[i].name);
		fflush(stdout);
		printf("Mark: %d \n",student[i].mark);
		fflush(stdout);
	}
	return 0;
}
