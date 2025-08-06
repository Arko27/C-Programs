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

void insertionSort(int arr[], int n)
{
    int i,j, k;
    for(i=1;i<n;i++)
    {
        k = arr[i];
        j=i-1;
        while(j>=0 && arr[j] > k)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = k;
    }
}

int partition (int arr[], int low, int high)
{
    int pivot, i, t, j;
    pivot = arr[high];

    i = (low - 1);

    for (j = low; j <= high- 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            t=arr[i];
            arr[i] = arr[j];
            arr[j]=t;
        }
    }
    t=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=t;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bin_Search(int arr[], int n, int search)
{
    int first,last,middle;
    first = 0;
    last = n - 1;
    middle = (first+last)/2;

    while (first <= last)
    {
        if (arr[middle] < search)
            first = middle + 1;
        else if (arr[middle] == search)
        {
            printf("%d found at location %d.\n", search, middle+1);
            break;
        }
        else
        last = middle - 1;

        middle = (first + last)/2;
    }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);
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
    printf("Enter the size of the array ");
    scanf("%d", &n);
    int arr[max];
    int ch, i;
    printf("\nEnter the numbers ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
  	start: 
	printf("\n1. Bubble Sort ");
    printf("\n2. Selection Sort ");
    printf("\n3. Insertion Sort ");
    printf("\n4. QuickSort ");
    printf("\n5. EXIT ");
    printf("\nEnter your choice ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
                bubbleSort(arr,n);
                display(arr,n);
                printf("\nEnter element to search ");
                scanf("%d", &item);
                bin_Search(arr,n,item);
                goto start;
        case 2:
                selectionSort(arr,n);
                display(arr,n);
                printf("\nEnter element to search ");
                scanf("%d", &item);
                bin_Search(arr,n,item);
                goto start;
        case 3:
                insertionSort(arr,n);
                display(arr,n);
                printf("\nEnter element to search ");
                scanf("%d", &item);
                bin_Search(arr,n,item);
                goto start;
        case 4:
                quickSort(arr, 0, n-1);
                display(arr, n);
                printf("\nEnter element to search ");
                scanf("%d", &item);
                bin_Search(arr,n,item);
                goto start;
        case 5:
                break;
        default:
                printf("\nWrong choice ");
    }
}
