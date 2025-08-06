#include<stdio.h>
int insert(int [],int ,int ,int );
int delpos(int [],int ,int );
int delele(int [],int ,int );
int count(int [],int );
int display(int [],int );
int c=0;
int insert(int a[],int n,int pos,int ele)
{
	int i,p=-1;
	if(a[pos-1]==0)
	{
		a[pos-1]=ele;
		c++;
	}
	else
	{
		for(i=pos-1;i<n;i++)
		{
			if(a[i]==0)
			{
				p=i;
				break;
			}
		}
		if(p==-1)
			printf("Array is full\n");
		else if(p>=0)
		{
			for(i=p;i>=pos;i--)
			{
				a[i]=a[i-1];
				a[i-1]=0;
			}
				a[pos-1]=ele;
				c++;
		}
	}
}

int delpos(int a[],int n,int pos)
{
	if(a[pos-1]!=0)
	{
		a[pos-1]=0;
		c--;
	}
	else
		printf("Array index already empty\n");
}

int delele(int a[],int n,int ele)
{
	int i,en;
	for(i=0;i<n;i++)
	{
		if(a[i]==ele)
		{
			a[i]=0;
			c--;
			break;
		}
		else
			en=1;
	}
	if(en==1)
	printf("\nElement Not Found");
}

int count(int a[],int n)
{
	printf("Total elements in the array is %d\n",c);
}

int display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

int main()
{
	int n,i,c;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		a[i]=0;
	printf("The array is created as:-->\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	start:
	printf("\n1. Insertion");
	printf("\n2. Deletion");
	printf("\n3. Count");
	printf("\n4. Display");
	printf("\n5. Exit");
	printf("\nEnter Your Choice: ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			int pos,ele;
			printf("\nEnter the position followed by the element: ");
			scanf("%d %d",&pos,&ele);
			if(pos>=1 && pos<=n)
				insert(a,n,pos,ele);
			else
				printf("\nInvalid Input");
			for(i=0;i<n;i++)
				printf("%d ",a[i]);
			goto start;
			break;
		
		case 2:
			int dc;
			printf("\n1. Delete by Position");
			printf("\n2. Delete by Element");
			printf("\nEnter: ");
			scanf("%d",&dc);
			switch(dc)
			{
				case 1:
					int i,po;
					printf("\nEnter the position: ");
					scanf("%d",&po);
					if(po>=1 && po<=n)
					{
						delpos(a,n,po);
						for(i=0;i<n;i++)
							printf("%d ",a[i]);
					}
					else
						printf("\nInvalid Input");
					goto start;
					break;
				case 2:
					int el;
					printf("\nEnter the element: ");
					scanf("%d",&el);
					delele(a,n,el);
					for(i=0;i<n;i++)
						printf("%d ",a[i]);
					goto start;
					break;
				
				default:
					printf("\nInvalid Input");
					goto start;
					break;
			}
		
		case 3:
			count(a,n);
			goto start;
			break;
		
		case 4:
			display(a,n);
			goto start;
			break;
			
		case 5:
			break;
		
		default:
			printf("\nWrong choice");
			goto start;
	}
}
