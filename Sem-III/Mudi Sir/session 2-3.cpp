#include<stdio.h>
int main()
{
	int n,i,c=0,max=0;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The Array is-->\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	for(i=0;i<n-1;i++)
	{
		if(a[i+1]-a[i]==1)
			c++;
		else
		{
			if(c>max)
				max=c;
			c=0;
		}
	}
	printf("\nThe longest sequence is of length %d",(max+1));
}
