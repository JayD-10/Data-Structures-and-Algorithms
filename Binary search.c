//to perform binary search
#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,m,flag=0,n;
	printf("enter the no. of array elements\n");
	scanf("%d",&n);
	int a[n];
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	i=0;
	j=n-1;
	printf("enter the element to be searched\n");
	int key;
	scanf("%d",&key);
	while(i<=j)
	{
		m=(i+j)/2;
		if(key==a[m])
		{
			flag=1;
			break;
		}
		else if(key>a[m])
		{
			i=m+1;
		}
		else
		{
			j=m-1;
		}
	}
		if(flag==1)	
		{
			printf("element found at position %d \n",m+1);
		}
		else
		{
			printf("element not found\n");
		}
	}
