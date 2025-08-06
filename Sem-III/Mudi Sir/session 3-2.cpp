#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int Display(int *[],int ,int );
int Multiply(int *[],int *[],int ,int ,int );
int main()
{
	int r1,c1,r2,c2,i,j;
	printf("Enter the dimensions of the First Matrix: ");
	scanf("%d %d",&r1,&c1);
	int *a[r1];
	printf("Enter the array elements for the First Matrix:\n");
	for (i=0;i<r1;i++) 
	{
		a[i] = (int *)malloc(c1* sizeof(int));
		for(j=0;j<c1;j++)
		{
			scanf("%d",a[i]+j);
		} 
	}
	printf("The First Matrix is-->\n");
	Display(a,r1,c1);
	printf("Enter the dimensions of the Second Matrix: ");
	scanf("%d %d",&r2,&c2);
	int *b[r2];
	printf("Enter the array elements for the Second Matrix:\n");
	for (i=0;i<r2;i++) 
	{
		b[i] = (int *)malloc(c2* sizeof(int));
		for(j=0;j<c2;j++)
		{
			scanf("%d",b[i]+j); 
		} 
	}
	printf("The Second Matrix is-->\n");
	Display(b,r2,c2);
	int *p[r1];
	
	if(c1==r2)
		Multiply(a,b,r1,c2,c1);
	else
		printf("Multiplication Not Possible");
	return 0;
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
int Multiply(int *a[],int *b[],int r1,int c2,int c1)
{
	int i,j,k,*p[r1];
	for(i=0;i<r1;i++)
	{
		p[i]=(int *)malloc(c2*sizeof(int));
		for(j=0;j<c2;j++)
		{
			*(p[i]+j)=0;
        	for(k=0;k<c1;k++)
        	{
            	*(p[i]+j)+=*(a[i]+k) * *(b[k]+j); 
    		}
    	}
	}
	printf("The Multiplied Matrix is-->\n");
	Display(p,r1,c2);
}
