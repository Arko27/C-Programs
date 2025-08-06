#include<stdio.h>
#define size 10
int stack[size],top=-1,n;
void push()
{
	if(top==n-1)
		printf("\nStack Overflow\n");
	else
	{
		printf("Enter the data: ");
		top++;
		scanf("%d",&stack[top]);
		printf("\n");
	}
}
void pop()
{
	if(top==-1)
		printf("\nStack Underflow\n");
	else
	{
		printf("\nThe Popped Data is: %d\n",stack[top]);
		top--;
	}
}
void count()
{
	int i,c=0;
	if(top==-1)
		printf("\nThe Stack is Empty\n");
	else
	{
		for(i=top;i>=0;i--)
			c++;
		printf("\nThere are %d Elements in the Stack\n",c);
	}
}
void display()
{
	int i;
	if(top==-1)
		printf("\nThe Stack is Empty\n");
	else
	{
		printf("\nThe Elements in the Stack are-->\n");
		for(i=top;i>=0;i--)
			printf("%d\n",stack[i]);
		printf("\n");
	}
}
int main()
{
	int ch;
	printf("Enter the size of the Stack: ");
	scanf("%d",&n);
	start:
	printf("1. Push\n2. Pop\n3. Display\n4. Count\n5. Exit\n");
	printf("\nEnter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			push();
			goto start;
		case 2:
			pop();
			goto start;
		case 3:
			display();
			goto start;
		case 4:
			count();
			goto start;
		case 5:
			printf("---Program Terminated---");
			break;
		default:
			printf("Wrong Choice");
	}
}
