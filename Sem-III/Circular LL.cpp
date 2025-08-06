#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *add;
};
int main()
{
	int m=0;
	struct node *pre,*prev,*search,*head=0;
	while(1)
	{
		int ch=0;
		printf("\n1. Add Node at End\n2. Display Data\n3. Length\n4. Add Node At Begining\n5. Insert At Any Position\n6. Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d",&ch);
		if(ch == 1)
		{
			pre = (struct node *)malloc(sizeof(struct node));
			printf("\nenter the data:");
			scanf("%d0",&pre->data);
			if(head==0)
			{
				prev= pre;
				head = pre;
				pre->add = head;
			}
			else
			{
				prev->add = pre;
				pre->add = head;
				prev = pre;
			}
			m = m+1;
		}
		else if(ch == 2)
		{
			search = head;
			while(search->add!=head)
			{
				printf("%d\t",search->data);
				search = search->add;
			}
			printf("%d",search->data);
		}
		else if(ch == 3)
		{
			printf("\nThe Length Of The Linked List Is:%d",m);
		}
		else if(ch == 4)
		{
			pre = (struct node *)malloc(sizeof(struct node));
			printf("\nEnter the number:");
			scanf("%d",&pre->data);
			pre->add = head;
			search = head;
			while(search->add!=head)
			{
				search = search->add;
			}
			search->add = pre;
			head = pre;
			m = m+1;
		}
		else if(ch == 5)
		{
			int pos;
			printf("\nenter the position:");
			scanf("%d",&pos);
			if(pos>1 && pos<m+1)
			{
				pre = (struct node *)malloc(sizeof(struct node));
				printf("\nenter the data:");
				scanf("%d",&pre->data);
				search = head;
				for(int i=0;i<pos-2;i++)
				{
					search = search->add;
				}
				pre->add = search->add;
				search->add = pre;
				m = m+1;
			}
			else if(pos>m+1)
			{
				printf("\nWrong position please try again");
			}
		}
		else if(ch == 6)
		{
			printf("Program Terminated");
			break;
		}
	}
}
