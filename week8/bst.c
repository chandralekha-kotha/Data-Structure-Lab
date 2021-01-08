#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct BST
{
	int data;
	struct BST *left, *right;
};
struct BST *root = NULL, *temp, *current;
void create()
{
	char c[10];
	temp = root;
	current = (struct BST*)malloc(sizeof(struct BST));
	printf("ENTER DATA : ");
	scanf("%d",&current->data);
	current->left = NULL;
	current->right = NULL;
	if(temp == NULL)
		root = current;
	else
	{
		while(temp!=NULL)
		{
			if((current->data) < (temp->data))
			{
				if(temp->left == NULL)
				{
					temp->left = current;
					return;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{
				if(temp->right == NULL)
				{
					temp->right = current;
					return;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
}

void postorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("\t%d",temp->data);
	}
}

void preorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		printf("\t%d",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(struct BST *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("\t%d",temp->data);
		inorder(temp->right);
	}
}
int main()
{
	int ch;
	printf("\n-----MENU OPTIONS-----\n\n");
	printf("1.CREATE\n2.POSTORDER\n3.PREORDER\n4.INORDER\n5.EXIT\n");
	while(1)
	{
		printf("\nENTER YOUR CHOICE: \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: create();
					break;
			case 2: printf("\nPOSTORDER TRAVERSAL\n");
					postorder(root);
					break;
			case 3: printf("\nPREORDER TRAVERSAL\n");
					preorder(root);
					break;
			case 4: printf("\nINORDER TRAVERSAL\n");
					inorder(root);
					break;
			case 5: exit(0);
					break;
			default : printf("\n! INVALID CHOICE !\n");
				
		}
	}
}
