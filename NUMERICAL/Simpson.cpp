//SIMPSON 1-3RD INTEGRATION

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float func(float x)
{
	return (x/(1+x));
}

float simpsons(float ll, float ul, int n)
{
	int i;
	float h;
	
	h = (ul - ll) / n;

	float x[n], fx[n];

	for (i = 0; i <= n; i++)
	{
		x[i] = ll + i * h;
		fx[i] = func(x[i]);
	}

	float res = 0;
	res+= fx[0] + fx[n];
	for (i = 1; i < n; i++)
	{
		if (i % 2 != 0)
			res += 4 * fx[i];
		else if (i % 2 == 0)
			res += 2 * fx[i];
	}
	res = res * (h / 3);
	return res;
}

int main()
{
	int n;
	float ll,ul;	
	
	printf("Enter the Lower Limit: ");
	scanf("%f",&ll);
	printf("\nEnter the Upper Limit: ");
	scanf("%f",&ul);
	printf("\nEnter the no of intervals: ");
	scanf("%d",&n);
	
	printf("\nThe value of Integral is %f ",simpsons(ll, ul, n));
	return 0;
}
