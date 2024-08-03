//To find substring 
#include<stdio.h>
#include<string.h>
int search(char[],char[]);
void main()
{
	char a[100],b[40];
	int loc;
	printf("\n enter the main string:");
	gets(a);
	printf("\n enter the search string:\n");
	gets(b);
	loc=search(a,b);
	if(loc==-1)
		printf("\n not found");
	else
		printf("\n found at location %d",loc+1);
	
}
	int search(char a[],char b[])
	{
		int i,j,k;
		i=0;j=0;
		while(a[i]!='\0')
		{
			i++;
			while(a[i]!=b[0]&&a[i]!='\0')
				i++;
			if(a[i]=='\0')
			return -1;
			k=i;
			while(a[i]==b[j]&&a[i]!='\0'&&b[j]!=0)
			{
				i++;
				j++;
			}
			if(b[j]=='\0')
				return(k);
			if(a[i]=='\0')
			{
				return(-1);
			}
			i=k+1;
			j=0;
		}
		
	}
