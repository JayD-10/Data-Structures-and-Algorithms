//To perform stack menu driven operations
#include<stdio.h>
typedef struct stack
{
    int a[10];
    int top;
}stack;
void init(stack *p)
{
    p->top=-1;
}
int isfull(stack *p)
{
    if(p->top==9)
    {
        return 1;
    }
    return 0;
}
int isempty(stack *p)
{
    if(p->top==-1)
    {
        return 1;
    }
    return 0;
}
void push(stack *p,int x)
{
    p->top=p->top+1;
    p->a[p->top]=x;
}
int pop(stack *p)
{
    int x=p->a[p->top];
    p->top=p->top-1;
    return x;
}
void display(stack *p)
{
    int i=0;
    while(i<=p->top)
    {
        printf("<-%d->",p->a[i]);
        i++;
    }
}
int main()
{
    int n,x;
    stack s;
    init(&s);
    do
    {
        printf("\n---------------MENU-----------------\n");
        printf("1. Push\n 2 POP\n 3.display\n enter your choice");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            if(isfull(&s))
            printf("stack is full!");
            else
            {
                printf("enter eleemnts\n");
                scanf("%d",&x);
                push(&s,x);
            }
            break;
            case 2:
            if(isempty(&s))
             {
                printf("stack empty");
             }
            else
            {
                x=pop(&s);
                printf("\n %d is popped",x);
            }
            break;
            case 3:
            display(&s);
            break;
            default:
            printf("wrong choice");

        }
    }while(n<=3);
}