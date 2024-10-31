//Binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
	
}node;
node *init()
{
	return NULL;
}
node *insert_NR(node *T,int x)
{
	node *p,*q,*r;
	r=(node*)malloc(sizeof(node));
	r->data=x;
	r->left=NULL;
	r->right=NULL;
	if(T==NULL)
		return r;
	p=T;
	while(p!=NULL)
	{
		p=q;
		if(x>p->data)
			p->right;
		else
			p->left;
	}
	if(x>q->data)
		q->right=r;
	else
		q->left=r;
	return T;
}
node *insert_R(node *T,int x)
{
	if(T==NULL)
	{
		T=(node*)malloc(sizeof(node));
		T->data=x;
		T->left=NULL;
		T->right=NULL;
		return T;
	}
	if(x> T->data)
	{
		T->right=insert_R(T->right,x);
		return T;	
	}
	T->left=insert_R(T->left,x);
	return T;
	
}
node *create()
{
	int n,x,i;
	node *root;
	root=NULL;
	printf("enter no of nodes:\n");
	scanf("%d",&n);
	printf("enter a tree value:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		root=insert_R(root,x);
	}
	return root;
}
node *findmin(node *T)
{
	while(T->left!=NULL)
		T=T->left;
	return T;
}
node *findmax(node *T)
{
	while(T->right!=NULL)
		T=T->right;
	return T;
}
void find_R(node *root,int x)
{
	if(root==NULL)
		printf("element not found\n");
	else if(root->data==x)
		printf("element found\n");
	else if(x > root->data)
	{
		find_R(root->right,x);
	}
	else if(x< root->data)
	{
		find_R(root->left,x);
	}
	else
		printf("element not found\n");
}
node *find_NR(node *root,int x)
{
	while(root!=NULL)
	{
		if(root->data==x)
			return root;
		if(x>root->data)
			root=root->right;
		else
			root=root->left;
	}
	return NULL;
}
node *makeempty(node *root)
{
	if(root!=NULL)
	{
		makeempty(root->left);
		makeempty(root->right);
		free (root);
	}
	return NULL;
}
node *delete(node*T,int x)
{
	
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
int main()
{
	node *tree=NULL;
	int n,x,y,m;
	node *b,*c,*a;
	tree=create();
	do
	{
		printf(" enter 1.insert 2.find 3.find min 4.find max 5.make empty 6 delete 7 print 8 exited\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("enter elem to insert\n");
				scanf("%d",&x);
				insert_R(tree,x);
				break;
			case 2:
				printf("enter elem to find\n");
				scanf("%d",&y);
				find_R(tree,y);
				break;
			case 3:
				b=findmin(tree);
				printf("%d",b->data);
			    break;
			case 4:
				c=findmax(tree);
				printf("%d",c->data);
			    break;
			case 5:
				makeempty(tree);
			break;
			case 6:
				printf("enter elem to delete");
				scanf("%d",&m);
				delete(tree,m);
			break;
			case 7:
				postorder(tree);
			break;
			case 8:
				printf("exited");
			break;
			default:printf("wrong input");
		}
	}while(n!=7);
}
