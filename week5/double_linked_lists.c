#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*prev;
	struct node*next;
};
struct node *head=NULL, *tail=NULL, *current, *t1, *t2;

//creation of double linked list
void create()
{
	int n, i;
	printf("Enter number of nodes: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		current = (struct node*)malloc(sizeof(struct node));
		printf("Enter data: \n");
		scanf("%d",&(current->data));
		current->prev = NULL;
		current->next = NULL;
		if(head == NULL)
			tail = head = current;
		else
		{
			tail->next = current;
			current->prev = tail;
			tail = current;
		}
	}
}

// insertion at the begining of the list
void insert_at_begin()
{
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: \n");
	scanf("%d",&(current->data));
	current->prev = NULL;
	current->next = head;
	head->prev = current;
	head = current;		
}

//insertion at a given position
void insert_at_position()
{
	int pos, c=1;
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data to be stored at the position:\n");
	scanf("%d",&(current->data));
	printf("Enter location where the node has to be inserted:\n");
	scanf("%d",&pos);
	t1 = head;
	while(c<pos && t1!=NULL)
	{
		t2 = t1;
		t1 = t1->next;
		c++;
	}
	t2->next = current;
	current->prev = t2;
	current->next = t1;
	t1->prev = current;
		
}

//insertion at the end of the list
void insert_at_end()
{
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: \n");
	scanf("%d",&(current->data));
	current->next = NULL;
	current->prev = tail;
	tail->next = current;
	tail = current;		
}

//insertion before a given node
void insert_before_node()
{
	int value;
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&(current->data));
	printf("Enter data before which node it has to be inserted:\n");
	scanf("%d",&value);
	t1 = head;
	while(t1!=NULL && t1->data!=value)
	{
		t2 = t1;
		t1 = t1->next;
	}
	t2->next = current;
	current->prev = t2;
	current->next = t1;
	t1->prev = current;

}

//insertion after a given node
void insert_after_node()
{
	int value;
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&(current->data));
	printf("Enter data after which node it has to be inserted:\n");
	scanf("%d",&value);
	t1 = head;
	while(t1!=NULL && t1->data!=value)
	{
		t1 = t1->next;
	}
	current->next = t1->next;
	t1->next->prev = current;
	t1->next = current;
	current->prev = t1;
}

//deletion at the begining
void delete_at_begin()
{
	current = head;
	head = current->next;
	head->prev = NULL;
	current->next = NULL;
	printf("Deleted element is: %d \n", (current->data));
	free(current);
} 

//deletion at the end
void delete_at_end()
{
	current = tail;
	tail = tail->prev;
	tail->next = NULL;
	current->prev = NULL;
	printf("Deleted element is : %d \n",(current->data));
	free(current);
}

//deletion at a position
void delete_at_position()
{
	int pos, c=1;
	printf("Enter the position of the node to be deleted:\n");
	scanf("%d",&pos);
	t1 = head;
	while(c<pos && t1!=NULL)
	{
		t2 = t1;
		t1 = t1->next;
		c++;
	}
	t2->next = t1->next;
	t1->next->prev = t2;
	printf("Deleted element is : %d \n", t1->data); 
	t1->next = t1->prev = NULL;
	free(t1);
}

//deletion before a given node
void delete_before_node()
{
	int value;
	printf("Enter data before which node it has to be deleted: \n");
	scanf("%d",&value);
	t1 = head;
	while(t1->next->data!=value && t1!=NULL)
	{
		t2 = t1;
		t1 = t1->next;
	}
	t2->next = t1->next;
	t1->next->prev = t2;
	printf("Deleted element is : %d \n",t1->data);
	t1->next = t1->prev = NULL;
	free(t1);
}

//deletion after a given node
void delete_after_node()
{
	int value;
	printf("Enter data after which node it has to be deleted: \n");
	scanf("%d",&value);
	t1 = head;
	while(t1->data!=value && t1!=NULL)
	{
		t1 = t1->next;
	}
	t2 = t1->next;
	t1->next = t2->next;
	t2->next->prev = t1;
	printf("Deleted element is %d \n",t2->data);
	t2->next = t2->prev = NULL;
	free(t2);
	
}

//to display the elements in forward direction
void display_forward()
{
	if(head == NULL)
		printf("The list is empty\n");
	else
	{
		current = head;
		while(current!=NULL)
		{
			printf("%d <-> ",current->data);
			current = current->next;
		}
	}
}

//to display the elements in reverse order
void display_reverse()
{
	if(head == NULL)
		printf("The list is empty\n");
	else
	{
		current = tail;
		while(current!=NULL)
		{
			printf("%d <-> ",current->data);
			current = current->prev;
		}
	}
}

//to search an element in the list
void search()
{
	int value, flag = 0, c=1;
	printf("Element to be searched: \n");
	scanf("%d",&value);
	t1 = head;
	while(t1!=NULL)
	{
		if(t1->data == value)
		{
			flag = 1;
			break;
		}
		t1 = t1->next;
		c++;
	}
	if(flag == 1)
		printf("Element is present at %d\n",c);
	else
		printf("Element is not present in the list\n");
}

//to sort the elements in the list
void sorting()
{
	struct node *p1, *last = NULL;
	int c, t;
	do
	{
		c = 0;
		p1 = head;
		while(p1->next!=NULL)
		{
			if(p1->data > p1->next->data)
			{
				t = p1->data;
				p1->data = p1->next->data;
				p1->next->data = t;
				c = 1;
			}
			p1 = p1->next;
		}
		last = p1;
	}while(c);
	
}
int main()
{
	int ch;
	while(1)
	{
		printf("Programs to be performed on double linked list\n");
		printf("---------------------------------------------------\n");
		printf("1-Create\n");
		printf("2-Insert at begin\n");
		printf("3-Insert at position\n");
		printf("4-Insert at end\n");
		printf("5-Insert before\n");
		printf("6-Insert after\n");
		printf("7-Delete at begin\n");
		printf("8-Delete at end \n");
		printf("9-Delete at positon\n");
		printf("10-Delete before\n");
		printf("11-Delete after\n");
		printf("12-Display from the first\n");
		printf("13-Display in reverse order\n");
		printf("14-Search element\n");
		printf("15-Sort element\n\n");
		printf("-----------------------------------------------------\n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
				break;
			case 2: insert_at_begin();
				break;
			case 3: insert_at_position();
				break;
			case 4: insert_at_end();
				break;
			case 5: insert_before_node();
				break;
			case 6: insert_after_node();
				break;
			case 7: delete_at_begin();
				break;
			case 8: delete_at_end();
				break;
			case 9: delete_at_position();
				break;
			case 10: delete_before_node();
				break;
			case 11: delete_after_node();
				break;
			case 12: display_forward();
				break;
			case 13: display_reverse();
				break;
			case 14: search();
				break;
			case 15: sorting();
				break;
			case 16: exit(0);
		}
	}
	return 0;
}