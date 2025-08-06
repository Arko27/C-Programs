#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create_Node(int item);
struct node *first;


struct node *create_Node(int item)
{
    struct node *new_Node;
    new_Node = (struct node *)malloc(sizeof(struct node));	// creating node dynamically
    new_Node->data=item;
    new_Node->next=NULL;
    return new_Node;
}
void AddNode(int item)
{
   struct node *temp, *traverser;
   temp=create_Node(item);
   if(first==NULL)			// checking if the list is empty or not
   {
       first=temp;
   }
   else
   {
       traverser=first;
       while(traverser->next != NULL)
       {
           traverser=traverser->next;
       }
       traverser->next = temp;
   }
}
void insertBegin(int item)
{
    if(first==NULL)
    {
        AddNode(item);
    }
    else
    {
        struct node *temp;
        temp = create_Node(item);
        temp->next=first;
        first=temp;
    }
}
void insertEnd(int item)
{
    struct node *temp;
    struct node *traverser;
    temp=create_Node(item);
    traverser=first;
    while(traverser->next!=NULL)
    {
        traverser=traverser->next;
    }
    traverser->next=temp;
    temp->next=NULL;
}
void insert_At_Posi(int item, int pos)
{
    struct node *temp;
    struct node *traverser;
    temp=create_Node(item);
    int i=1;
    traverser=first;
    while(i<pos-1)
    {
        traverser=traverser->next;
        i++;
    }
    temp->next=traverser->next;
    traverser->next=temp;
}
int del_By_Val(int item)
{
    int info;
    struct node *traverser,*traverser1;
    if(first->data==item)
    {
        info=first->data;
        first=first->next;
        return info;
    }
    else
    {
        traverser=first;
        while(traverser != NULL)			// checking for the last node
        {
            if(traverser->data==item)
            {
                break;
            }
            traverser1=traverser;
            traverser=traverser->next;

        }
        if(traverser==NULL)
        {
            return 0;
        }
        else
        {
            info=traverser->data;
            traverser1->next=traverser->next;
            return info;
        }
    }


}
int countNodes()
{
    int c=0;
    struct node *traverser;
    traverser=first;
    while(traverser!=0)
    {
        c++;					// counting number of nodes
        traverser=traverser->next;
    }
    return c;
}
void display()
{
    struct node *traverser;
    traverser=first;
    while(traverser!=NULL)
    {
        printf("%d ", traverser->data);
        traverser=traverser->next;
    }
}
int main()
{
    int ch, val, val1,val2,pos,val3,pos1,val4,i,k, p,n;
    printf("\nEnter the no.of nodes: ");				//entering no of nodes
    scanf("%d", &n);
    i=0;
    while(i<n)
    {
        printf("\nEnter Data %d : ", i+1);
        scanf("%d", &val);				//Entering the data
        AddNode(val);
        i++;
    }
    start: printf("\n1. Add a node at the beginning");
    printf("\n2. Add a node at the end");
    printf("\n3. Add a node at intermediate position");
    printf("\n4. Delete a node by value ");
    printf("\n5. Count the nodes");
    printf("\n6. Display the list ");
    printf("\n7. EXIT ");
    printf("\nEnter your choice");		// entering user's choice
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
                printf("\nEnter the value to be inserted at beginning");
                scanf("%d", &val2);
                insertBegin(val2);
                display();
                goto start;
        case 2:
                printf("\nEnter the value to be inserted at end");
                scanf("%d", &val3);
                insertEnd(val3);
                display();
                goto start;

        case 3:
                printf("\nEnter the position of insertion");
                scanf("%d", &pos);
                printf("\nEnter the item to be inserted");
                scanf("%d", &val3);
                insert_At_Posi(val3,pos);
                display();
                goto start;
        case 4:
                printf("\nEnter the item to be deleted ");
                scanf("%d", &val4);
                k=del_By_Val(val4);
                if(k==0)
                {
                    printf("\nThe item is not found ");
                }
                else
                {
                    printf("\nThe item deleted is %d ", k);
                    printf("\nThe updated list is ");
                    display();
                }
                goto start;
        case 5:
                p = countNodes();
                printf("\nThe no.of nodes is %d ", p);
                goto start;
        case 6:
                printf("\nThe list is :");
                display();
        case 7:
                break;
        default:
                printf("\nInvalid entry");
    }
}
