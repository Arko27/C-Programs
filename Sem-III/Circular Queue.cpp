#include <stdio.h>
#define SIZE 100

int Queue[SIZE];
int front = -1, rear = -1,n;

int isFull()
{
  if ((front == rear + 1) || (front == 0 && rear == n - 1))
  return 1;
  return 0;
}

int isEmpty()
{
  if (front == -1)
  return 1;
  return 0;
}

void Insert(int element)
{
  if (isFull())
  	printf("Queue Overflow\n\n");
  else
  {
  	if (front == -1)
	  front = 0;
    rear = (rear + 1) % n;
    Queue[rear] = element;
    printf("\n---Element Inserted---\n\n");
  }
}

int Del()
{
	int element;
  	if (isEmpty())
  	{
  		printf("Queue Underflow\n\n");
    	return (-1);
	}
	else
	{
		element = Queue[front];
    	if (front == rear)
		{
      		front = -1;
      		rear = -1;
    	}
    	else
      		front = (front + 1) % n;
    	printf("\nThe Element deleted is %d \n", element);
    	return (element);
  	}
}

void display()
{
	int i;
  	if (isEmpty())
    	printf("The Queue is empty\n\n");
  	else
	{
    	printf("\nThe Queue is: ");
    	for (i = front; i != rear; i = (i + 1) % n)
      		printf("%d ", Queue[i]);
    	printf("%d ", Queue[i]);
  	}
  	printf("\n");
}
void count() 
{
	int i,c=0; 
 	for (i = front; i != rear; i = (i + 1) % n)
   		c++; 
  	printf("There are %d Elements in the Queue\n\n",c+1); 
}  
int main() 
{
	int ch,ele;
	printf("Enter the size of the Queue: ");
	scanf("%d",&n);
	printf("\n");
	start:
	printf("1. Insert\n2. Delete\n3. Display\n4. Count\n5. Exit\n");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter the element: ");
			scanf("%d",&ele);
			Insert(ele);
			goto start;
		case 2:
			Del();
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
  return 0;
}
