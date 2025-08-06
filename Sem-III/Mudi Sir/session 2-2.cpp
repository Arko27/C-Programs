#include<stdio.h>
int main()
{
	int n,i,j,k;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The Array is-->\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	for(i=0;i<n;i++)
	{
        for(j=i+1;j<n;)
    	{
			if(a[j]==a[i])
            {
                for(k=j;k<n;k++)
                {
                	a[k]=a[k+1];
                }
                n--;
            }
            else
            	j++;
        }
	}
    printf("\nThe Array without Duplicate elements is-->\n");
    for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
