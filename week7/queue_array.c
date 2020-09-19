//implementation of queue using arrays
#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
int front = -1, rear = -1, queue[maxsize];
int isfull()
{
	if(rear == maxsize - 1)
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
	if(front == -1)
		front = 0;
	queue[++rear] = data;
}
int dequeue()
{
	int x = queue[front];
	if(front == rear)
	{
		front = rear = -1;
	}
	else
		front++;
	return x;
}
void display()
{
	int i;
	for(i=front;i<=rear;i++)
		printf("%d ",queue[i]);
}
int main()
{
	int ch, x;
	while(1)
	{
		printf("----Operations to be performed on the queue----\n");
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(isfull())
					printf("Queue Overflow\n");
				else
				{
					printf("Enter data to  insert: ");
					scanf("%d",&x);
					enqueue(x);
				}
				break;	
			case 2: if(isempty())
					printf("Queue Underflow\n");
				else
				{
					printf("Deleted element is %d \n",dequeue());
				}
				break;
			case 3: display();
			case 4: exit(0);
		}
	}
}