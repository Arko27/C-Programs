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
	temp->link=root;
	p=root;
	if(root==NULL)
	{
		root=temp;
		temp->link=p;
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
		c++;
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
void del_end()
{
	struct node *ptr,*p;
	ptr=root;
	if(ptr==NULL)
		printf("\nThe List is Empty");
	else
	{
		while(ptr->link!=root)
		{
			p=ptr;
			ptr=ptr->link;
		}
		if(ptr==ptr->link)
			root=NULL;
		else
			p->link=root;
		printf("\n---Node Deleted Succefully---\n\n");
		c--;
	}
}
void del_begin()
{
	struct node *ptr,*p;
	ptr=root;
	if(ptr==NULL)
		printf("\nThe List is Empty");
	else
	{
		if(ptr==ptr->link)
			root=NULL;
		else
		{
			while(ptr->link!=root)
				ptr=ptr->link;
			root=root->link;
			ptr->link=root;
		}
		printf("\n---Node Deleted Succefully---\n\n");
		c--;	
	}
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
			c--;
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
				c--;
			}
		}
	}
}
/*void search()
{
	
}
void reverse()
{
	
}
void sort()
{
	
}*/
int main()
{
	int ch;
	start:
	printf("1. Append Node at End\n2. Append Node at Beginning\n3. Append Node at Position\n4. Delete Node from End\n");
	printf("5. Delete Node from Beginning\n6. Delete by Value\n7. Delete Duplicate Elements\n8. Length of the List\n");
	printf("9. Search a Node\n10. Reverse the List\n11. Sort the List\n12. Display\n13. Exit\n");
	printf("Enter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			append_end();
			c++;
			goto start;
		case 2:
			append_begin();
			c++;
			goto start;
		case 3:
			append_pos();
			goto start;
		case 4:
			del_end();
			goto start;
		case 5:
			del_begin();
			goto start;
		case 6:
			del_value();
			goto start;
		/*case 7:
			del_dup();
			goto start;*/
		case 8:
			printf("The Length of the List is %d\n",c);
			goto start;
		/*case 9:
			search();
			goto start;
		case 10:
			reverse();
			goto start;
		case 11:
			sort();
			goto start;*/
		case 12:
			display();
			goto start;
		case 13:
			printf("\n---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
			goto start;
	}
}
