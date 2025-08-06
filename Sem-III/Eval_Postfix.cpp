#include <stdio.h>
#include <ctype.h>
#include<Math.h>

#define SSize 100
#define PSize 100

int stack[SSize];
int top = -1;

void push(int item)
{
	if (top>=SSize-1)
	{
		printf("Stack Over Flow");
        return;
    }
    else
	{
		top=top+1;
        stack[top]=item;
    }
}
int pop()
{
    int item;
    if (top<0)
	    printf("Stack Under Flow");
    else
	{
		item=stack[top];
        top=top-1;
        return item;
    }
}
void EvalPostfix(char postfix[])
{
	int i;
    char ch;
    int val;
    int A, B;
    for (i=0;postfix[i]!=')';i++)
	{
        ch=postfix[i];
        if (isdigit(ch))
            push(ch-48);
        else if (ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='^')
		{
			A = pop();
            B = pop();
            switch (ch)
            {
            	case '*':
                	val = B * A;
                	break;
            	case '/':
                	val = B / A;
                	break;
            	case '+':
                	val = B + A;
                	break;
            	case '-':
                	val = B - A;
                	break;
                case '^':
                	val = pow(B,A);
                	break;
                case '%':
                	val = B%A;
                	break;
            }
            push(val);
        }
    }
    printf("\nResult of expression evaluation: %d \n", pop());
}
int main()
{
	int i;
    char postfix[PSize];
    printf("Enter Postfix Expression & press ')' for End Expression:\n");
    for (i=0;i<=PSize-1;i++)
	{
		scanf("%c",&postfix[i]);
        if(postfix[i]==')')
        	break;
    }
    EvalPostfix(postfix);
    return 0;
}
