#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int reverse(int n,int x)
{
	if(n!=0)
	{
		x=x*10+n%10;
		reverse(n/10,x);
	}
	else
		return x;
}
int main()
{
	int n,ans;
	printf("enter a no.\n");
	scanf("%d",&n);
	ans=reverse(n,0);
	if(ans==n)
		printf("palindrome no");
	else
		printf("not palindrome no");
}