//To reverse a string
#include<stdio.h>
#include<string.h>
void main()
{
    char s[100],temp;
    int i,j=0;
    printf("\n enter the string");
    gets(s);
    i=0;
    j=strlen(s)-1;
    while(i<j)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;

    }
    printf("\n reverse string is %s",s);
    getch();
    
}