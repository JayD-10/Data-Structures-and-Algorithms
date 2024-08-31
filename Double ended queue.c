//To perform double ended queue operations
#include<stdio.h>
#include<conio.h>
typedef struct Queue
{
	int a[10];
	int F,R;
}Queue;
void init(Queue *P)
{
	P->F=P->R=-1;
}
int isempty(Queue *P)
{
	if(P->R==-1)
		return 1;
	return 0;
}
void enqueueF(Queue *P)
{
	if(P->F==0)
		printf("queue is full");
	else
	{
		int x;
		printf("enter elem to be inserted\n");
		scanf("%d",&x);
		if(P->F==-1)
			P->F=P->R=0;
		else
		{
			P->F=P->F-1;
		}
	    P->a[P->F]=x;
		
	}
	
}
void enqueueR(Queue *P)
{
	if(P->R==9)
		printf("Queue is full\n");
	else
	{
		int x;
		printf("enter the element\"");
		scanf("%d",&x);
		if(P->R==-1)
			P->R=P->F=0;
		else
			P->R=P->R+1;
		P->a[P->R]=x;
	}
}
void dequeueF(Queue *P)
{
	int x=P->a[P->F];
	if(P->F==P->R)
		P->F=P->R=-1;
	else
		P->F=P->F+1;
		printf("%d is removed",x);
}
void dequeueR(Queue *P)
{
	int x=P->a[P->R];
	if(P->F==P->R)
		P->F=P->R=-1;
	else
		P->R=P->R-1;
	printf("%d is removed\n",x);
}
void display(Queue *P)
{
	int i=P->F;
	while(i<=P->R)
	{
		printf("<-%d->",P->a[i]);
		i++;
	}	
}
int main()
{
	int n;
	Queue Q;
	init(&Q);
	do
	{
		printf("\n---MENU---");
		printf("\n 1.EnqueueF\n 2.EnqueueR\n3.DequeueF\n 4.DequeueR\n5 enter your choice");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				enqueueF(&Q);
			break;
			case 2:
				enqueueR(&Q);
			break;
		    case 3:
		    	if(isempty(&Q))
		        printf("queue is empty");
		    	else
		    		dequeueF(&Q);
		    break;
		    case 4:
		    	if(isempty(&Q))
		    		printf("Queue is empty");
		    	else
		    		dequeueR(&Q);
		    break;
		    case 5:
		    	display(&Q);
		    default:printf("wrong choice");
		}
	}while(n<=5);
}



