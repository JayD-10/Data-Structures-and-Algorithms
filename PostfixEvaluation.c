//To implement postfix evaluation
#include<stdio.h>
#include<string.h>
typedef struct stack
{
	int data[20];
	int top;
}stack;
int evaluate(char x,int op1,int op2)
{
	if(x=='+')
		return (op1+op2);
	if(x=='-')
		return (op1-op2);
	if(x=='/')
		return (op1/op2);
	if(x=='*')
		return(op1*op2);
	if(x=='%')
		return(op1%op2);
}
void init(stack *s)
{
	s->top-1;
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
void push(stack *s,int x)
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
int main()
{
	char str[20];
	stack s;
	char x;
	int op1,op2,val,n,i;
	init(&s);
	printf("enter the expression:\n");
	gets(str);
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		x=str[i];
		if(isdigit(x))
			push(&s,x-48);
		else
		{
			op2=pop(&s);
			op1=pop(&s);
			val=evaluate(x,op1,op2);
			push(&s,val);
		}
	}
	val=pop(&s);
	printf("\n value pf expression=%d",val);
}
