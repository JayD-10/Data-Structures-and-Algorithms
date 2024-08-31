//Infix to prefix
#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct stack
{
	int data[20];
	int top;
}stack;
int precedence(char x)
{
	if(x=='(')
		return 0;
	if(x=='+'||x=='-')
		return 1;
	if(x='*'||x=='/'||x=='%')
		return 2;
	return 3;
}
void init(stack *s)
{
	s->top=-1;
}
int isempty(stack *s)
{
	if(s->top==-1)
		return 1;
	return 0;
}
int isfull(stack *s)
{
	if(s->top==19)
		return 1;
	return 0;
}
void push(stack *s,char x)
{
	s->top++;
	s->data[s->top]=x;
}
int pop(stack *s)
{
	int x;
	x=s->data[s->top];
	s->top--;
	return x;
}
int top(stack *s)
{
	return s->data[s->top];
}
void infix_to_prefix(char infix[],char prefix[])
{
	stack s;
	char x,temp,token;
	int i,j,n;
	init(&s);
	n=strlen(infix);
	for(i=0,j=n-1;i<j;i++,j--)
	{
		temp=infix[i];
		infix[i]=infix[j];
		infix[j]=temp;
	}
	for(i=0;i<n;i++)
	{
		if(infix[i]=='(')
			infix[i]=')';
		else if(infix[i]==')')
			infix[i]='(';
		
	}

	j=0;
	for(i=0;infix[i]!='\0';i++)
	{
		token=infix[i];
		if(isalnum(token))
			prefix[j++]=token;
		else if(token=='(')
			push(&s,token);
		else if(token==')')
		{
			while((x=pop(&s)) !='(')
				prefix[j++]=x;
		}
		else
		{
			while(precedence(token)<=precedence(top(&s))&& !isempty(&s))
			{
				x=pop(&s);
				prefix[j++]=x;
			}
			push(&s,token);
		}
	}
	while(!isempty(&s))
	{
		x=pop(&s);
		prefix[j++]=x;
	}
	prefix[j]='\0';
	n=strlen(prefix);
	for(i=0,j=n-1;i<j;i++,j--)
	{
		temp=prefix[i];
		prefix[i]=prefix[j];
		prefix[j]=temp;
	}
}
int main()
{
	char infix[30],prefix[30];
	printf("enter infix expression:\n");
	gets(infix);
	infix_to_prefix(infix,prefix);
	printf("prefix = %s",prefix);
}
