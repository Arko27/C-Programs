//factorial of a number (positive only)

#include<stdio.h>

int main()
{
	int n,f=1,i;
	printf("Enter the number to find the factorial: ");
	scanf("%d",&n);
	if(n>0)
	{
		for(i=1;i<=n;i++)
			f=f*i;
		printf("The factorial of %d is %d",n,f);
	}
	else
		printf("\nFactorial of a negative no is undefined");
}
