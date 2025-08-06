#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}*root=NULL;
void push()
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
void count()
{
	struct node *ptr;
	int c=0;
	ptr=root;
	if(ptr==NULL)
		printf("There are no elements in the Stack\n");
	else
	{
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
			c++;
		}
		printf("There are %d elements in the Stack\n",c+1);
	}
}
void display()
{
	struct node *ptr;
	ptr=root;
	if(ptr==NULL)
		printf("\nUnder Flow\n");
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
void peak()
{
	struct node *ptr;
	ptr=root;
	if(root=NULL)
		printf("Under Flow");
	else
		printf("The peak data is %d\n",ptr->data);	
}
int main()
{
	int ch;
	start:
	printf("1. Push\n2. Pop\n3. Display\n4. Count\n5. Peak\n6. Exit\n");
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
			count();
			goto start;
		case 5:
			peak();
			goto start;
		case 6:
			printf("---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
	}
}
