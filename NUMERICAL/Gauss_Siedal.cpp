#include<stdio.h> 
#include<math.h>
 
#define f1(x, y, z)(15 - y - z)/10
#define f2(x, y, z)(24 - x - z)/10 
#define f3(x, y, z)(33 - x - y)/10

int main()
{
	float x0, y0, z0, x1, y1, z1, e, ex, ey, ez;
	int count = 0;
	
	printf("Enter tolerable error: \ne = "); 
	scanf("%f", &e);
	
	printf("\nEnter initial guess for x: \nx0 = "); 
	scanf("%f", &x0);
	
	printf("\nEnter initial guess for y: \ny0 = ");  
	scanf("%f", &y0);
	
	printf("\nEnter initial guess for z: \nz0 = "); 
	scanf("%f", &z0);
	
	printf("\nCount\tx\ty\tz\n");
	
	do
	{
		x1 = f1(x0, y0, z0);
		y1 = f2(x1, y0, z0);
		z1 = f3(x1, y1, z0); 
		printf("%d\t%0.4f\t0.4f\t%0.4f\n", count, x1, y1, z1);
		ex = fabs(x1 - x0);
		ey = fabs(y1 - y0);
		ez = fabs(z1 - z0);
		
		count++;
		x0 = x1;
		y0 = y1;
		z0 = z1;
		
	}while(ex>e && ey>e && ez>e);
	
	printf("\nFinal Approximation:\nx=%0.3f\ny=%0.3f\nz=%0.3f\n", x1, y1, z1);
	return 0;
}
