#include<stdio.h>

struct bstNode
{
	struct bstNode *left;
	struct bstNode *right;
	int data;
}

int main()
{
	struct bstNode *root;
	int option;
	root=NULL;
	printf("Enter 1. Insert\n2. Delete\n3. Traverse\n4. Display\n5. Exit\n\n");
	printf("Enter Your Choice: ");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			int value;
			printf("Enter the value to be inserted");
			scanf("%d",&value);
			insert(&root,value);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		
	}
}
int insert(struct bstNode **p,value)	//p ->&root *p ->root
{
	struct bstNode *temp,*ins;
	temp = (struct bstNode *)malloc(sizeof(struct bstNode));
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	
	if(*p == NULL)
		*p = temp;
	else
	{
		ins = traverse(p,value);
		ins->right = temp;
	}
}

struct bstNode *traverse(struct bstNode **p,int value)
{
	struct bstNode *f;
	f = *p;
	if(f->right == NULL)
	{
		printf("\nPosition Found for Insertion");
		return f;
	}
	else
	{
		if(value >= f->data)
			traverse(%(f->right),value);
		else
			f = f->left;
		
		
	}
}
