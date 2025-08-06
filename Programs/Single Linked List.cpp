#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}*root=NULL;
int count()
{
	struct node *p;
	int c=0;
	p=root;
	while(p!=NULL)
	{
		c++;
		p=p->link;
	}
	return c;
}
void append_pos()
{
	struct node *temp,*p;
	int pos,i,c;
	c=count();
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the Position and Data: ");
	scanf("%d %d",&pos,&temp->data);
	temp->link=NULL;
	if(pos>=1 && pos<=c+1)
	{
		if(root==NULL)
			root=temp;
		else
		{
			p=root;
			if(pos==1)
			{
				temp->link=root;
				root=temp;
			}
			else
			{
				for(i=1;i<pos-1;i++)
					p=p->link;
				temp->link=p->link;
				p->link=temp;
			} 
		}
		printf("---Node created Succesfully---\n\n");
	}
	else
		printf("Invalid Input\n\n");
}

del_val()
{
	struct node *ptr,*p;
	int val;
	ptr=root;
	printf("Enter the Data to be Deleted: ");
	scanf("%d",&val);
	if(ptr==NULL)
		printf("\nThe List is Empty\n\n");
	else
	{
		if(ptr->link==NULL && ptr->data==val)
		{
			root=NULL;
			printf("\n---Node deleted Succesfully---\n\n");
		}
		else
		{
			while(ptr->data!=val)
			{
				ptr=ptr->link;
				if(ptr==NULL)
					break;
			}
			if(ptr==NULL)
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
					root=ptr->link;
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

void search()
{
	struct node *p;
	int num,f=0;
	p=root;
	printf("Enter an Element to be searched for: ");
	scanf("%d",&num);
	while(p!=NULL)
	{
		if(p->data==num)
		{
			f=1;
			break;
		}
		p=p->link;
	}
	if(f==1)
		printf("Element Found :))\n\n");
	else
		printf("Element Not Found :((\n\n");
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
			append_pos();
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
