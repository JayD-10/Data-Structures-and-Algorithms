//Conversion of infix to postfix
#include<stdio.h>
#include<ctype.h>
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
void infix_to_postfix(char infix[],char postfix[])
{
	stack s;
	char x;
	int i,j=0;
	char token;
	init(&s);
	for(i=0;infix[i]!='\0';i++)
	{
		token=infix[i];
		if(isalnum(token))
			postfix[j++]=token;
		else if(token=='(')
			push(&s,token);
		else if(token==')')
		{
			while((x=pop(&s))!='(')
				postfix[j++]=x;
		}
		else
		{
			while(precedence(token)<=precedence(top(&s))&&!isempty(&s))
			{
				x=pop(&s);
				postfix[j++]=x;
			}
			push(&s,token);
		}
	}
	while(!isempty(&s))
	{
		x=pop(&s);
		postfix[j++]=x;
	}
	postfix[j]='\0';
}
int main()
{
	char infix[30],postfix[30];
	printf("enter an infix expression: \n");
	gets(infix);
	infix_to_postfix(infix,postfix);
	printf("postfix: %s",postfix);
}