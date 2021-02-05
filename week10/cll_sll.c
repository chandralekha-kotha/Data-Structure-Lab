//program for circular linked list implementation using single linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*head=NULL,*current, *temp,*t1,*t2;
void create()
{
	current=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data: \n");
	scanf("%d",&current->data);
	current->link=current;
	if(head==NULL)
		head=current;
	else
	{
		temp=head;
		while(temp->link!=head)
			temp=temp->link;
		temp->link=current;
		current->link=head;
	}
}

void insert_begin()
{
	current=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data: ");
	scanf("%d",&current->data);
	temp=head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=current;
	current->link=head;
	head=current;
}
void insert_end()
{
	current=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data: \n");
	scanf("%d",&current->data);
	temp=head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=current;
	current->link=head;
}
void insert_position()
{
	int c=1,pos;
	printf("Enter position of insertion: \n");
	scanf("%d",&pos);
	current=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data: \n");
	scanf("%d",&current->data);
	t1=head;
	while(c<pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=current;
	current->link=t1;
}
void delete_begin()
{
	current=temp=head;
	while(temp->link!=head)
		temp=temp->link;
	temp->link=current->link;
	head=current->link;
	current->link=NULL;
	printf("Deleted element is %d\n",current->data);
	free(current);
}
void delete_end()
{
	t1=head;
	while(t1->link!=head)
	{
		t2=t1;
		t1=t1->link;
	}
		t2->link=head;
		t1->link=NULL;
		printf("Deleted element is %d\n",t1->data);
		free(t1);
}
void delete_position()
{
	int c=1,pos;
	printf("Enter position of deletion: \n");
	scanf("%d",&pos);
	t1=head;
	while(c<pos)
	{
		t2=t1;
		t1=t1->link;
		c++;
	}
	t2->link=t1->link;
	t1->link=NULL;
	printf("Deleted element is %d\n",t1->data);
	free(t1);
}
void display()
{
	if(head==NULL)
	printf("CLL IS EMPTY\n");
	else
	{
		temp=head;
		while(temp->link!=head)
		{
			printf("%d\t->\t",temp->data);
			temp=temp->link;
		}
		printf("%d\n",temp->data);
	}
}	
int main()
{
	int ch;
	while(1)
	{
		printf("\n-----OPERATIONS TO BE PERFORMED ON CLL-----\n");
		printf("1.CREATE\n2.INSERT AT BEGIN\n3.INSERT AT END\n4.INSERT AT POSITION\n5.DELETE AT BEGIN\n6.DELETE AT END\n7.DELETE AT POSITION\n8.DISPLAY\n9.EXIT\n");
		printf("enter your choice: \n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: create();
			break;
		case 2: insert_begin();
			break;
		case 3: insert_end();
			break;
		case 4: insert_position();
			break;
		case 5: delete_begin();
			break;
		case 6: delete_end();
			break;
		case 7: delete_position();
			break;
		case 8: display();
			break;
		case 9: exit(0);
		}
	}
	return 0;
}

