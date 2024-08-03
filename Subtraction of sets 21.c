//To do subtraction of 2nd set from 1st set
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
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(b[i]==a[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("%d ",b[i]);
        flag=0;
    }
}