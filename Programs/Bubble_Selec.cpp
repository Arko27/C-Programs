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
void selectionSort(int arr[], int n)
{
    int t,i,j,pos=0;
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[pos]> arr[j])
            {
                pos=j;
            }
        }
        if(pos != i)
        {
            t=arr[i];
            arr[i]=arr[pos];
            arr[pos]=t;
        }
    }
}
void display(int arr[], int n)
{
    printf("\nThe sorted array is ");
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
	printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
                bubbleSort(arr,n);
                display(arr,n);
                break;
        case 2:
                selectionSort(arr,n);
                display(arr,n);
                break;
        case 3:
        	printf("---Program Terminated---");
        	break;
        default:
                printf("\nWrong choice ");
    }
}
