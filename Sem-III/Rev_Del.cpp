#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}*root=NULL;
int c=0;
int append_end()
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
		struct node *p;
		p=root;
		while(p->link!=NULL)
			p=p->link;
		p->link=temp;
	}
	printf("---Node created Succesfully---\n\n");
}
void display()
{
	struct node *ptr;
	ptr=root;
	if(ptr==NULL)
		printf("The List is empty");
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
void reverse()
{ 
    struct node *prev = NULL,*current,*next = NULL; 
    current=root;
    while(current!=NULL)
	{ 
        next=current->link; 
        current->link=prev; 
        prev=current; 
        current=next; 
    } 
    root=prev;
    	printf("---List Reversed Succesfully---\n\n");
}
del_val()
{
	struct node *ptr,*p;
	int val,f=0;
	ptr=root;
	printf("Enter the Data to be Deleted: ");
	scanf("%d",&val);
	if(ptr==NULL)
		printf("The List is Empty\n");
	else
	{
		while(ptr->data!=val && ptr->link!=NULL)
			ptr=ptr->link;
		if(ptr->link==NULL)
			printf("The Value is not present\n\n");
		else
		{
			ptr=root;
			while(ptr->data!=val)
			{
				p=ptr;
				ptr=ptr->link;
			}
			if(ptr==root)
				root=ptr->link;
			else
				p->link=ptr->link;
			printf("---Node deleted Succesfully---\n\n");
		}
	}
}
int main()
{
	int ch;
	start:
	printf("1. Append Node\n2. Display the List\n3. Reverse the List\n4. Delete element\n5. Exit");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			append_end();
			goto start;
		case 2:
			display();
			goto start;
		case 3:
			reverse();
			goto start;
		case 4:
			del_val();
			goto start;
		case 5:
			printf("\n<---The Program is Terminated--->");
			break;
		default:
			printf("\nWrong Choice");
			goto start;
	}
}
