//to do basic operations on queue
#include<stdio.h>
typedef struct queue
{
	int a[10],f,r;
}queue;
void init(queue *q)
{
	q->f=q->r=-1;
}
int isempty(queue *q)
{
	if(q->r==-1)
		return 1;
	return 0;
}
int isfull(queue *q)
{
	if(q->r==9)
		return 9;
	return 0;
}
void enqueue(queue *q,int x)
{
	if(q->r==-1)
		q->r=q->f=0;
	else
		q->r=q->r+1;
	q->a[q->r]=x;
}
int dequeue(queue *q)
{
	int x=q->a[q->f];
	if(q->a==q->f)
		q->r=q->f=-1;
	else
		q->f=q->f+1;
	return x;
}
void display(queue *q)
{
	int i=q->f;
	if(i==-1)
		printf("Queue is empty!");
	else
	{
		while(i<=q->r)
		{
			printf("%d--",q->a[i]);
			i=i+1;
		}
	}
}
int main()
{
	queue q;
	init(&q);
	int n,x;
	do
	{
		printf("\n----MENU----\n");
		printf("\n 1 enqueue \n 2 dequeue\n 3 display\n enter your choice=\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("enter element=\n");
				scanf("%d",&x);
				if(isfull(&q))
					printf("\n queue is full!");
				else
				enqueue(&q,x);
			break;
			case 2:
				if(isempty(&q))
					printf("queue is empty!");
				else
				{
					x=dequeue(&q);
					printf("\n %d is removed");
				}
			break;
			case 3:
				display(&q);
				break;
			default:printf("wrong choice\n");
			
		}
		
		
	}while(n<=3);
}
