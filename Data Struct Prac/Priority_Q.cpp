#include<stdio.h>
#define N 20
int Q[N],Pr[N];
int r = -1,f = -1;
void insert(int data,int p)//insert function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==N-1)) //Check if Queue is full
		printf("Queue Overflow\n\n");
	else
	{
		if(f==-1)//if Queue is empty
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else if(r == N-1)//if there there is some elemets in Queue
		{
			for(i=f;i<=r;i++)
			{
				Q[i-f] = Q[i];
				Pr[i-f] = Pr[i];
				r = r-f;
				f = 0;
				for(i = r;i>f;i--)
				{
					if(p>Pr[i])
					{
						Q[i+1] = Q[i];
						Pr[i+1] = Pr[i];
					}
					else
						break;
					Q[i+1] = data;
					Pr[i+1] = p;
					r++;
				}
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Pr[i])
				{
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];	
				}
				else
					break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}	
	}
}

void print() //print the data of Queue
{
	int i;
	for(i=f;i<=r;i++)
		printf("\nElement = %d\tPriority = %d",Q[i],Pr[i]);
	printf("\n\n");
}

int del() //remove the data from front
{
	if(f == -1)
		printf("Queue Underflow\n\n");	
	else
	{
		printf("deleted Element = %d\t Its Priority = %d\n",Q[f],Pr[f]);
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}
void count()
{
	int c=0,i=0;
	for(i=f;i<=r;i++)
	{
		c++;
	}
	printf("The no. of Elements in the Queue is %d\n",c);
}

int main()
{
	int ch,n,i,data,p;
	start:
	printf("1. Insertion\n2. Deletion\n3. Display\n4. Count\n5. Exit\n");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter the Number of Data: ");
			scanf("%d",&n);
			printf("\nEnter your Data and Priority of data:\n");
			i=0;
			while(i<n)
			{
				scanf("%d %d",&data,&p);
				insert(data,p);
				i++;
			}
			goto start;
		case 2:
			del();
			goto start;
		case 3:
			print();
			goto start;
		case 4:
			count();
			goto start;
		case 5:
			printf("---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
		goto start;
	}
}
