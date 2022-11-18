#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
typedef struct node node;
node* getnode()
{
	node *x;
	x=(node*)malloc(sizeof(node));
	if(x==NULL)
	{
		printf("\nMemory not alloted");
		exit(0);
	}
	return x;
}
node* insert_end(node *first,int item)
{
	node *tem,*ptr;
	tem=getnode();
	tem->data=item;
	tem->link=NULL;
	if(first==NULL)
		return tem;
	ptr=first;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	ptr->link=tem;
	return first;
}
void delete_end(node* first)
{
	node *tem,*ptr;
	if(first==NULL)
	{
		printf("\nList is empty");
		exit(0);
	}
	ptr=first;
	while(ptr->link!=NULL)
		ptr=ptr->link;
	tem=ptr;
	printf("\nElement to be deleted : %d",tem->data);
	free(tem);
}
void display(node *first)
{
	if(first==NULL)
		printf("\nEmpty list");
	else
	{
		node *ptr;
		printf("\nElements of the list:");
		for(ptr=first;ptr!=NULL;ptr=ptr->link)
			printf(" %d",ptr->data);
	}
	printf("\n");
}
int main()
{
	node *first=NULL;
	int x=1,n;
	while(x)
	{
		printf("\n1. Insert an element\n2. Delete an element\n3. Exit\nEnetr your choice : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: 
					printf("\nEnter element to be inserted : ");
					scanf("%d",&n);
					first=insert_end(first,n);
					display(first);
					break;
			case 2:
					delete_end(first);
					display(first);
					break;
			case 3:
					x=0;break;
		}
	}
	return 0;
}