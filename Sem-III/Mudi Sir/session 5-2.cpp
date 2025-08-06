#include<stdio.h>
#include<string.h>
struct student{
	char name[25];
	int roll,marks[3];
};
void avg(struct student [],int );
int main()
{
	int n,i,j;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	struct student a[n],c;
	for(i=0;i<n;i++)
	{
		printf("Enter the name of student %d: ",i+1);
		scanf("%s",&a[i].name);
		printf("Enter the roll: ");
		scanf("%d",&a[i].roll);
		printf("Enter the marks in 3 subjects:\n");
		for(j=0;j<3;j++)
			scanf("%d",&a[i].marks[j]);
	}
	avg(a,n);
	return 0;
}
void avg(struct student a[],int n)
{
	int i,j;
	float s;
	for(i=0;i<n;i++)
	{
		s=0;
		for(j=0;j<3;j++)
		{
			s+=a[i].marks[j];
		}
		printf("\nThe avergae marks of %s is %0.2f",a[i].name,(s/3));
	}
}
