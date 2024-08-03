//To do A-B of 2 sets
#include<stdio.h>
int main()
{
    int m,n,i,j;
    printf("Enter number of elements in 1st array\n");
    scanf("%d",&m);
    printf("Enter number of elements in 2nd array\n");
    scanf("%d",&n);
    int a[m],b[n];
    printf("Enter elemnts in 1st array\n");
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);
    printf("Enter elemnts in 2nd array\n");
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);
    int flag=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("%d ",a[i]);
    }
}