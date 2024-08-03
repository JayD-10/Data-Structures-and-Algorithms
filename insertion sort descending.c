//to sort array in descending order
#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,n,temp;
	printf("enter the no. of array elements\n");
	scanf("%d",&n);
	int a[n];
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;a[j]<temp&&j>=0;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
	printf("sorted array is \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}