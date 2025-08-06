#include<stdio.h>
#include<math.h>
#include<malloc.h>
void cofactor(int *[],int *[],int ,int ,int );
int det(int *[],int );
void display(int *a[],int n);
void display(float *a[],int n);
void adjoint(int *mat[],int *adj[],int n);
bool inverse(int *mat[], float *inv[],int n);
int main()
{
	int n,i,j,D=0;
	printf("Enter the dimensions of the matrix: ");
	scanf("%d %d",&n,&n);
	int *a[n],*adj[n];
	float *inv[n];
	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(n*sizeof(int));
		adj[i]=(int *)malloc(n*sizeof(int));
		inv[i]=(float *)malloc(n*sizeof(float));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&(*(a[i]+j)));
		}
	}
	printf("The Matrix is-->\n");
	display(a,n);
	D=det(a,n);
	printf("The Determinant of the Matrix is %d\n",D);
	printf("The Adjoint of the Matrix is-->\n");
	adjoint(a,adj,n);
	display(adj,n);
	printf("The Inverse of the Matrix is-->\n");
	if(inverse(a,inv,n)==true)
		display(inv,n);
	else
		printf("Inverse doesn't exist");
}
void display(int *a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",*(a[i]+j));
		}
		printf("\n");
	}
}
void display(float *a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%.2f ",*(a[i]+j));
		}
		printf("\n");
	}
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
void adjoint(int *mat[],int *adj[],int n) 
{
	int i,j,sign=1,*temp[n];
    for(i=0;i<n;i++)
    {
    	temp[i]=(int *)malloc(n*sizeof(int));
	}
    for(i=0;i<n;i++) 
    {
    	for(j=0;j<n;j++) 
        {
            cofactor(mat, temp, i, j, n);
            sign = ((i + j) % 2 == 0)? 1: -1;
            *(adj[j]+i) = (sign)*(det(temp, n-1));
        } 
    } 
}
bool inverse(int *mat[], float *inv[],int n) 
{
	int i,j,d=0,*adj[n];
	d=det(mat,n);	
	if(d==0)
		return false;
	else
	{
		for(i=0;i<n;i++)
    	{
    		adj[i]=(int *)malloc(n*sizeof(int));
		}
		adjoint(mat,adj,n);
    	for (int i = 0; i < n; i++)
    	{
    		for (int j = 0; j < n; j++)
    		{
    			*(inv[i]+j) = *(adj[i]+j)/(float)d;
    		}
    	}
    	return true;
    }
}
