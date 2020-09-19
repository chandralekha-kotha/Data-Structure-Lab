#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int front = -1, rear = -1, cqueue[maxsize];
int isfull()
{
	if(front == (rear+1)%maxsize)
		return 1;
	else
		return 0;
}
int isempty()
{
	if(front == -1)
		return 1;
	else
		return 0;
}
void enqueue(int data)
{
	if(front == (rear+1)%maxsize)
		printf("Curcular queue overflow\n");
	else if(front == -1)
	{
		front = rear = 0;
		cqueue[rear] = data;
	}
	else
	{
		rear = (rear+1)%maxsize;
		cqueue[rear] = data;
	}
}
void dequeue()
{
	if(front == -1)
		printf("Circular queue is empty\n");
	else if(front == rear)
	{
		printf("Deleted element is %d\n",cqueue[front]);
		front = rear = -1;
	}
	else
	{
		printf("Deleted element is %d\n",cqueue[front]);
		front = (front+1)%maxsize;
	}
}
void display()
{
	int i = front;
	if(isempty())
		printf("Circular queue is empty\n");
	else
	{
		while(i!=rear)
		{
			printf(" %d ",cqueue[i]);
			i = (i+1)%maxsize;
		}
		printf(" %d ",cqueue[i]);
	}
}
int main()
{
	int ch, x;
	while(1)
	{
		printf("\n PROGRAMS FOR CIRCULAR QUEUE\n\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(isfull())
					printf("Circular queue overflow\n");
				else
				{	
					printf("Enter data to be inserted: \n");
					scanf("%d",&x);
					enqueue(x);
				}
					break;
			case 2: if(isempty())
					printf("Circular queue underflow\n");
				else
				{
					dequeue();
				}
					break;
			case 3: display();
				break;
			case 4: exit(0);
		}
	}
}