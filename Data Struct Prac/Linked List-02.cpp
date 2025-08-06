#include <stdio.h>
#include <malloc.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
struct Node *tail=NULL;

struct Node *createNode(int item)
{
    struct Node *new_Node;
    new_Node = (struct Node *)malloc(sizeof(struct Node));
    new_Node->data = item;
    new_Node->prev = NULL;
    new_Node->next = NULL;
    return new_Node;
}
void AddNode(int item)
{
    struct Node *temp;
    temp=createNode(item);
    if(head==NULL)
    {
        head=tail=temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void insertBegNode(int item)
{
    struct Node *temp;
    if(head==NULL)
    {
        printf("\nList is Empty ");
    }
    else
    {
        temp=createNode(item);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertEndNode(int item)
{
    struct Node *temp;
    temp=createNode(item);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void insertPosNode(int item, int pos)
{
    struct Node *temp,*traverser;
    temp=createNode(item);
    int i=1;
    traverser=head;
    while(i<pos-1)
    {
        traverser=traverser->next;
        i++;
    }
    temp->prev=traverser;
    temp->next = traverser->next;
    traverser->next=temp;
    temp->next->prev=temp;
}
int del_By_Val(int item)
{
    struct Node *traverser, *traverser1;
    int  info;
    if(head->data == item)
    {
        info=head->data;
        head=head->next;
        head->prev=NULL;
        return info;
    }
    else
    {
        traverser=head;
        while(traverser != NULL)
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
            info = traverser->data;
            traverser1->next = traverser->next;
            traverser->next->prev = traverser1;
            return info;
        }
    }
}
int length()
{
    struct Node *traverser;
    traverser=head;
    int c=0;
    while(traverser!=NULL)
    {
        c++;
        traverser=traverser->next;
    }
    return c;
}
void reverse()
{
    struct Node *prevNode, *currentNode, *nextNode;
    prevNode=NULL;
    currentNode=head;
    nextNode=head;
    while(nextNode!=NULL)
    {
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        currentNode->prev=nextNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    head=prevNode;
}
void display()
{
    struct Node *traverser;
    traverser=head;
    while(traverser->next!=NULL)
    {
        printf("%d ", traverser->data);
        traverser=traverser->next;
    }
    printf("%d ", traverser->data);
}
int main()
{
    int val,val1,val2,ch,val3,p,position,n,i,val4,k;
    printf("\nEnter the no.of nodes ");				
    scanf("%d", &n);				//Read the no.of nodes
    i=0;
    while(i<n)
    {
        printf("\nEnter data %d : ", i+1);
        scanf("%d", &val);
        AddNode(val);				//Initialising the values
        i++;
    }
	start:
	printf("\n1.  Insert at beginning");
	printf("\n2. Insert at end");
    printf("\n3. Insert node at specific position ");
    printf("\n4. Delete a node by value ");
    printf("\n5. Count the nodes ");
    printf("\n6. Inverse the list ");
    printf("\n7. Display the list ");
    printf("\n8. EXIT ");
    printf("\nEnter your choice");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
                printf("\nEnter the item to be inserted in doubly linked list at the beginning");
                scanf("%d", &val1);
                insertBegNode(val1);
                display();
                goto start;
        case 2:
                printf("\nEnter the item to be inserted in doubly linked list at the end");
                scanf("%d", &val2);
                insertEndNode(val2);
                display();
                goto start;
        case 3:
                printf("\nEnter the position of insertion");
                scanf("%d", &p);
                printf("\nEnter the item to be inserted ");
                scanf("%d", &val3);
                insertPosNode(val3,p);
                display();
                goto start;
        case 4:
                 printf("\nEnter the item to be deleted ");
                 scanf("%d", &val4);
                 k=del_By_Val(val4);
                 if(k==0)
                 {
                    printf("\nThe item is not found : ");
                 }
                 else
                 {
                    printf("\nThe item deleted is %d ", k);
                    printf("\nThe updated list is ");
                    display();
                 }
                 goto start;
        case 5:
                p = length();
                printf("\nThe no.of nodes is %d ", p);
                goto start;
        case 6:
                printf("The list after reversing");
                reverse();
                display();
                goto start;
        case 7:
                printf("\nThe list is :");
                display();
                goto start;
        case 8:
                break;
        default:
                printf("Invalid Entry");
    }
}
