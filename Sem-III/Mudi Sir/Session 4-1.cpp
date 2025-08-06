#include<stdio.h>
#include<math.h>
#include<malloc.h>
void cofactor(int *[],int *[],int ,int ,int );
int det(int *[],int );
int main()
{
	int n,i,j,D=0;
	printf("Enter the dimensions of the matrix: ");
	scanf("%d %d",&n,&n);
	int *a[n];
	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&(*(a[i]+j)));
		}
	}
	printf("The Matrix is-->\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",*(a[i]+j));
		}
		printf("\n");
	}
	D=det(a,n);
	printf("The Determinant of the Matrix is %d",D);
}
int det(int *mat[],int n)
{
	int D=0,i,j,f,*temp[n],sign=1;
    if(n==1) 
        return (*(mat[0]+0));
    for(i=0;i<n;i++)
    {
    	temp[i]=(int *)malloc(n*sizeof(int));
	}
    for(i=0;i<n;i++) 
    {
       	cofactor(mat,temp,0,i,n);
    	D += sign * (mat[0][i] * det(temp,(n-1)));
       	sign = -sign;
    }
    return D;
}
void cofactor(int *mat[],int *temp[],int p,int q,int n)
{
	int i=0,j=0,row,col;
    for(row=0;row<n;row++) 
    {
		for(col=0;col<n;col++) 
        {
			if (row!=p && col!=q) 
            { 
                *(temp[i]+(j++))=*(mat[row]+col); 
                if (j==(n-1))
                {
                    j=0; 
                    i++; 
                } 
            } 
        } 
    } 
}
