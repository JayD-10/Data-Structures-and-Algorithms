#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *create()
{
	node *head=NULL,*p;
	int i,n,x;
	printf("enter no of nodes=\n");
	scanf("%d",&n);
	head=(node*)malloc(sizeof(node));
	printf("enter data\n");
	scanf("%d",&x);
	head->data=x;
	head->next=head;
	//making single node for initilaising LL
	//starting from 1 as 1 node is already created
	for(i=1;i<n;i++)
	{
		p=(node*)malloc(sizeof(node));
			printf("enter data\n");
	        scanf("%d",&x);
	        p->data=x;
	        p->next=head->next;
	        head->next=p;
	        head=p;
	        //head should be on last node so this statement
	        
	}
	return head;
}
void display(node *head)
{
	node *p;
	p=head->next;
	//using do while to print all nodes properly
	do
	{
		printf("--%d--",p->data);
		p=p->next;
		//used like i++
		
	}while(p!=head->next);
}
int count(node *head)
{
	int cnt=0;
	node *p=head->next;
	do
	{
		cnt++;
		p=p->next;
		
	}while(p!=head->next);
	return cnt;
}
void sort(node *head)
{
	node *p;
	int n=count(head);
	int temp,i,j;
	for(i=1;i<n;i++)
	{
		p=head->next;
		for(j=0;j<n-i;j++)
		{
			if(p->data > p->next->data)
			{
				temp=p->data;
				p->data=p->next->data;
				p->next->data=temp;
			}
			p=p->next;
		}
	}
	printf("\n after sorting \n");
	display(head);

}
node *insert_b(node *head)
{
	node *p;
	int x;
	p=(node*)malloc(sizeof(node));
	printf("enter data=\n");
	scanf("%d",&x);
	p->data=x;
	p->next=head->next;
	head->next=p;
	return head;
}
node *insert_e(node *head)
{
	node *p;
	int x;
	p=(node*)malloc(sizeof(node));
	printf("enter data=\n");
	scanf("%d",&x);
	p->data=x;
	p->next=head->next;
	head->next=p;
	head=p;
	return head;
}
node *insert_i(node *head)
{
	node *p,*q;
	int n,key,x;
	p=(node*)malloc(sizeof(node));
	printf("enter data=\n");
	scanf("%d",&x);
	p->data=x;
	printf("enter key=\n");
	scanf("%d",&key);
	q=head->next;
	while(q->data!=key)
	{
		if(q==head)
		{
			printf("key not found");
			return head;
		}
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
	if(q==head)
		head=p;
	return head;
}
node *delete_node(node *head)
{
	node *p,*q;
	int key;
	printf("enter key=\n");
	scanf("%d",&key);
	if(head==NULL)
		printf("cll is empty\n");
	else if (head->next==head)
	{
		if(head->data==key)
		{
			p=head;
			head=NULL;
			free(p);
			printf("cll is empty  now\n");
		}
			else
			{
			
				printf("key not found\n");
		}
		}
		else
		{
			if(head->next->data==key)
			{
				p=head->next;
				head->next=p->next;
				free(p);
				return head;
			}
			else
			{
				q=head->next;
				while(q->next->data!=key)
				{
					if(q->next==head)
					{
						printf("key not found\n");
						return head;
					}
				}
				p=q->next;
				q->next=p->next;
				if(p==head)
					head=q;
				free(p);
			}
		}
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
		
			case 3:
					head=delete_node(head);
					display(head);
			break;
			case 4:
				sort(head);
			break;
			case 5:
				display(head);
			break;
			default:
			printf("wrong ch:");
		}
	}while(n!=6);
}