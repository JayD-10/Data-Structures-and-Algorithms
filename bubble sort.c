//To perform bubble sorting
#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter number of elemnts in array \n");
    scanf("%d",&n);
    int a[n],temp;
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
            cnt++;
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
            
            
        }
        if (cnt==0)
        break;
    }

printf("Sorted array is \n");
for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}