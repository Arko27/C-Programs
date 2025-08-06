#include<stdio.h>
#include<process.h>
#define MAX 30
 
typedef struct dequeue
{
	int data[MAX];
	int rear,front;
}dequeue;
 
void initialize(dequeue *p);
int empty(dequeue *p);
int full(dequeue *p);
void enqueueR(dequeue *p,int x);
void enqueueF(dequeue *p,int x);
int dequeueF(dequeue *p);
int dequeueR(dequeue *p);
void print(dequeue *p);

int main()
{
	int i,x,op,n;
	dequeue q;
	initialize(&q);
	start:
		printf("1.Create\n2.Insert(rear)\n3.Insert(front)\n4.Delete(rear)\n5.Delete(front)");
		printf("\n6.Print\n7.Exit\n\nEnter your choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter number of elements: ");
				scanf("%d",&n);
				initialize(&q);
				printf("Enter the data:");
				for(i=0;i<n;i++)
				{
					scanf("%d",&x);
					if(full(&q))
						printf("Queue Overflow\n\n");
					else
						enqueueR(&q,x);
				}
				goto start;
			case 2:
				printf("Enter the Element to be inserted: ");
				scanf("%d",&x);
				if(full(&q))
					printf("Queue Overflow\n\n");
				else
					enqueueR(&q,x);
				goto start;
			case 3:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&x);
				if(full(&q))
					printf("Queue Overflow\n\n");
				else
					enqueueF(&q,x);
				goto start;
			case 4:
				if(empty(&q))
					printf("Queue Underflow\n\n");
				else
				{
					x=dequeueR(&q);
					printf("Element deleted is %d\n\n",x);
				}
				goto start;
			case 5:
				if(empty(&q))
					printf("Queue Underflow\n\n");
				else
					{
						x=dequeueF(&q);
						printf("Element deleted is %d\n\n",x);
					}
				goto start;
			case 6:
				print(&q);
				goto start;
			case 7:
				printf("---Program Terminated---");
				break;
			default:
				printf("Wrong Choice");
				goto start;
		}
}
 
void initialize(dequeue *P)
{
	P->rear=-1;
	P->front=-1;
}
 
int empty(dequeue *P)
{
	if(P->rear==-1)
		return(1);
	return(0);
}
 
int full(dequeue *P)
{
	if((P->rear+1)%MAX==P->front)
		return(1);
	
	return(0);
}
 
void enqueueR(dequeue *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->rear=(P->rear+1)%MAX;
		P->data[P->rear]=x;
	}
}
 
void enqueueF(dequeue *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->front=(P->front-1+MAX)%MAX;
		P->data[P->front]=x;
	}
}
 
int dequeueF(dequeue *P)
{
	int x;
	x=P->data[P->front];
	if(P->rear==P->front)	//delete the last element
		initialize(P);
	else
		P->front=(P->front+1)%MAX;
	return(x);
}
 
int dequeueR(dequeue *P)
{
	int x;
	x=P->data[P->rear];
	if(P->rear==P->front)
		initialize(P);
	else
		P->rear=(P->rear-1+MAX)%MAX;
	return(x);
}
 
void print(dequeue *P)
{
	if(empty(P))
	{
		printf("Queue Underflow\n\n");
		exit(0);
	}
	int i;
	i=P->front;
	while(i!=P->rear)
	{
		printf("\n%d",P->data[i]);
		i=(i+1)%MAX;
	}
	printf("\n%d\n\n",P->data[P->rear]);
}
