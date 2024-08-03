//To do addition of 2 matrices 
#include<stdio.h>
#include<conio.h>
int main()
{
    int a[10][10],b[10][10],m,n,i,j;
    printf("enter rows and columns\n");
    scanf("%d %d",&m,&n);
    printf("enter elements in A\n");
    for(i=0;i<m;i++)

    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter elements in B\n");
    for(i=0;i<m;i++)

    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    int c[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("Matrix addition is\n");
    
    for(i=0;i<m;i++)

    {
        for(j=0;j<n;j++)
        {
            printf("%d \t",c[i][j]);
        }
        printf("  \n");
    }

}