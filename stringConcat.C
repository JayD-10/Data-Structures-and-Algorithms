//To concatenate 2 strings
#include<stdio.h>
#include<string.h>
void concatenate(char[],char[]);

    int main()
    {
        char s1[50],s2[30];
        printf("\n enter 2 strings");
        gets(s1);
        gets(s2);
        concatenate(s1,s2);
        printf("\n final string is: %s",s1);
        
    }
    void concatenate(char s1[],char s2[])
    {
        int i,j;
        i=strlen(s1);
        for(j=0;s2[j]!='\0';i++,j++)
        s1[i]=s2[j];
        s1[i]='\0';
    }
