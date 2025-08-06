#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int queue[MAX],front=-1,rear=-1,n;

void enqueue()
{
	int data;
	if(rear==n-1)
		printf("\nQueue is Full!");
	else
	{
		rear=rear+1;
		printf("Enter the element: ");
		scanf("%d",&data);
		queue[rear]=data;
		if(front==-1)
		front=0;
	}
	
}
void display()
{
	printf("\nThe elements in the queue are:");
	int i;
	if(front==-1)
		printf("\nQueue is Empty");
	else
		for(i=front;i<=rear;i++)
		{
		   
			printf("%d ",queue[i]);
		}
		printf("\n");
}
void dequeue()
{
	if(front==-1||front==rear+1)
		printf("\nQueue is Empty");
	else
	{
		queue[front]=0;
		front=front+1;
	}
	display();
}
void count()
{
	int i,c=0;
	for(i=front;i<=rear;i++)
		c++;
	printf("\nThere are %d Elements in the Queue\n",c);
}
int main()
{
	int ch;
	printf("Enter the size of the Queue: ");
	scanf("%d",&n);
	start:
	printf("1. Insertion\n2. Deletion\n3. Display\n4. Count\n5. Exit\n");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			enqueue();
			goto start;
		case 2:
			dequeue();
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
			printf("Wrong Choice");
			goto start;
	}
}
