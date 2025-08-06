//TRAPEZOIDAL INTEGRATION

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float y(float x)
{
	return (x*x);
}

float trapezoidal(float a, float b, float n)
{
	int i;
	float h,s;
	
	h = (b-a)/n;
	s = y(a)+y(b);

	for (i = 1; i < n; i++)
		s += 2*y(a+i*h);
	
	return (h/2)*s;
}

int main()
{
	int n;
	float x0,x1;
	
	printf("Enter the Lower Limit: ");
	scanf("%f",&x0);
	printf("\nEnter the Upper Limit: ");
	scanf("%f",&x1);
	printf("\nEnter the no of intervals: ");
	scanf("%d",&n);
		
	printf("\nValue of Integral is %f\n",trapezoidal(x0, x1, n));
	return 0;
}
