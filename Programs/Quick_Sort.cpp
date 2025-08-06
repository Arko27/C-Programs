#include <stdio.h>
#include<stdlib.h> 
void quicksort(int *list, int low, int high)
{
	int pivot, i, j, temp;     
	if (low < high)
	{
		pivot=low;
		i=low;
 		j=high;
		while (i<j)
		{
			while(list[i]<=list[pivot] && i<=high)            
 			{
  				i++;
 			}
			while (list[j] > list[pivot] && j>=low)
 			{
 				j--;
			}            
 			if (i < j)
			{
				temp = list[i];
 				list[i] = list[j];
				list[j] = temp;
			}
		}
 		temp = list[j];
 		list[j] = list[pivot];
 		list[pivot] = temp;
		quicksort(list, low, j - 1);
		quicksort(list, j + 1, high);
	}
}
int main()
{
	int i,n,*data;
	printf("Enter the number of inputs:");
	scanf("%d",&n);
	data=(int *)malloc(sizeof(int) * n);
	printf("Enter the data to be sorted:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d", &data[i]); 
    }
	quicksort(data,0,n-1);
	printf("Sorted array:\n");         
	for (i=0;i<n;i++)
	{
		printf("%d ",data[i]);
    }
    printf("\n");         
	return 0;
}
