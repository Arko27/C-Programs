#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root=NULL;
int c=0;
void append_end()
{
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter the node data: ");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        p=root;
        while(p->right!=NULL)
            p=p->right;
        p->right=temp;
        temp->left=p;
    }
    printf("\n---Node created Succesfully---\n\n");
}
append_begin()
{
	struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data: ");
    scanf("%d",&temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        p=root;
        temp->right=p;
        p->left=temp;
        root=temp;
    }
    printf("\n---Node created Succesfully---\n\n");
}
append_pos()
{
	struct node *temp,*p;
	int pos,i;
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
		c++;
	}
	else
		printf("\nInvalid Input\n");
}
void display()
{
    struct node *temp=root;
    if(temp==NULL)
        printf("\nThe List is empty");
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
void del_end()
{
	struct node *temp,*ptr;
	temp=root;
	if(temp==NULL)
		printf("\nThe List is already Empty");
	else
	{
		while(temp->right!=NULL)
		{
			ptr=temp;
			temp=temp->right;
		}
		ptr->right=NULL;
		c--;
	}
}
void del_begin()
{
	struct node *temp,*ptr;
	ptr=root;
	if(ptr==NULL)
		printf("\nThe List is already Empty");
	else
	{
		temp=ptr->right;
		temp->left=NULL;
		root=temp;
		c--;
	}
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
		printf("The List is Empty");
	}
	else
	{
		if(ptr->left==NULL && ptr->right==NULL && ptr->data==val)
		{
			root=NULL;
			printf("\n---Node deleted Succesfully---\n\n");
			c--;
		}
		else
		{
			while(ptr->data!=val)
				ptr=ptr->right;
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
				c--;
			}
		}
	}
}
/*void search()
{
	
}*/
int main()
{
	int ch;
	start:
	printf("1. Append Node at End\n2. Append Node at Beginning\n3. Append Node at Position\n4. Display Nodes\n");
	printf("5. Length of the List\n6. Delete from End\n7. Delete from Beginning\n8. Delete Duplicate Elements\n");
	printf("9. Delete by Value\n10. Sort the List\n11. Reverse the List\n12. Search Data\n13. Exit\n");
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
			display();
			goto start;
		case 5:
			printf("\nThe Length of the Linked List is %d\n",c);
			goto start;
		case 6:
			del_end();
			goto start;
		case 7:
			del_begin();
			goto start;
		/*case 8:
			del_dup();
			c--;
			goto start;*/
		case 9:
			del_val();
			goto start;
		/*case 10:
			sort();
			goto start;
		case 11:
			reverse();
			goto start;
		case 12:
			search();
			goto start;*/
		case 13:
			printf("\n---Program Terminated---");
			break;
	}
}
