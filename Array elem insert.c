//To insertion of an element at the specified location
#include<stdio.h>
#include<conio.h>
int main()
{
    int n,i,loc,a[30],x;
    printf("\n enter no of elements:\n");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter element to be inserted\n");
    scanf("%d",&x);
    printf("enter element loc\n");
    scanf("%d",&loc);
    for(i=n-1;i>=loc-1;i--)
    {
        a[i+1]=a[i];
    }
    n++;
    a[loc-1]=x;
    for(i=0;i<n;i++)
    {
        printf("\n %d",a[i]);
    }

}