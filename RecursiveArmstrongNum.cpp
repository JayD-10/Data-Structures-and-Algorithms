//armstrong no
int armstrong(int n, int x)
{
	if(n!=0)
	{
		int a=n%10;
		x=x+(a*a*a);
		armstrong(n/10,x);
	}
	else
	{
		return x;
	}

}
int main()
{
	int n,ans;
	printf("enter a no.\n");
	scanf("%d",&n);
	ans=armstrong(n,0);
	if(n==ans)
		printf("armstrong\n");
	else
		printf("not armstrong");
}