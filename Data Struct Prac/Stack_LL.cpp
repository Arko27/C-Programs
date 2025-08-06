#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct node{
	int data;
	struct node *link;
}*root;
int count();
void push()
{
	int c=count();
	if(c<SIZE)
	{
		struct node *tmp;
		tmp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter the data: ");
		scanf("%d",&tmp->data);
		tmp->link=NULL;
		if(tmp==NULL)
			printf("Over Flow");
		else
		{
			if(root==NULL)
				root=tmp;
			else
			{
				tmp->link=root;
				root=tmp;		
			}
		}
	}
	else
		printf("Stack Overflow\n\n");
}
int count()
{
	struct node *ptr;
	int c=0;
	ptr=root;
	while(ptr!=NULL)
	{
		ptr=ptr->link;
		c++;
	}
	return c;
}
void display()
{
	struct node *ptr;
	ptr=root;
	if(ptr==NULL)
		printf("The Stack is empty\n\n");
	else
	{
		printf("The data/s is/are---> ");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
		printf("\n\n");
	}
}
void pop()
{
	struct node *ptr;
	ptr=root;
	if(ptr==NULL)
		printf("Under Flow\n");
	else
	{
		printf("The Data Popped is %d\n",ptr->data);
		root=ptr->link;
	}
}
int main()
{
	int ch;
	start:
	printf("1. Push\n2. Pop\n3. Display\n4. Count\n5. Exit\n");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			push();
			goto start;
		case 2:
			pop();
			goto start;
		case 3:
			display();
			goto start;
		case 4:
			int c;
			c=count();
			printf("No of nodes is/are: %d\n",c);
			goto start;
		case 5:
			printf("---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
			goto start;
	}
}
