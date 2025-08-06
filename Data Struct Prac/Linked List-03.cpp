#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}*root=NULL;
int c=0;

void append_end()
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
void append_begin()
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the data: ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		temp->link=root;
	}
	else
	{
		p=root;
		while(p->link!=root)
			p=p->link;
		temp->link=root;
		root=temp;
		p->link=root;
	}
	printf("\n---Node created Succesfully---\n\n");
}
void append_pos()
{
	struct node *temp,*p;
	int pos,i;
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
				p=root;
				while(p->link!=root)
					p=p->link;
				temp->link=root;
				root=temp;
				p->link=root;
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
		printf("Invalid Input");
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
void del_value()
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
int count()
{
	struct node *ptr;
	ptr=root;
	if(root==NULL)
	printf("There are 0 Nodes in the List\n");
	else
	{
		while(ptr->link!=root)
		{
			c++;
			ptr=ptr->link;
		}
	}
	return c;
}
int main()
{
	int ch;
	start:
	printf("1. Append Node at Begin\n");
	printf("2. Append Node at Position\n");
	printf("3. Append Node at End\n");
	printf("4. Delete Node by Value\n");
	printf("5. Count Nodes\n");
	printf("6. Display Nodes\n");
	printf("7. Exit\n");
	printf("Enter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			append_begin();
			display();
			goto start;
		case 2:
			count();
			append_pos();
			display();
			goto start;
		case 3:
			append_end();
			display();
			goto start;
		case 4:
			del_value();
			display();
			goto start;
		case 5:
			count();
			printf("The Length of the List is %d\n",c);
			goto start;
		case 6:
			display();
			goto start;
		case 7:
			printf("\n---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
			goto start;
	}
}
