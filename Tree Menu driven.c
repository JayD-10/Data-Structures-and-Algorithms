//menu driven program of tree
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node*left;
	struct node*right;

}node;
node *create()
{
	node *p;
	int x;
	printf("\n enter data(-1 for null)");
	scanf("%d",&x);
	if(x==-1)
		return NULL;
	p=(node*)malloc(sizeof(node));
	p->data=x;
	printf("enter left child of %d",x);
	p->left=create();
	printf("enter right child of %d",x);
	p->right=create();
	return p;
}
typedef struct stack
{
	int data[20];
	int top;
}stack;
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
void pre_non_recursive(node *T)
{
	stack s;
	init(&s);
	while(T!=NULL)
	{
		printf("%d\n ",T->data);
		push(&s,T);
		T=T->left;
	}
	while(!isempty(&s))
	{
		T=pop(&s);
		T=T->right;
		while(T!=NULL)
		{
		printf("%d\n ",T->data);
		push(&s,T);
		T=T->left;
		}
	}
}
void in_non_recursive(node *T)
{
	stack s;
	init(&s);
	while(T!=NULL)
	{
		push(&s,T);
		T=T->left;
	}
	while(!isempty(&s))
	{
		T=pop(&s);
		printf("%d \n",T->data);
		T=T->right;
		while(T!=NULL)
		{
		push(&s,T);
		T=T->left;
		}
	}
}
void post_non_recursive(node *T)
{
	stack s,s1;
	init(&s);
	init(&s1);
	while(T!=NULL)
	{
		push(&s,T);
		push(&s,NULL);
		T=T->left;
	}
	while(!isempty(&s))
	{
		T=pop(&s);
		if(pop(&s1)==NULL)
		{
			push(&s,T);
			push(&s1,(node*)1);
			T=T->right;
			while(T!=NULL)
			{
				push(&s,T);
				push(&s,NULL);
				T=T->left;
			}	
		}
		else
		{
			printf("\n %d",T->data);
			
		}
	}
}
void preorder(node *t)
{
	if(t!=NULL)
	{
		printf("--%d--",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
void inorder(node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("--%d--",t->data);
		inorder(t->right);
	}
}
void postorder(node *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("--%d--",t->data);	
	}
}
int countleaf(node *T)
{
	int i;
	if(T==NULL)
		return 0;
	if(T->left==NULL&&T->right==NULL)
	{
		return 1;
	}
	i=countleaf(T->left)+countleaf(T->right);
	return i;
}
int count1(node *T)
{
	int i;
	if(T==NULL)
		return 0;
	if(T->left==NULL&&T->right==NULL)
	{
		return 0;
	}
	if(T->left==NULL || T->right==NULL)
	{
		i=1+count1(T->left)+count1(T->right);
		return i;
	}
	i=count1(T->left)+count1(T->right);
	return i;
}
int count2(node *T)
{
	int i;
	if(T==NULL)
		return 0;
	if(T->left==NULL&&T->right==NULL)
	{
		return 0;
	}
	if(T->left==NULL || T->right==NULL)
	{
		i=1+count2(T->left)+count2(T->right);
		return i;
	}
	i=1+count1(T->left)+count1(T->right);
	return i;
	
}
int count(node *T)
{
	if(T==NULL)
		return 0;
	int i=1+count(T->left)+count(T->right);
	return i;
}
int main()
{
	node *tree=NULL;
	int i1,i,x,n,a,b,c,i2,i3;
	tree=create();
	do
	{
		printf("1 pre 2 inorder 3 postorder 4 count,count leaf,count of degree1,count of degree1 ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				preorder(tree);
				pre_non_recursive(tree);
			break;
			case 2:
				inorder(tree);
				in_non_recursive(tree);
			break;
			case 3:
				postorder(tree);
				post_non_recursive(tree);
			break;
			case 4:
				i1=count(tree);
				i=countleaf(tree);
				i2=count1(tree);
				i3=count2(tree);
				printf("node=%d",i1,"\nleaf nodes=%d",i,"\n leaf nodes deg 1",i2,"leaf nodes deg 2=%d",i3);
			default:printf("wrong ch");
		}
	}while(n!=5);
}