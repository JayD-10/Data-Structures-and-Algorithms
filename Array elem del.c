//To delete an element in the array
#include<stdio.h>
#include<conio.h>
int main()
{
    int a[30],n,i,j;
    printf("Enter no of elements\n");
    scanf("%d",&n);
    printf("enter elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter location of the element to be deleted:\n");
    scanf("%d",&j);
    while(j<n)
    {
        a[j-1]=a[j];
        j++;
    }
    n--;
    for(i=0;i<n;i++)
    printf("%d  \n",a[i]);
    
}