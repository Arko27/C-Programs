#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	int deg;
	struct node *add;
};
int main()
{
	int n,m1,m2;
	struct node *head1=0,*head2=0,*head3=0,*pre,*prev,*fi,*se;
	for(int i=1;i<=2;i++)
	{
		printf("Enter The Higest Degree of %dth Polynomial:",i);
		scanf("%d",&n);
		if(i==1)
			m1 = n+1;
		else if(i==2)
			m2 = n+1;
		for(int j=n;j>=0;j--)
		{
			pre = (struct node *)malloc(sizeof(struct node));
			if(j==0 || j==1)
			{
				if(j==0)
					printf("\nEnter The Constant Term:");
				else
					printf("\nEnter The Co-Efficient Of x:");
			}
			else
					printf("\nEnter The Co-Efficient Of x^%d:",j);
			scanf("%d",&pre->data);
			pre->deg = j;
			pre->add = 0;
			if(i==1)
			{
				if(head1==0)
				{
					head1 = pre;
					prev = pre;
				}
				else
				{
					prev->add = pre;
					prev = pre;
				}
			}
			if(i==2)
			{
				if(head2==0)
				{
					head2 = pre;
					prev = pre;
				}
				else
				{
					prev->add = pre;
					prev = pre;
				}
			}
		}
	}
	printf("\n1st Polynomial Is:-\n");
	prev = head1;
	while(prev!=0)
	{
		if(prev->data>0)
		{
			if(prev->deg==0 || prev->deg==1)
			{
				if(prev->deg==0)
					printf(" + %d ",prev->data);
				else if(prev->deg==1)
					printf(" + %dx ",prev->data);
			}
			else
				printf(" + %dx^%d ",prev->data,prev->deg);
		}
		else if(prev->data<0)
		{
			if(prev->deg==0 || prev->deg==1)
			{
				if(prev->deg==0)
					printf(" %d ",prev->data);
				else if(prev->deg==1)
					printf(" %dx ",prev->data);
			}
			else
				printf(" %dx^%d ",prev->data,prev->deg);
		}
		else if(prev->data==0)
			printf("");
		prev = prev->add;
	}
	printf("\n2nd Polynomial Is:-\n");
	prev = head2;
	while(prev!=0)
	{
		if(prev->data>0)
		{
			if(prev->deg==0 || prev->deg==1)
			{
				if(prev->deg==0)
					printf(" + %d ",prev->data);
				else if(prev->deg==1)
					printf(" + %dx ",prev->data);
			}
			else
				printf(" + %dx^%d ",prev->data,prev->deg);
		}
		else if(prev->data<0)
		{
			if(prev->deg==0 || prev->deg==1)
			{
				if(prev->deg==0)
					printf(" %d ",prev->data);
				else if(prev->deg==1)
					printf(" %dx ",prev->data);
			}
			else
				printf(" %dx^%d ",prev->data,prev->deg);
		}
		else if(prev->data==0)
			printf("");
		prev = prev->add;
	}
	fi = head1;
	while(fi!=0)
	{
		se = head2;
		while(se!=0)
		{
			pre = (struct node *)malloc(sizeof(struct node));
			pre->data = (fi->data) * (se->data);
			pre->deg  = (fi->deg) + (se->deg);
			pre->add = 0;
			if(head3 == 0)
			{
				head3 = pre;
				prev = pre;
			}
			else
			{
				prev->add = pre;
				prev = pre;
			}
			se = se->add;
		}
		fi = fi->add;
	}
	prev = head3;
	while(prev->add!=0)
	{
		pre  =prev->add;
		while(pre!=0)
		{
			if(prev->deg == pre->deg)
			{
				prev->data = (prev->data) + (pre->data);
				fi = head3;
				while(fi->add!=pre)
					fi = fi->add;
				fi->add = pre->add;
			}
			pre = pre->add;
		}
		prev = prev->add;		
	}
	printf("\nResulting Polynomial Is:-\n");
	prev = head3;
	while(prev!=0)
	{
		if(prev->data>0)
		{
			if(prev->deg==0 || prev->deg==1)
			{
				if(prev->deg==0)
					printf(" + %d ",prev->data);
				else if(prev->deg==1)
					printf(" + %dx ",prev->data);
			}
			else
				printf(" + %dx^%d ",prev->data,prev->deg);
		}
		else if(prev->data<0)
		{
			if(prev->deg==0 || prev->deg==1)
			{
				if(prev->deg==0)
					printf(" %d ",prev->data);
				else if(prev->deg==1)
					printf(" %dx ",prev->data);
			}
			else
				printf(" %dx^%d ",prev->data,prev->deg);
		}
		else if(prev->data==0)
			printf("");		
		prev = prev->add;
	}
}
