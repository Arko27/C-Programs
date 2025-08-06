#include <stdio.h>
#include<string.h>
#define max 20

void linearSearch(char string[][20], int n, char word[]);
int binSearch(char string[][20],int n,char word[]);
int main()
{
    char string[max][20],t[20],word[20];
    int i, j, n, ch,p;
    printf("Enter the number of Words: \n");
    scanf("%d", &n);
    printf("Enter the words: \n");
    
	for (i = 0; i < n; i++)
    	scanf("%s",string[i]);
    
	printf("\nInput Words: \n");
    for(i = 0; i < n; i++)
         printf("%s\n", string[i]);
    
	printf("\n1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
    	case 1:
        	printf("\nEnter the word to be searched: \n");
            scanf("%s", word);
            linearSearch(string,n,word);
            break;
    	case 2:
    		for(i=0;i<=n;i++)
    		{
    			for(j=i+1;j<=n;j++)
				{
					if(strcmp(string[i],string[j])>0)
					{
						strcpy(t,string[i]);
						strcpy(string[i],string[j]);
						strcpy(string[j],t);
					}
				}
			}
            printf("\nEnter the word to be searched: \n");
            scanf("%s",word);
            p = binSearch(string,n,word);
            if(p==-1)
            	printf("\nSearch Unsuccessful");
    		else
        		printf("\nSearch Successful");
            break;
        default:
        	printf("\nInvalid Entry ");
    }
}

void linearSearch(char string[][20], int n, char word[])
{
    int i, f=0;
    for (i = 0; i < n; i++)
    {
        if((strcasecmp(word, string[i]))== 0)
            f=1;
    }
    if(f == 0)
        printf("\nSearch unsuccessful");
    else
        printf("\nSearch Successful");
}
int binSearch(char string[][20],int n,char word[])
{
    int lb, mid, ub;
    lb = 0;
    ub = n-1;
    while(lb<=ub)
    {
    	mid=lb+(ub-1)/2;
    	int res;
        if (strcasecmp(word,string[mid]) == 0)
        	res = 0;
        if (res == 0)
        	return mid;
        else if (strcasecmp(word,string[mid]) > 0)
        	lb = mid + 1; 
        else
        	ub = mid - 1; 
    }
    return -1;
}
