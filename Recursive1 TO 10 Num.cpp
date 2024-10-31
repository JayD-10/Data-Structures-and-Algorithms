//print no 1 to 10
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main()
{
	static int i=1;
	if(i<=10)
	{
		printf("\n %d",i);
		i++;
		main();
	}
}