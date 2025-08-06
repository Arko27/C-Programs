#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int Transpose(int *m[],int r,int c)
{
	int i,j;
	printf("The Transposed Matrix is-->\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",*(m[j]+i));
		}
		printf("\n");
	}
}
int main()
{
	int r,c,i,j;
	printf("Enter the dimensions of the matrix: ");
	scanf("%d %d",&r,&c);
	int *a[r];
	printf("Enter the array elements for the Matrix:\n");
	for (i=0;i<r;i++) 
	{
		a[i] = (int *)malloc(c* sizeof(int));
		for(j=0;j<c;j++)
		{
			scanf("%d",a[i]+j);
		} 
	}
	printf("The Matrix is-->\n");
	for (i=0;i<r;i++) 
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",*(a[i]+j));
		}
		printf("\n");
	}
	if(r==c)
		Transpose(a,r,c);
	else
	{
		Transpose(a,c,r);
	}
}
