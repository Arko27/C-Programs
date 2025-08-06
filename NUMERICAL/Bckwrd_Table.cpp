#include<stdio.h>
int main()
{
	int n,i,j;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	float x[n],y[n][n],p,q,sum=0,h,u;
	for(i=0;i<n;i++)
	{
		printf("Enter x[%d]: ",i);
		scanf("%f",&x[i]);
		printf("Enter y[%d]: ",i);
		scanf("%f",&y[i][0]);
	}
	
	for (j=1;j<n;j++)
	{
		for (i=n-1;i>j-1;i--)
		{
			y[i][j] = y[i][j-1] - y[i-1][j-1];
		}
	}
	
	printf("The Backward Difference table is:\n\n");
	for(i=0;i<n;i++)
	{
		printf("%.2f",x[i]);
		for(j=0;j<=i;j++)
		{
			printf("\t%.2f",y[i][j]);
		}
		printf("\n");
	}
	
	printf("\nEnter the value of p: ");
	scanf("%f",&p);
	float c=p;
	
	h = x[1]-x[0];
	u = (p - x[n-1])/h;
	sum = y[n-1][0];
	p=1;
	q=1;
	
	for(j=1;j<n;j++)
	{
		p=p*j;
		q = q*(u+j-1);
		sum = sum + q*y[n-1][j]/p;
	}
	
	printf("\nThe value of f(%f) = %0.2f ",c,sum);
}
