#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL;

int count()
{
	struct node *p;
	int c=0;
	p=root;
	while(p!=NULL)
	{
		c++;
		p=p->right;
	}
	return c;
}

append_pos()
{
	struct node *temp,*p;
	int pos,i,c;
	c=count();
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the Position and Data: ");
	scanf("%d %d",&pos,&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(pos>=1 && pos<=c+1)
	{
		if(root==NULL)
			root=temp;
		else
		{
			if(pos==1)
			{
				temp->right=root;
				root=temp;
			}
			else if(pos==c+1)
			{
				p=root;
				while(p->right!=NULL)
					p=p->right;
				temp->left=p;
				p->right=temp;
			}
			else
			{
				p=root;
				for(i=1;i<pos-1;i++)
					p=p->right;
				temp->left=p;
				temp->right=p->right;
				p->right=temp;
			}
		}
		printf("\n---Node created Succesfully---\n\n");
	}
	else
		printf("\nInvalid Input\n");
}

void del_val()
{
	struct node *p,*ptr;
	int val;
	ptr=root;
	printf("Enter the data to be deleted: ");
	scanf("%d",&val);
	if(ptr==NULL)
	{
		root=NULL;
		printf("The List is Empty\n");
	}
	else
	{
		if(ptr->left==NULL && ptr->right==NULL && ptr->data==val)
		{
			root=NULL;
			printf("\n---Node deleted Succesfully---\n\n");
		}
		else
		{
			while(ptr->data!=val)
			{
				ptr=ptr->right;
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
					ptr=ptr->right;
				}
				if(ptr==root)
				{
					root=ptr->right;
					ptr->right->left=NULL;
				}
				else if(ptr->right==NULL)
					p->right=NULL;
				else
				{
					p->right=ptr->right;
					ptr->right->left=p;
				}
				printf("\n---Node deleted Succesfully---\n\n");
			}
		}
	}
}

void display()
{
    struct node *temp=root;
    if(temp==NULL)
        printf("\nThe List is empty\n\n");
    else
    {
        printf("The Node/s is/are--> ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->right;
        }
        printf("\n");
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
		p=p->right;
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
	}
}
