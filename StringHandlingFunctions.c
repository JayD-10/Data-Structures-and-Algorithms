//To use of string handling functions
#include<string.h>
#include<stdio.h>
#include<conio.h>
int main()
{
    char s1[30],s2[30];
    int l1,l2;
    printf("enter the string: \n");
    gets(s1);
    l1=strlen(s1);
    printf("length of string %s=%d\n",s1,l1);
    strcpy(s2,s1);
    printf("1st string=%s\n",s1);
    printf("2nd string=%s\n",s2);
    l1=strcmp(s1,s2);
    printf("comparison of string=%d\n",l1);
    strcat(s1,s2);
    printf("after concatenation= %s\n",s1);
}