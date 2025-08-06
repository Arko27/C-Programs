#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *link;
	struct node *prev; 
}nd;
nd *head;
int c=0;
void insertFirst ()
{
 	nd *temp;
 	temp = (nd *)malloc(sizeof (nd));
 	printf ("\nEnter A Number :");
 	scanf ("%d",&temp->data);
 	temp->link = NULL;
 	temp->prev = NULL;
 	if (head == NULL)
 		head = temp;
 	else
	{
		temp->link = head;
		head->prev = temp;
 		head = temp;
	}
}
void insertLast ()
{
 	nd *temp,*ptr;
 	temp = (nd *)malloc (sizeof (nd));
 	printf ("\nEnter A Number :");
 	scanf ("%d",&temp->data);
 	temp->link = NULL;
 	temp->prev = NULL;
 	if (head == NULL)
 		head = temp;
 	else
	{
		ptr = head;
 		while (ptr->link != NULL)
 			ptr = ptr->link;
		ptr->link= temp;
		temp->prev=ptr;
	}	
}
void posInsert()
{
  	int pos,i,length;
  	nd *temp,*ptr;
 	temp = (nd *)malloc (sizeof (nd));
 	printf ("Enter Position in which New Node will be Inserted :");
 	scanf ("%d",&pos);
 	if (pos<0 || pos>c)
 		printf ("Invalid Position!");
 	else
	{
	 	printf ("\nEnter A Number :");
 		scanf ("%d",&temp->data);
 		temp->link = NULL;
 		temp->prev = NULL;
	 	ptr = head;
 		for (i=1;i<pos-1;i++)
 		{
			ptr= ptr->link;
		}
		temp->link = ptr->link;
 		temp->prev = ptr;
 		ptr->link->prev=temp;
 		ptr->link = temp;
 		c++;
	}
}
void display ()
{
	nd *ptr;
  	if (head == NULL)
		printf ("\nList is empty!");
  	else
	{
		ptr = head;
  		while (ptr !=NULL)
  		{
			printf ("%d ",ptr->data);
  			ptr = ptr->link;
		}
	}
}
void delete_begin()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
    	printf("The List is empty");
    else
    {
    	head=head->link;
    	temp->link=NULL;
    	head->prev=NULL;
    	display();
    	c--;
    }
}
void delete_end()
{
    struct node *tail,*temp;
    temp=head;
    if(temp==NULL)
    	printf("The List is empty");
    else
    {
    	while(temp->link!=NULL)
    	{
    		tail=temp;
			temp=temp->link;
		}
    	tail->link=NULL;
    	display();
    	c--;
    }
}
void delete_location()
{
    struct node *temp=head;
    int len,loc,i;
    printf("Enter the location to delete:");
    scanf("%d",&loc);
   if(loc>c)
    {
        printf("Invalid location\n");
    }
    else
    {
        struct node *temp;
        temp=head;
        for(i=1;i<loc-1;i++)
        {
            temp=temp->link;
        }
        temp->link=temp->link->link;
        temp->link->prev=temp;
        display();
        c--;
    }
}
int main()
{
	int choice=1;
    head= NULL;
    printf("1. Insert at beginning\n2. Insert at end\n3. Insert at required position\n4. Length of list\n5. Delete from Begin\n");
	printf("6. Delete from End\n7. Delete from position\n8. Display\n9. Exit");
    while(1)
    {
		printf("\nEnter your choice: ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:
        		insertFirst();
        		c++;
        		break;
    		case 2:
        		insertLast();
        		c++;
        		break;
    		case 3:
        		posInsert();
        		break;
    		case 4:
       			printf("No of Nodes is/are %d",c);
        		break;
    		case 5:
        		delete_begin();
        		break;
        	case 6:
        		delete_end();
        		break;
        	case 7:
        		delete_location();
        		break;
        	case 8:
        		display();
        		break;
    		case 9:
        		exit(1);
     		default : printf ("Wrong Choice!");
    	}
	}
}
