#include<stdio.h>
#include<conio.h>
int product(int n)
{
	if(n!=1)
	{
		return n*product(n-1);
	}
}
int main()
{
	int n,ans;
	printf("enter any no\n");
	scanf("%d",&n);
	ans=product(n);
	printf("product of n nos= %d",ans);
}