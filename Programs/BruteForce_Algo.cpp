#include <stdio.h>
#include <malloc.h>
#define max 25
int x;
int top;
void push();
struct no_stack
{
    int stack[max];
    int capacity;
    int top;
};
struct no_stack *createStack(int);
int main()
{
    int size, i, j,sum=0,k, c=0, gen, fake, diff=0;
    printf("\nEnter the number of stacks :");
    scanf("%d", &size);
    printf("\nEnter the weight of genuine coins : ");
    scanf("%d", &gen);
    printf("\nEnter the weight of counter feit coins : ");
    scanf("%d", &fake);
    int arr[max];
    struct no_stack *Stack[max];
    for(i=0;i<size;i++)
    {
        Stack[i] = NULL;
    }
    for(i=0;i<size;i++)
    {
      Stack[i] = createStack(size);
      printf("\nEnter the weight of coins in Stack{%d}", i+1);
      for(j=0;j<size;j++)
      {
          push(Stack[i]);
      }
    }
    for(i=0;i<size;i+=2)
    {
        if(i == size-1)
        {
             printf("\n---->Stack{%d} is the counterfeit ", i+1);
             break;
        }
        else if(Stack[i]->stack[top] == Stack[i+1]->stack[top])
        {
            c+=1;
            continue;
        }
        else
        {
            c +=1;
            if(Stack[i]->stack[top] == 11)
            {
                printf("\n---->Stack{%d} is the counterfeit ", i+1);
                break;
            }
            else
            {
                 printf("\n---->Stack{%d} is the counterfeit ", i+2);
                 break;
            }
        }
    }
    printf("\n----->minimum weights needed to get the counterfeit stack is is %d ", c);
}
struct no_stack *createStack(int n)
{
    struct no_stack *temp;
    temp = (struct no_stack *)malloc(sizeof(struct no_stack));
    temp->capacity = n;
    temp->top = -1;
    return temp;
};
void push(struct no_stack *temp)
{
    if(temp->top >temp->capacity-1)
    {
        printf("\n\tSTACK is over flow");

    }
    else
    {
        printf("\nEnter a coin weight to be pushed:");
        scanf("%d",&x);
        temp->top = temp->top + 1;
        temp->stack[temp->top]=x;
    }
}
