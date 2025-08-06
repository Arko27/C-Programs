#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *add;
};

int main()
{
    int m=0,ch,li;
    struct node *head=0,*prev,*pre,*search;
    printf("1. Adding a Node at the End\n2. Deleting a Node\n3. No of Nodes\n4. Display the datas\n5. Add a node at Beginning\n");
	printf("6. Add Intermediate Node\n7. Delete from Starting\n8. Delete from given position\n9. Delete by value\n");
	printf("10. Search a No\n11. Sort the List\n12. Exit\n"); 
    while(1)
    {
		printf("\nEnter your choice: ");
        scanf("%d",&ch);
        if(ch == 1)
        {
			pre = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter the Data:");
            scanf("%d",& pre->data);
            if(head==0)
            {
                head= pre;
            }
            else
            {
                prev->add = pre;
            }
            prev = pre; 
            pre->add = 0;  
            m = m+1;            
        }
        else if(ch == 2)
        {
           if(m==0)
           {
               printf("\nWe cant delete item as no node is created\n");
           }
           else
           {
               search = head;
               for(int i=0;i<m-2;i++)
               {
                   search =search->add;
               }
               search->add = 0;
               m = m-1;

           }
        }
        else if(ch==3)
        {
            printf("\nNumber of node present is:%d\n",m);
        }
        else if(ch==4)
        {
            search = head;
            printf("\nThe data is:");
            for(int i=0;i<m;i++)
            {
                printf("%d ",search->data);
                search = search->add;
            }
            printf("\n");
        }
        else if(ch == 5)
        {
            pre = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter the data:");
            scanf("%d",&pre->data);
            pre->add = head;
            head = pre;
            m = m+1;
            printf("\n");
        }
        else if(ch == 6)
        {
            //addintermediate
            int pos;
            printf("\nEnter the position(should be between 1 to %d):",m+1);
            scanf("%d",&pos);
            pre=(struct node *)malloc(sizeof(struct node));
            search = head;
            for(int i=0;i<pos-2;i++)
            {
                search = search->add;
            }
            printf("\nEnter the data:");
            scanf("%d",&pre->data);
            pre->add = search->add;
            search->add = pre;
            m = m+1;
            printf("\n");
        }
        else if(ch == 7)
		{
			//delete from starting
			head = head->add;
			m = m-1;
			printf("\n");	
		}
		else if(ch == 8)
		{
			//delete by position
			int position;
			struct node *p;
			printf("\nEnter the position:");
			scanf("%d",&position);
			search = head;
			for(int i=0;i<position-2;i++)
			{
				search = search->add;
			}
			p = search;
			search = head;
			for(int i=0;i<position-1;i++)
			{
				search=search->add;
			}
			p->add = search->add;
			
			m =m-1;
			printf("\n");
		}
		else if(ch == 9)
		{
			//delete by value
			int num;
			struct node *p;
			printf("\nEnter the value:");
			scanf("%d",&num);
			search = head;
			while(search->data!=num)
			{
				search = search->add;
			}
			p = search;
			search = head;
			while(search->add!=p)
			{
				search = search->add;
			}
			search->add = p->add;
			
			m = m-1;
			printf("\n");
		}											
		else if(ch == 10)
		{
			int num,f=0;
			printf("\nEnter the No:");
			scanf("%d",&num);
			search = head;
			for(int i=0;i<m;i++)
			{
				if(search->data == num)
				{
					f= 1;
					break;
				}
				else
				{
					f = 0;
				}
				search = search->add;
			}
			if(f == 1)
			{
				printf("\nNo found!");
			}
			else
			{
				printf("\nNumber not found!");
			}
		}
		else if(ch == 11)
		{
			int a[m];
			search = head;
			for(int i=0;i<m;i++)
			{
				a[i] = search->data;
				search = search->add;
			//	printf("0");
			}
			for(int i=0;i<m;i++)
			{
				for(int j=i+1;j<m;j++)
				{
					if(a[i]>a[j])
					{
						//	printf("0");
						int c=0;
						c = a[i];
						a[i] = a[j];
						a[j] = c;
					}
				}
			}
			search = head;
			for(int i=0;i<m;i++)
			{
				//printf("0");
				search->data = a[i];
				search = search->add;
			}
		}
		else if(ch == 0)
		{
			printf("1. Adding a Node at the End\n2. Deleting a Node\n3. No of Nodes\n4. Display the datas\n5. Add a node at Beginning\n");
			printf("6. Add Intermediate Node\n7. Delete from Starting\n8. Delete from given position\n9. Delete by value\n");
			printf("10. Search a No\n11. Sort the List\n12. Exit\n"); 
		}
        else if(ch==12)
            break;
        else
        {
        	printf("\nWrong choice!");
        	continue;
		}
	}
}
