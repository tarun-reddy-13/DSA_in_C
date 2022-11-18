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
	struct node *nxt;
	int x=0;
	//Memory allocation for nodes in linked list in heap
	head=(struct node*)malloc(sizeof(struct node));
	while(x!=1)
	{
		nxt=(struct node*)malloc(sizeof(struct node));
		printf("\nENter the element to be inserted : ");
		scanf("%d",nxt->data);
		nxt->next=nxt;
		printf("\nEnter 0 to insert another element : ");
		scanf("%d",&x);
	}
/*	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	//linking 1st and 2nd nodes
	head->data=7;
	head->next=second;
	//linking 2nd and 3rd nodes
	second->data=11;
	second->next=third;
	//terminating the list
	third->data=13;
	third->next=NULL; */
	traversal(head);
	return 0;
}