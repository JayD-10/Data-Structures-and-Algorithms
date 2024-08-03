//To copy elements of an array into another array
#include<stdio.h>
#include<conio.h>
int main()
{
    int a[30],b[30],i,n;
    printf("enter no of elements\n");
    scanf("%d",&n);
    printf("enter elements of array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    printf("copied array is:\n");
    for(i=0;i<n;i++)
    {
        printf("b[%d] is %d \n",i,b[i]);
    }

}