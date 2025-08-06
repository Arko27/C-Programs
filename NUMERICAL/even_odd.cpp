//Print all even or odd numbers upto 100 acc to user's choice and print the sum

#include<stdio.h>

int main()
{
	int ch,s=0,i;
	printf("Enter 1 to print even and 2 to print odd: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("The even nos are-->\n");
			for(i=0;i<=100;i++)
			{
				if(i%2==0)
				{
					printf("\n%d",i);
					s=s+i;
				}
			}
			printf("\nThe sum of even nos. is %d",s);
			break;
		case 2:
			printf("The odd nos are-->\n");
			for(i=0;i<=100;i++)
			{
				if(i%2!=0)
				{
					printf("\n%d",i);
					s=s+i;
				}
			}
			printf("\nThe sum of odd nos. is %d",s);
			break;
		default:
			printf("Wrong Choice");
	}
}

