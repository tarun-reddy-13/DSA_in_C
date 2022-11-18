#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void traversal(struct node *ptr)
{
	printf("\nList elements : ");
	while(ptr!=NULL)
	{
		printf(" %d",ptr->data);
		ptr=ptr->next; 
	}
}
int main()
{
	struct node *head;
	struct node *rare,*second;
	char ch;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	rare=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter an element to be insreted : ");
	scanf(" %d",&head->data);
	head->next=second;
	while(ch=='1')
	{
		printf("\nEnter 'Y' to insert another element : ");
		scanf("%c",&ch);
		if(ch=='Y')
		{
			scanf(" %d",&second->data);
			second->next=rare;
			rare=(struct node*)malloc(sizeof(struct node));
		}
		else
		{
			second->next=NULL;
			break;
		}
	}
	
	traversal(head);	
	return 0;
}