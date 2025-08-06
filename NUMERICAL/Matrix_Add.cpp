//Summation of two matrices check condition

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int matrixaddition(int,int,int *[],int*[],int*[]); 
int main()
{
	int row,column,i,j;
	printf("Enter the common dimension of two matrices to be added: ");
	scanf("%d %d",&row,&column);
	int *matrix1[row],*matrix2[row],*summatrix[row];
	
	printf("Enter the array elements for the First Matrix:\n");
	for (i=0; i<row; i++) 
	{
		matrix1[i] = (int *)malloc(column* sizeof(int));
		for(j=0;j<column;j++)
		{
			scanf("%d",matrix1[i]+j); 
		}
	}
	
	printf("Enter the array elements for the Second Matrix:\n");
	for (i=0; i<row; i++)  
	{ 
		matrix2[i] = (int *)malloc(column* sizeof(int));
		for(j=0;j<column;j++)
		{
			scanf("%d",matrix2[i]+j); 
		} 
	}
	printf("\nThe First Matrix is-->\n");
	for (i=0; i<row; i++)  
	{  
		for(j=0;j<column;j++)  
		printf("%d ",*(matrix1[i]+j)); 
		printf("\n"); 
	} 
	printf("\n");
	printf("The Second Matrix is-->\n");
	for (i=0; i<row; i++)  
	{  
		for(j=0;j<column;j++)  
		printf("%d ",*(matrix2[i]+j)); 
		printf("\n"); 
	} 
	printf("\n");   
	matrixaddition(row,column,matrix1,matrix2,summatrix);
	printf("-----Addition Matrix of Matrix 1 and Matrix 2 -----\n"); 
	for (i=0; i<row; i++)  
	{  
	for(j=0;j<column;j++)  
	printf("%3d ",*(summatrix[i]+j)); 
	printf("\n"); 
	} 
	return 0; 
}  
int matrixaddition(int row,int column,int *x[],int *y[],int *z[]) 
{
	int i,j;  
	for(i=0;i<row;i++) 
	{ 
		z[i] = (int *)malloc(column* sizeof(int));
		for(j=0;j<column;j++)  
		{  
			*(z[i]+j) = *(x[i]+j) + *(y[i]+j);  
		}
	} 
	return 0; 
}
