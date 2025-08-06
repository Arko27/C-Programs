#include<stdio.h>
int main()
{
	int n,i,pos,s,k=0;
	printf("Enter the Size of the Array: ");
	scanf("%d",&n);
	int a[n],b[n],c[n];
	printf("Enter the Array Elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The Array Elements are-->\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	start:
	printf("\nEnter the Position for Rotation: ");
	scanf("%d",&pos);
	if(pos>n || pos==0)
	{
		printf("Invalid Input");
		goto start;
	}
	else
	{
		printf("The Rotated Matrix is-->\n");
		for(i=pos-1;i<=n-1;i++)
			printf("%d ",a[i]);
		for(i=0;i<pos-1;i++)
			printf("%d ",a[i]);
	}
}
