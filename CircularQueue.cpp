//To perform various operations on a circular queue 
#include<stdio.h>
#include<conio.h>
#define MAX 30
#include<iostream>
#include<stdlib.h>
class queue
{
	int data[MAX];
	int rear,front;
	public:
		queue(){rear=front=-1;}
		int empty();
		int full();
		void enqueue(int x);
		int dequeue();
		void print();
		void makeempty(){rear=front=-1;}
};
int queue::empty()
{
	if(rear==-1)
		return (1);
	return(0);
}
int queue::full()
{
	if((rear+1)%MAX==front)
		return(1);
	return 0;
}
void queue::enqueue(int x)
{
	if(empty())
	{
		rear=front=0;
		data[rear]=x;
	}
	else
	{
		rear=(rear+1)%MAX;
		data[rear]=x;
	}
}
int queue::dequeue()
{
	int x=data[front];
	if(rear==front)
		rear=front=-1;
	else
		front=(front+1)%MAX;
	return(x);
}
void queue::print()
{
	int i=front;
	while(i!=rear)
	{
		std::cout<<data[i]<<" ";
		i=(i+1)%MAX;
	}
	std::cout<<data[rear];
}
int main()
{
	int x,op,n,i;
	queue q;
	do
	{
		std::cout<<"\n1)create\n 2)insert\n3)delete\n4)print\n5quit";
		std::cout<<"\n enter your choice";
		std::cin>>op;
		switch(op)
		{
			case 1:
				std::cout<<"\n enter no. of elements:";
				std::cin>>n;
				q.makeempty();
				std::cout<<"\enter data";
				for(i=0;i<n;i++)
				{
					std::cin>>x;
					if(q.full())
					{
						std::cout<<"\n queue is full!!";
						exit(0);
					}
					q.enqueue(x);
				}
				break;
				case 2:
				std::cout<<"\n enter elem to be ins:";
				std::cin>>x;
				if(q.full())
				{
					std::cout<<"\n queue is full!!!";
					exit(0);
				}
				q.enqueue(x);
				break;
				case 3:
					if(q.empty())
					{
						std::cout<<"\n queue is empty!!";
						exit(0);
					}
					x=q.dequeue();
					std::cout<<"\n elem="<<x;
				break;
				case 4:q.print();
				break;
				default:break;
		}
		
	}while(op!=5);
}