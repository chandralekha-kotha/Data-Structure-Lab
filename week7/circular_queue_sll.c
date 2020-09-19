#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *front = NULL, *rear = NULL, *current;
void enqueue()
{
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data to insert: \n");
	scanf("%d",&current->data);
	if(front == NULL)
	{
		current->link = current;
		front = rear = current;
	}
	else
	{
		rear->link = current;
		current->link = front;
		rear = current;
	}
}
void dequeue()
{
	if(front == NULL)
		printf("Circular queue underflow\n");
	else if(front == rear)
	{
		printf("Deleted data is %d \n", front->data);
		front = rear = NULL;
	}
	else
	{
		current = front;
		front = front->link;
		rear->link = front;
		printf("Deleted data is %d \n",current->data);
		free(current);
	}
}
void display()
{
	if(front == NULL)
		printf("Circular queue is empty\n");
	else
	{
		current = front;
		while(current->link!=front)
		{
			printf(" %d -> ",current->data);
			current = current->link;
		}
		printf(" %d ",current->data);
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n PROGRAMS FOR CIRCULAR QUEUE\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: exit(0);
		}
	}
}