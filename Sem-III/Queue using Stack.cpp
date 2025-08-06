#include<stdio.h>
#include<stdlib.h>
# define N 100
int s[N],n,top = -1;
int pop()
{
	return s[top--];
}
void push(int x)
{
	top++;
	s[top] = x;	
}
void enqueue(int x)
{
	push(x);
}
int dequeue()
{	
	int data,res;
	if(top == -1)
		printf("Queue Underflow\n");
	else if(top == 0)
		return pop();
	data = pop();
	res = dequeue();
	push(data);
	return res;
}
void display()
{
	if(top=-1)
		printf("The Queue is Empty\n");
	else
	{
		int i;
		for(i=0;i<=top;i++)
			printf("%d  ",s[i]);
		printf("\n");
	}
}
void count()
{
	int i,c=0;
	if(top==-1)
		printf("The Queue is Empty\n");
	else
	{
		for(i=top;i>=0;i--)
			c++;
		printf("There are %d Elements in the Stack\n",c);
	}
}
int main()
{
	int opt,i,data,t;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	start:
	printf("1. Insert Data\n2. Delete Data\n3. Display the Queue\n4. Count the Datas\n5. Exit\n");
	printf("Enter Your Choice: ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			if(top == n-1)
				printf("Stack Overflow\n");
			else
			{
				printf("Enter the data: \n");
				while(top<n-1)
				{
					scanf("%d",&data);
					enqueue(data);
				}
			}
			goto start;
		case 2:
			t=dequeue();
			printf("Dequeued element is: %d\n",t);
			goto start;
		case 3:
			display();
			goto start;
		case 4:
			count();
			goto start;
		case 5:
			printf("---Program Terminated---");
			break;
		default:
			printf("\nWrong Choice");
			goto start;
	}
}
