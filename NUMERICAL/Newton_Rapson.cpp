#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f(x) sin(x)-x/2
#define g(x) cos(x)-1/2

void newtonRaphson(float x)
{
	float e,h;
	printf("Enter the tolerable error:");
	scanf("%f",&e);
	h = f(x)/g(x);
	while (abs(h) >= e)
	{
		h = f(x)/g(x);
		x = x - h;
	}

	printf("The value of the root is : %f",x);
}

int main()
{
	float x0;
	printf("Enter the initial guess: ");
	scanf("%f",&x0);
	newtonRaphson(x0);
	return 0;
}
