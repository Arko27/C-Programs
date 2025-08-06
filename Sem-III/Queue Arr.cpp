#include<stdio.h>
#define size 100
int queue[size],front=-1,rear=-1,n;

void enqueue()
{
	if(rear==(n-1))
		printf("Queue Overflow\n\n");
	else if(front==-1 && rear==-1)
	{
		front=0,rear=0;
		printf("Enter the element: ");
		scanf("%d",&queue[rear]);
	}
	else
	{
		printf("Enter the element: ");
		rear++;
		scanf("%d",&queue[rear]);
	}
}

void dequeue()
{
	int i;
	if(front==rear)
		printf("Queue Underflow\n\n");
	else
	{
		printf("The Dequeued Element is %d\n\n",queue[front]);
		for(i=1;i<n;i++)
			queue[i-1]=queue[i];
		rear--;
	}
}

void count()
{
	int i,c=0;
	if(front==rear)
		printf("The Queue is Empty\n\n");
	else
	{
		for(i=rear;i>=0;i--)
			c++;
		printf("\nThere are %d Elements in the Queue\n",c);
	}
}

void display()
{
	int i;
	if(front==rear)
		printf("The Queue is Empty\n\n");
	else
	{
		printf("The Elements in the Queue are-->\n");
		for(i=rear;i>=0;i--)
			printf("%d\t",queue[i]);
		printf("\n");
	}
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
