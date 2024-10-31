#include<stdio.h>
#include<conio.h>
int sum(int n)
{
	if(n!=0)
		return n+sum(n-1);
}
int main()
{
	int n,ans;
	printf("enter any number\n");
	scanf("%d",&n);
	ans=sum(n);
	printf("sum of nos=%d",ans);
}