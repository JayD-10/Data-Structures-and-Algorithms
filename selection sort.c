#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,m,flag=0,n,k,temp;
	printf("enter the no. of array elements\n");
	scanf("%d",&n);
	int a[n];
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k])
			k=j;
		}
		if(i!=k)
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
	printf("sorted array \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}