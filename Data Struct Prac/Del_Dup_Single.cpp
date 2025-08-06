#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
}*root=NULL;
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
		printf("\nThe List is empty\n");
	else
	{
		printf("The data/s is/are---> ");
		while(ptr->link!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
		printf("%d ",ptr->data);
	}
	printf("\n\n");
}
void del_dup()
{
	struct node *current,*index,*temp;
	current=root;
    if(current==NULL)
		printf("\nThe List is Empty\n");  
    else
	{
		while(current!=NULL)
		{
			temp=current;
            index=current->link;  
            while(index!=NULL)
			{
				if(current->data==index->data)
                    temp->link=index->link;  
                else
                	temp=index;
                index=index->link;  
            }
            current=current->link;
        }
        printf("\n---Duplicate Nodes Deleted Succesfully---\n\n");
        display();
    }
}
int main()
{
	int ch;
	start:
	printf("1. Append Node\n2. Delete Duplicate Elements\n3. Display\n4. Exit\n");
	printf("Enter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			append_end();
			goto start;
		case 2:
			del_dup();
			goto start;
		case 3:
			display();
			goto start;
		case 4:
			printf("\n---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
			goto start;
	}
}
