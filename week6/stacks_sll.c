//implementation of stack using singled linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node *top = NULL, *current;
void push()
{
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter current node data:\n");
	scanf("%d",&(current->data));
	current->link = top;
	top = current;
}
void pop()
{
	current = top;
	top = current->link;
	printf("Deleted element is : %d\n",(current->data));
	current->link = NULL;
	free(current);
}
void display()
{
	if(top==NULL)
		printf("Stack Underflow\n");
	else
	{
		current = top;
		printf("Stack = ");
		while(current!=NULL)
		{
			printf("%d -> ",current->data);
			current = current->link;
		}
	}

}
void peek()
{
	if(top!=NULL)
		printf("The top most element is : %d\n",top->data);
	else
		exit(1);
}
int main()
{
	int ch;
	while(1)
	{
		printf("Programs for stack\n");
		printf("1:Push\n");
		printf("2:Pop\n");
		printf("3:Display\n");
		printf("4:Peek\n");
		printf("5:Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		case 4: peek();
			break;
		case 5: exit(0);
		
		}
	}
	return 0;

}