#include<stdio.h>
int main()
{
	int n,i,j,a,b,c;
	printf("Enter the no. of cities: ");
	scanf("%d",&n);
	int g[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			g[i][j] = 0;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a);
			scanf("%d",&b);
			scanf("%d",&c);
			g[a-1][b-1] = c;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
}
