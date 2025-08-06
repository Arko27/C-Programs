#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct node{
	int data;
	struct node *link;
}*root;
int count();
void append_begin()
{
	int c=count();
	if(c<SIZE)
	{
		struct node *temp;
		temp=(struct node*)malloc(sizeof(struct node*));
		printf("Enter the data: ");
		scanf("%d",&temp->data);
		temp->link=NULL;
		if(root==NULL)
			root=temp;
		else
		{
			temp->link=root;
			root=temp;
		}
		printf("---Node created Succesfully---\n\n");
	}
	else
		printf("Queue Overflow\n\n");
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
		printf("The Queue is empty\n\n");
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
void del_end()
{
	struct node *ptr,*p;
	ptr=root;
	if(ptr==NULL)
		printf("Queue Underflow\n\n");
	else
	{
		while(ptr->link!=NULL)
		{
			p=ptr;
			ptr=ptr->link;
		}
		if(ptr==root)
			root=NULL;
		else
			p->link=NULL;
		printf("The Deleted Element is %d\n\n",ptr->data);
		printf("---Node Deleted Succefully---\n\n");
	}
}
int main()
{
	int ch,c;
	start:
	printf("1. Insertion\n2. Deletion\n3. Display\n4. Count\n5. Exit\n");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			append_begin();
			goto start;
		case 2:
			del_end();
			goto start;
		case 3:
			display();
			goto start;
		case 4:
			c=count();
			if(c==0)
				printf("Queue Underflow\n");
			else
				printf("There are %d elements in the Queue\n",c);
			goto start;
		case 5:
			printf("---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
			goto start;
	}
}
