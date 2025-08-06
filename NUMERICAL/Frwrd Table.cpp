#include<stdio.h>
int main()
{
	int n,i,j;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	float x[n],y[n][n];
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
	printf("The Forward Difference table is:\n\n");
	for(i=0;i<n;i++)
	{
		printf("%.2f",x[i]);
		for(j=0;j<n-i;j++)
		{
			printf("\t%.2f",y[i][j]);
		}
		printf("\n");
	}
}
