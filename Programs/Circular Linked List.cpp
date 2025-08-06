#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}*root=NULL;

int append()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the data: ");
	scanf("%d",&temp->data);
	temp->link=root;
	if(root==NULL)
	{
		root=temp;
		temp->link=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=root)
			p=p->link;
		p->link=temp;
		temp->link=root;
	}
	printf("\n---Node created Succesfully---\n\n");
}
void del_val()
{
	struct node *ptr,*p;
	int val;
	ptr=root;
	if(ptr==NULL)
		printf("\nThe List is Empty");
	else
	{
		printf("Enter the Data to be Deleted: ");
		scanf("%d",&val);
		if(ptr==ptr->link && ptr->data==val)
		{
			root=NULL;
			printf("\n---Node Deleted Succefully---\n\n");
		}
		else
		{
			ptr=root;
			while(ptr->link!=root && ptr->data!=val)
				ptr=ptr->link;
			if(ptr->link==root && ptr->data!=val)
				printf("\nThe Value is not present\n\n");
			else
			{
				ptr=root;
				while(ptr->data!=val)
				{
					p=ptr;
					ptr=ptr->link;
				}
				if(ptr==root)
				{
					while(ptr->link!=root)
						ptr=ptr->link;
					root=root->link;
					ptr->link=root;
				}
				else
					p->link=ptr->link;
				printf("\n---Node deleted Succesfully---\n\n");
			}
		}
	}
}
void display()
{
	struct node *ptr;
	ptr=root;
	if(ptr==NULL)
		printf("\nThe List is empty");
	else
	{
		printf("The data/s is/are---> ");
		while(ptr->link!=root)
		{
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
		printf("%d ",ptr->data);
	}
	printf("\n\n");
}
void search()
{
	struct node *p;
	int num,f=0;
	p=root;
	printf("Enter an Element to be searched for: ");
	scanf("%d",&num);
	if(p->data==num)
		printf("Element Found:))");
	else
	{
		p=p->link;
		while(p->data!=num)
		{
			p=p->link;
			if(p==root)
				break;
		}
		if(p==root)
			printf("Element Not Found:((\n");
		else
			printf("Element Found:))\n");
	}
	
}
int main()
{
	int ch;
	start:
	printf("1. Insert an Element\n");
	printf("2. Delete an Element\n");
	printf("3. Display the List\n");
	printf("4. Search an Element\n");
	printf("5. Exit\n");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			append();
			goto start;
		case 2:
			del_val();
			goto start;
		case 3:
			display();
			goto start;
		case 4:
			search();
			goto start;
		case 5:
			printf("\n---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
			goto start;
	}
}
