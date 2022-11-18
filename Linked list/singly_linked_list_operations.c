#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *flink;

};
typedef struct node node;
node* getnode()
{
	node *x;
	x=(node*)malloc(sizeof(node));
	return x;
}
node* insertfront(node *first,int item)
{
	node *tem;
	tem=getnode();
	tem->data=item;
	tem->flink=first;
	return tem;
}

void display(node *first)
{
	node *ptr;
	ptr=first;
	if(ptr==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		printf("\nElements of list : ");
		while(ptr!=NULL)
		{
			printf(" %d",ptr->data);
			ptr=ptr->flink;
		}
	}
}
node* deletefront(node *first)
{
	node *tem;
	tem=first;
	if(tem==NULL)
	{
		printf("\nList is empty");
	}
	else
	{
		first=first->flink;
		printf("\nDeleted element : %d",tem->data);
		free(tem);
	}
	return first;
}

int main()
{
	node *first;int n;int x=-1;
	first=getnode();
	first=NULL;
	while(1)
	{
		printf("\nEnter 1 to insert an element at front\n      2 to delete an element\nPress 0 to exit\nEnter your choice : ");
		scanf("%d",&x);
		switch(x)
		{
			case 0:return 0;
			case 1:
				printf("\nEnter the data to be inserted at front : ");
				scanf("%d",&n);
				first=insertfront(first,n);
				printf("\nInsertion successful");
				printf("\nList elements :");
				display(first);break;
			case 2:
				first=deletefront(first);display(first);break;
				
		}
		printf("\n\n");
	}
	return 0;
	
}
