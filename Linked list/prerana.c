#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;
NODE* getnode()
{
    NODE *x;
    x=(NODE*)malloc(sizeof(NODE));
    if(x==NULL)
    {
        printf("no memory allocated:\n");
        exit(0);
    }
    return x;
}
NODE* insert_front(NODE *first, int item)
{
    NODE *temp;
    temp=getnode();
    temp->data=item;
    temp->link=first;
    first=temp;
    return first;
}
void display(NODE *first)
{
    NODE *temp;
    temp=first;
    if(temp==NULL)
    {
        printf("no elements:\n");
        exit(0);
    }
    while(temp!=NULL)
    {
        printf("elements to be display are : %d\n",temp->data);
        temp=temp->link;
    }
    
}
int main()
{
    NODE *first;
    first=getnode();
    int p;
    printf("enter the elements:\n");
    scanf("%d",&p);
    first->data=p;
    first->link=NULL;
    display(first);
    while(1)
    {
        printf("enter the elements:\n");
        scanf("%d",&p);
        first=insert_front(first, p);
        display(first);
    }
	return 0;
}