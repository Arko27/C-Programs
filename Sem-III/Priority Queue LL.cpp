#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
struct node{
	int data;
	int prior;
	struct node *link;
}*root=NULL;

int count();

void append()
{
	int c=count();
	if(c+1<SIZE)
	{
		struct node *temp,*p,*ptr;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter the Priority: ");
		scanf("%d",&temp->prior);
		printf("Enter the Data: ");
		scanf("%d",&temp->data);
		temp->link=NULL;
		if(root==NULL)
			root=temp;
		else
		{
			/*p=root;
			while(temp->prior!=p->prior)
			{
				ptr=p;
				p=p->link;
				if(p==NULL)
					break;
			}
			if(p->prior==temp->prior)
			{
				if(p->link==NULL)
					p->link=temp;
				else
				{
					temp->link=p->link;
					p->link=temp;
				}
			}
			else
			{*/
				p=root;
				while((temp->prior>p->prior))
				{
					ptr=p;
					p=p->link;
					if(p==NULL)
						break;
				}
				if(p==root)
				{
					temp->link=p;
					root=temp;
				}
				else if(p==NULL)
					ptr->link=temp;
				else
				{
					ptr->link=temp;
					temp->link=p;
				}
			}
		}
	else
		printf("Queue Overflow\n");
}
void del()
{
	struct node *ptr,*p;
	ptr=root;
	if(ptr==NULL)
		printf("The List is Empty");
	else
	{
		root=ptr->link;
		printf("---Node Deleted Succefully---\n\n");
	}
}
int count()
{
	struct node *ptr;
	int c=0;
	ptr=root;
	if(ptr!=NULL)
	{
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
			c++;
		}
		return c;
	}
	else
		return 0;
}
void display()
{
	struct node *ptr;
	ptr=root;
	if(ptr==NULL)
		printf("\nThe List is empty\n");
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
int main()
{
	int ch,c;
	start:
	printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Count\n5. Exit\n");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			append();
			display();
			goto start;
		case 2:
			del();
			display();
			goto start;
		case 3:
			display();
			goto start;
		case 4:
			c=count();
			if(c==0)
				printf("Queue Underflow\n");
			else
				printf("There are %d elements in the Queue\n",c+1);
			goto start;
		case 5:
			printf("---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
			goto start;
	}
}
