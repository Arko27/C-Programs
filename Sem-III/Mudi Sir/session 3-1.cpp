#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int Add(int *[],int*[],int ,int );
int Display(int *[],int ,int );
int main()
{
	int r,c,i,j;
	printf("Enter the common dimensions of the two matrices: ");
	scanf("%d %d",&r,&c);
	int *a[r],*b[r],*s[r];
	printf("Enter the array elements for the First Matrix:\n");
	for (i=0;i<r;i++) 
	{
		a[i] = (int *)malloc(c* sizeof(int));
		for(j=0;j<c;j++)
		{
			scanf("%d",a[i]+j);
		} 
	}
	printf("The First Matrix is-->\n");
	Display(a,r,c);
	printf("Enter the array elements for the Second Matrix:\n");
	for (i=0;i<r;i++) 
	{
		b[i] = (int *)malloc(c* sizeof(int));
		for(j=0;j<c;j++)
		{
			scanf("%d",b[i]+j); 
		} 
	}
	printf("The Second Matrix is-->\n");
	Display(b,r,c);
	Add(a,b,r,c);
}
int Display(int *m[],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",*(m[i]+j));
		}
		printf("\n");
	}
}
int Add(int *a[],int *b[],int r,int c) 
{
	int *s[r],i,j;  
	for(i=0;i<r;i++) 
	{ 
		s[i]=(int *)malloc(c* sizeof(int));
		for(j=0;j<c;j++)
		{  
			*(s[i]+j) = *(a[i]+j) + *(b[i]+j); 
		}
	}
	printf("The Added Matrix is-->\n");
	Display(s,r,c);
}
