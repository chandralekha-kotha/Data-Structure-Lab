#include<stdio.h>
#include<stdlib.h>
struct node
{
	float data;
	struct node*prev;
	struct node*next;
};
int main()
{
	struct node*s;
	s=(struct node*)malloc(sizeof(struct node));
	s->data=20.5;
	s->prev=NULL;
	s->next=NULL;
	printf("data=%f",s->data);
}