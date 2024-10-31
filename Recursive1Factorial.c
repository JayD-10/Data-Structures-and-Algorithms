#include<stdio.h>
#include<conio.h>
int fact(int n)
{
	if(n==1)
		return 1;
	return n*fact(n-1);
}
int main()
{
	int n,ans;
	printf("enter any number\n");
	scanf("%d",&n);
	ans=fact(n);
	printf("factorial of a no.= %d",ans);
}