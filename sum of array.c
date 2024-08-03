#include<stdio.h>
#include<conio.h>
void main()
{
    int i,sum,n;
    printf("enter no. of elements\n");
    scanf("%d",&n);
    int a[n];
    printf("enter elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    printf("sum=%d",sum);
    
}