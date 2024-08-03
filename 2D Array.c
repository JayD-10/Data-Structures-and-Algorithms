//To show the use of 2D array
#include<stdio.h>
#include<conio.h>
int main()
{
    int a[10][10],m,n,i,j;
    printf("enter rows and columns\n");
    scanf("%d %d",&m,&n);
    printf("enter elements\n");
    for(i=0;i<m;i++)

    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("2d array is \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }
    printf("transpose is \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t",a[j][i]);
        }
        printf("\n");
    }

    int sum=0;
    for(i=1;i<m;i++)
    {
        for(j=0;j<i;j++)
        {
            sum=sum+a[i][j];
        }
    }
    printf("Sum of lower triangle is %d \n",sum);
    int sum1=1;
    for(i=0;i<m;i++)
    {
        sum1=sum1*a[i][i];
    }
    printf("prod of diagonal elements is %d \n",sum1);
    sum=0;
    for(i=0;i<m-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            sum=sum+a[i][j];
        }
    }
    printf("sum of elements of upper triangle %d",sum);
}