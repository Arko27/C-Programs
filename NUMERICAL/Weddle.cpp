#include<stdio.h> 
#include<math.h>

float y(float x)
{
    return 1/(1 + (x*x));
}
float WeddleRule(float a, float b, int n)
{
    double h = (b - a) / n; float sum = 0;
    sum = sum + (((3 * h) / 10) * (y(a)+ y(a + 2 * h)+ 5 * y(a + h)+ 6 * y(a + 3 * h)+ y(a + 4 * h)+ 5 * y(a + 5 * h)+ y(a + 6 * h)));
    return sum;
}
int main()
{
	float a, b;
	int n;
	printf("Enter the Lower Limit : ");
	scanf("%f",&a);
	printf("\nEnter the Upper Limit : ");
	scanf("%f",&b);
	printf("\nEnter the number of sub-intervals : ");
	scanf("%d",&n);
	printf("f(x) = %f", WeddleRule(a, b, n)); 
	return 0;
}
