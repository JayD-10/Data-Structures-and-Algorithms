//To create and display singly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node*next;
}node;
//function to create a linked list
node *create()
{
    node *head,*p;
    int i,n;
    printf("Enter number of nodes=\n");
    scanf("%d",&n);
    if(n>0)
    {
        head=(node*)malloc(sizeof(node));
        printf("enter data=\n");
        scanf("%d",&head->data);
        head->next=NULL;
        p=head;
        for(i=1;i<n;i++)
        {
            p->next=(node*)malloc(sizeof(node));//new node
            p=p->next;
            printf("enter data=\n");
            scanf("%d",&p->data);
            p->next=NULL;
        }
    }
    return head;
}
//function to display a linked list
void display(node *head)
{

    node *p=head;
    while(p!=NULL)
    {
        printf("--%d--",p->data);
        p=p->next;
    }
    if(head==NULL)
        printf("LL is empty!");

}
//function to count no. of elements in the LL
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
//Function to sort the elements in ascending order
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
            if(p->data>p->next->data)//to sort in descending order just do <
            {
                temp=p->data;
                p->data=p->next->data;
                p->next->data=temp;
            }
            p=p->next;
        }

    }
    printf("\n After sorting list in ascending order:\n");
    display(head);

}
node *insert_b(node *head)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    printf("enter data to be inserted at start=\n");
    scanf("%d",&p->data);
    p->next=head;
    head=p;
    return head;

}
node *insert_e(node *head)
{
    node *p,*q;
    p=(node*)malloc(sizeof(node));
    printf("enter data to be inserted at end=\n");
    scanf("%d",&p->data);
    p->next=NULL;
    q=head;
    while(q->next!=NULL)
        q=q->next;
    q->next=p;
    return head;
}
node *insert_i(node *head)
{
	node *p,*q;
	int key;
	p=(node*)malloc(sizeof(node));
	printf("enter data insert in between=\n");
	scanf("%d",&p->data);
	p->next=NULL;
	q=head;
	printf("Enter key=\n");//key means elem after which you want to insert it.
	scanf("%d",&key);
	while(q->data!=key)
	{
		if(q->data!=key)
		{
			printf("key not found\n");
			return head;
		}
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
	return head;
}
node *delete_b(node *head)
{
	node *p;
	if(head==NULL)
		printf("LL is empty\n");
	else if(head->next==NULL)
	{
		p=head;
		head=NULL;
		free(p);
		printf("LL is empty now\n");
	}
	else
	{
		p=head;
		head=head->next;
		free(p);
		printf("Node is deleted\n");
	}
	return head;
	
}
node *delete_e(node *head)
{
	node *p,*q;
	if(head==NULL)
		printf("LL is empty");
	else if(head->next==NULL)
	{
		p=head;
		head=NULL;
		free(p);
		printf("LL is empty now.");
	}
	else
	{
		q=head;
		while(q->next->next!=NULL)
			q=q->next;
		p=q->next;
		q->next=NULL;
		free(p);
	}
	return head;
}





int main()
{

    node *head=NULL;
    int n,n1,x,cnt;
    head=create();
    display(head);
    printf("\n");
    cnt=count(head);
    printf("Number of elements:%d",cnt);
    sort(head);
    printf("\n");
    head=insert_b(head);
    printf("element after insertion\n");
    display(head);
    printf("\n");
    head=insert_e(head);
    printf("element after insertion\n");
    display(head);
    head=insert_i(head);
    printf("element after insertion\n");
    display(head);
    head=delete_b(head);
    printf("element after deletion at beginning\n");
    display(head);
    head=delete_e(head);
    printf("element after deletion at end\n");
    display(head);
    

}
