#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node *head = NULL, *tail = NULL, *current = NULL, *prev, *next;

//creation of a singly linked list
void create()
{
	int i,n;
	printf("Enter number of nodes for linked lists: \n ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		current = (struct node*)malloc(sizeof(struct node));
		printf("Enter current node data: \n");
		scanf("%d",&(current->data));
		current->link = NULL;
		if(head == NULL)
			head = tail = current;
		else
		{
			tail->link = current;
			tail = current;
		}
	} 
}

//insertion of a node at the beginning
void insert_at_begin()
{
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data: \n");
	scanf("%d", &(current->data));
	current->link = head;
	head = current;
}

//insertion of a node at the end
void insert_at_end()
{
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:\n");
	scanf("%d",&(current->data));
	current->link = NULL;
	tail->link = current;
	tail = current;
}

//insertion a node at a position
void insert_at_position()
{
	int pos, c = 1;
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data to store at a position: \n");
	scanf("%d",&(current->data));
	printf("Enter the position where the data has to be stored: \n");
	scanf("%d",&pos);
	next = head;
	while(c < pos)
	{
		prev = next;
		next = next->link;
		c++;
	}
	prev->link = current;
	current->link = next;
}



//insertion before a given node
void insert_before_node()
{
	int value;
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data of the new node: \n");
	scanf("%d",&(current->data));
	printf("Enter data to insert before: \n");
	scanf("%d",&value);
	next = head;
	while(next->data != value && next!=NULL)
	{
		prev = next;
		next = next->link;
	}
	prev->link = current;
	current->link = next;
}

//insertion after a given node
void insert_after_node()
{
	int value;
	current = (struct node*)malloc(sizeof(struct node));
	printf("Enter data for the new node\n");
	scanf("%d",&(current->data));
	printf("Enter data to insert after\n");
	scanf("%d",&value);
	next = head;
	while(next->data!=value && next->link!=NULL)
	{
		next = next->link;
	}
	current->link = next->link;
	next->link = current;
}


//to display all the elements in the list
void display()
{
	if(head == NULL)
		printf("List is empty\n");
	else
	{
		next = head;
		while(next!=NULL)
		{
			printf("%d->",next->data);
			next = next->link;
		}
	}
}

//deletion of a node at the beginning
void delete_at_begin()
{
	current = head;
	head = current->link;
	current->link = NULL;
	printf("Deleted element is %d\n",current->data);
	free(current);
}

//deletion of a node at the end
void delete_at_end()
{
	current = head;
	while(current->link!=tail)
	{
		current = current->link;
	}
	current->link = NULL;
	next = tail;
	printf("Deleted element is %d\n", next->data);
	free(next);
	tail = current;
}

//deletion at a given position 
void delete_at_position()
{
	int pos, c=1;
	printf("Enter position of deletion\n");
	scanf("%d",&pos);
	next = head;
	while(c < pos)
	{
		prev = next;
		next = next->link;
		c++;
	}
	prev->link = next->link;
	printf("Deleted element is %d\n",next->data);
	next->link = NULL;
	free(next);
}

//deletion of a node before a given node
void delete_before_node()
{
	printf("Enter element before which it has to be deleted\n");
	int value;
	scanf("%d",&value);
	next = head;
	while(next->link->data!=value)
	{
		prev = next;
		next = next->link;
	}
	prev->link = next->link;
	next->link = NULL;
	printf("Deleted element is %d\n",next->data);
	free(next);
}

//deletion of a node after a given node
void delete_after_node()
{
	printf("Enter element after which it has to be deleted\n");
	int value;
	scanf("%d",&value);
	next = head;
	while(next->data!=value)
	{
		prev = next;
		next = next->link;
	}
	prev = next->link;
	next->link = prev->link;
	prev->link = NULL;
	printf("Deleted element is %d\n",prev->data);
	free(prev);
}

//to search an element in singly linked list
void search_element()
{
	if(head == NULL)
		printf("List is empty\n");
	else
	{
		printf("Enter the element to be searched\n");
		int value, c=1;
		scanf("%d",&value);
		next = head;
		while(next!=NULL)
		{
			if(next->data == value)
			{
				printf("Element is at %d position\n",c);
				break;
			}
			else
			{
				next = next->link;
				c++;
			}
		}
	}
}

//print the elements in the reverse order
void reverse_sll()
{
	int a[100], i=0;
	current = head;
	while(current!=NULL)
	{
		a[i++] = current->data;
		current = current->link;
	}
	i -= 1;
	while(i>=0)
	{
		printf("%d\t",a[i]);
		i--;
	}
}

// sorting elements in a singly linked list
void sorting_sll()
{
	struct node *p1, *last = NULL;
	int c, t;
	do
	{
		c = 0;
		p1 = head;
		while(p1->link!=NULL)
		{
			if(p1->data > p1->link->data)
			{
				t = p1->data;
				p1->data = p1->link->data;
				p1->link->data = t;
				c = 1;
			}
			p1 = p1->link;
		}
		last = p1;
	}while(c);
}


int main()
{
	int ch;
	while(1)
	{
		printf("Programs to be performed on single linked list\n\n");
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
		printf("12-Display elements\n");
		printf("13-Search element\n");
		printf("14-Sort\n");
		printf("15-Reverse\n\n");
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
			case 12: display();
				break;
			case 13: search_element();
				break;
			case 14: sorting_sll();
				break;
			case 15: reverse_sll();
				break;
			case 16: exit(0);
		}
	}
	return 0;
}