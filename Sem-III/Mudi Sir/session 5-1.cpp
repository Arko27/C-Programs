#include<stdio.h>
#include<malloc.h>
struct dob{
	int day;
	char month[15];
	int yr;
};
struct student{
	char name[25];
	int roll;
	struct dob dt;
	int marks;
};
void avg(struct student *,int );
int main()
{
	int i,n;
	struct student *st;
	printf("Enter the number of students: ");
	scanf("%d",&n);
	st=(struct student*)malloc(n*sizeof(struct student));
	for(i=0;i<n;i++)
	{
		printf("Enter name %d: ",(i+1));
		scanf("%s",&(st[i].name));
		printf("Enter the roll: ");
		scanf("%d",&(st[i].roll));
		printf("Enter the date of birth: ");
		scanf("%d %s %d",&(st[i].dt.day),&(st[i].dt.month),&(st[i].dt.yr));
		printf("Enter the marks: ");
		scanf("%d",&(st[i].marks));
	}
	avg(st,n);
	return 0;
}
void avg(struct student *st,int n)
{
	int i;
	float s=0.0;
	for(i=0;i<n;i++)
	{
		s+=st[i].marks;
	}
	for(i=0;i<n;i++)
	{
		printf("\n\nInformation about Student %d:\n",(i+1));
		printf("Name: %s",st[i].name);
		printf("\nRoll: %d",st[i].roll);
		printf("\nDate of Birth: %d %s %d",st[i].dt.day,st[i].dt.month,st[i].dt.yr);
		printf("\nMarks: %d",st[i].marks);
	}
	printf("\n\nThe Average Marks is %0.2f",(s/n));
}
