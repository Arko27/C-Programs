#include<stdio.h>

int main()
{
	int n;
	printf("Enter a no. to be checked: ");
	scanf("%d",&n);
	if(n%2==0)
		printf("%d is an Even no.",n);
	else
		printf("%d is an Odd no.",n);
}
