//To accept & display array using pointers
#include<stdio.h>
void main()
{
    int n,i,*p;
    printf("enter number of elements in array ");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p+i);
    }
    printf("Given array is \n");
    for(i=0;i<n;i++)
    {
        printf("%d",*(p+i));
    }
}