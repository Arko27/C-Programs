#include <stdio.h>
#define max 25

void bubbleSort(int arr[], int n)
{
    int t=0,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}
void display(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int n, item;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[max];
    int ch, i;
    printf("\nEnter the numbers:\n");
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("The Array is: ");
	display(arr,n);
	bubbleSort(arr,n);
	printf("\n\nThe Sorted Array is: ");
	display(arr,n);
}
