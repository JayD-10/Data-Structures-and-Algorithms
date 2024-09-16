//To do operations on double linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}node;
node *create()
{
	node *head=NULL,*p;
	int i,n;
	printf("enter no of nodes\n");
	scanf("%d",&n);
	if(n>0)
	{
		head=(node*)malloc(sizeof(node));
		printf("enter data=\n");
		scanf("%d",&head->data);
		head->next=NULL;
		head->prev=NULL;
		p=head;
		for(i=1;i<n;i++)
		{
			p->next=(node*)malloc(sizeof(node));
			p->next->prev=p;
			p=p->next;
			printf("enter data\n");
			scanf("%d",&p->data);
			p->next=NULL;
		}
		
	}
	return head;
}
void display(node *head)
{
	node *p=head;
	while(p!=NULL)
	{
		printf("---%d---",p->data);
		p=p->next;
	}
}
void display_r(node *head)
{
	node *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	while(p!=NULL)
	{
		printf("--%d--",p->data);
		p=p->prev;
	}
}
int count(node *head)
{
	int cnt=0;
	node *p=head;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;
}
void sort(node *head)
{
	node *p;
	int n=count(head);
	int temp,i,j;
	for(i=1;i<n;i++)
	{
		p=head;
		for(j=0;j<n-i;j++)
		{
			if(p->data < p->next->data)
			{
				temp=p->data;
				p->data=p->next->data;
				p->next->data=temp;
			}
			p=p->next;			
		}
	}
	printf("\n after sorting list\n");
	display_r(head);
}
node *insert_b(node *head)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	printf("enter data=\n");
	scanf("%d",&p->data);
	if(head==NULL)
	{
		p->next=NULL;
		p->prev=NULL;
		head=p;
	}
	else
	{
		p->prev=NULL;
		p->next=head;
		head->prev=p;
		head=p;
	}
	return head;
}
node *insert_e(node *head)
{
	node *p,*q;
	p=(node*)malloc(sizeof(node));
	printf("enter data=\n");
	scanf("%d",&p->data);
	p->next=NULL;
	if(head=NULL)
	{
		p->prev=NULL;
		p->next=NULL;
		head=p;
	}
	else
	{
		q=head;
		while(q->next!=NULL)
			q=q->next;
		p->prev=q;
		q->next=p;
	}
	return head;
}
node *insert_i(node *head)
{
	if(head==NULL)
		printf("insertion not possible");
	else
	{
		node *p,*q;
		int key;
		p=(node*)malloc(sizeof(node));
	printf("enter data=\n");
	scanf("%d",&p->data);
	p->next=NULL;
	q=head;
	printf("enter key\n");
	scanf("%d",&key);
	while(q->data!=key)
	{
		if(q->next!=NULL)
			q=q->next;
		else
		{
			printf("key nit found");
			return head;
		}
	}
	p->next=q->next;
	p->prev=q;
	q->next->prev=p;
	q->next=p;
	}
	return head;
}
int main()
{
	node *head=NULL;
	int n,n1,x,cnt;
	head=create();
	do
	{
		printf("\n------MENU----\n");
		printf("1count \n2 insert elem\n 3 delete \n 4 sort \n 5 display");
		printf("enter ch");
		scanf("%d",&n);
			switch(n)
		{
		
			case 1:
				cnt=count(head);
				printf("no of elem =%d",cnt);
			break;
			case 2:
				printf("1. beg\n 2 end\n 3 middle");
				scanf("%d",&n1);
				switch(n1)
				{
					case 1:
						head=insert_b(head);
						break;
					case 2:
						head=insert_e(head);
						break;
					case 3:
						head=insert_i(head);
						break;
					default:printf("worng ch");
				}
				
			break;
			display(head);
			default:printf("wrong choice");
	    }
	}while(n!=6);
}