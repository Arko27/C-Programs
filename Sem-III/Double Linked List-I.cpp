#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
	struct node *prev; 
}nd;

nd *head;
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
int count ()
{
 	int cou=0;
 	nd *ptr;
 	ptr=head;
	while (ptr!=NULL)
	{
		cou ++;
		ptr =ptr->link;
	}
	printf ("\nNumber Of Nodes = %d",cou); 
	return cou;
}
void posInsert()
{
  	int pos,i,length;
  	nd *temp,*ptr;
 	temp = (nd *)malloc (sizeof (nd));
 	printf ("Enter Position in which New Node will be Inserted :");
 	scanf ("%d",&pos);
 	if (pos<0 || pos>count())
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
int main()
{
	int choice=1;
    head= NULL;
    printf("1.Insert at beginning\n2.Insert at end\n3.Insert at required position\n4.Length of list\n5.Display\n6.Exit");
    while(1)
    {
		printf("\nEnter your choice: ");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:
        		insertFirst();
        		break;
    		case 2:
        		insertLast();
        		break;
    		case 3:
        		posInsert();
        		break;
    		case 4:
       			count();
        		break;
    		case 5:
        		display();
        		break;
    		case 6:
        		exit(1);
     		default : printf ("Wrong Choice!");
    	}
	}
}
