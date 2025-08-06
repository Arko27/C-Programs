//FORWARD INTERPOLATION

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
	
	for (j = 1;j <= (n-1);j++)
	{
		for (i = 0;i < (n-j);i++)
		{
			y[i][j] = y[i+1][j-1] - y[i][j-1];
		}
	}
		
	printf("\nThe Forward Difference table is:\n\n");
	for(i=0;i<n;i++)
	{
		printf("%.2f",x[i]);
		for(j=0;j<n-i;j++)
		{
			printf("\t%.2f",y[i][j]);
		}
		printf("\n");
	}
	
	printf("\nEnter the value of p: ");
	scanf("%f",&p);
	float c=p;
	
	h = x[1]-x[0];
	u = (p - x[0])/h;
	sum = y[0][0];
	p=1;
	q=1;
	
	for(j=1;j<=n-1;j++)
	{
		p=p*j;
		q = q*(u+1-j);
		sum = sum + q*y[0][j]/p;
	}
	
	printf("\nThe value of f(%f) = %0.2f ",c,sum);
	
}
