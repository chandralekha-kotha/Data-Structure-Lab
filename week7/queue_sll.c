//implementation of queue using single linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node *front = NULL, *rear = NULL, *current;
void enqueue()
{
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data to insert: \n");
	scanf("%d",&current->data);
	current->link = NULL;
	if(front == NULL)
		front = rear = current;
	else
	{
		rear->link = current;
		rear = current;
	}
}
void dequeue()
{
	if(front == NULL)
		printf("Queue Underflow\n");
	else if(front == rear)
	{
		printf("Deleted data %d\n",front->data);
		front = rear = NULL;
	}
	else
	{
		current = front;
		front = front->link;
		printf("Deleted data %d\n",current->data);
		free(current);	
	}
}
void display()
{
	if(front == NULL)
		printf("Queue is empty\n");
	else
	{
		current = front;
		while(current!=NULL)
		{
			printf("%d -> ",current->data);
			current = current->link;
		}
		printf("%d ",current->data);
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
