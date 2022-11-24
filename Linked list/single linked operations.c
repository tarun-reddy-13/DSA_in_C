/******************************************************************************
1 c program to implement the following operations on the single linked list:

1. Insert the node at beginning
2. Insert the node at the end
3. insert the node at given position
4. delete the node at beginning
5. delete the node at the end
6. delete the node at given position
7. Search for the given element
8. count the number of nodes
9. display
*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(NODE));
    if(x==NULL)
    {
        printf("\nMemory not alloted");
        exit(0);
    }
    return x;
}
NODE insert_front(NODE first,int item)
{
    NODE tem;
    tem=getnode();
    tem->data=item;
    tem->link=first;
    return tem;
}
NODE delete_fornt(NODE first)
{
    NODE ptr;
    if(first==NULL)
    {
        printf("\nEmpty list");
        exit(0);
    }
    ptr=first;
    printf("\nThe element to be deleted : %d",ptr->data);
    first=first->link;
    free(ptr);
    return first;
}
NODE insert_rear(NODE first,int item)
{
    NODE tem,ptr;
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
NODE delete_end(NODE first)
{
    NODE cur,pre;
    if(first==NULL)
    {
        printf("\nEmpty list");
        exit(0);
    }
    else if(first->link==NULL)
    {
        printf("\nElement to be deleted : %d",first->data);
        free(first);
        return NULL;
    }
    else
    {
        cur=first;
        pre=NULL;
        while(cur->link!=NULL)
        {
            pre=cur;
            cur=cur->link;
        }
        printf("\nElement to be deleted : %d",cur->data);
        pre->link=NULL;
        free(cur);
        return first;
    }
}
NODE insert_pos(NODE first,int pos,int item)
{
    NODE pre,cur,tem;
    int count=1;
    if(first==NULL)
    {
        printf("\nList empty. Insertion not possible");
        exit(0);
    }
    tem=getnode();
    tem->data=item;
    tem->link=NULL;
    cur=first;
    pre=NULL;
    while(cur!=NULL)
    {
        if(pos==count)
        {
            tem->link=pre->link;
            pre->link=tem;
            break;
        }
        count++;
        pre=cur;
        cur=cur->link;
    }
    return first;
}
NODE delete_pos(NODE first,int pos)
{
	NODE pre,cur;
	int count=1;
	if(first==NULL)
    {
        printf("\nList empty.");
        exit(0);
    }
    pre=NULL;
    cur=first;
    while(cur!=NULL)
    {
    	if(pos==count)
    	{
    		pre->link=cur->link;
    		printf("\nElement to be deleted : %d",cur->data);
    		free(cur);
    		break;
		}
		count++;
       	pre=cur;
       	cur=cur->link;
	}
	return first;
}
void display(NODE first)
{
    NODE ptr;
    ptr=first;
    if(ptr==NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
    	printf("\nList Elements :");
    	while(ptr!=NULL)
    	{
        	printf(" %d",ptr->data);
        	ptr=ptr->link;
    	}
	}
}
int count(NODE first)
{
    NODE tem;
    int count=0;
    if(first==NULL)
        return 0;
    tem=first;
    while(tem!=NULL)
    {
        count++;
        tem=tem->link;
    }
    return count;
}
void search(NODE first,int ele)
{
    NODE tem;
    int count=0,flag=-1;
    if(first==NULL)
    {
        printf("\nSearch unsuccessful empty list");
        exit(0);
    }
    tem=first;
    while(tem!=NULL)
    {
        count++;
        if(tem->data==ele)
        {
            flag=count;
            break;
        }
        tem=tem->link;
    }
    if(flag==-1)
        printf("\nSearch unsuccessful");
    else
        printf("\nSearch successful. Element %d found at position %d",ele,count);
}
int main()
{
    NODE first;
    first=getnode();
    first=NULL;
    int item,pos;
    int choice;
    printf("\n\n1. Insert at front\n2. Insert at end\n3. Insert at given position\n4. Delete front\n5. Delete end\n6. Delete at given position\n7. Search for an element\n8. Count the elements\n9. Display\n0. Exit");
    printf("\nEnter your choice : ");
	scanf("%d",&choice);
    while(choice)
    {
    	switch(choice)
    	{
    		case 1:
    			printf("\nEnter the element to be inserted (front): ");
    			scanf("%d",&item);
    			first=insert_front(first,item);
    			display(first);
    			break;
    		case 2:
    			printf("\nEnter the element to be inserted (rear): ");
    			scanf("%d",&item);
    			first=insert_rear(first,item);
    			display(first);
    			break;
    		case 3:
    			printf("\nEnter the element to be inserted : ");
    			scanf("%d",&item);
    			printf("\nEnter the position to be inserted : ");
    			scanf("%d",&pos);
    			first=insert_pos(first,pos,item);
    			display(first);
    			break;
    		case 4:
    			printf("\nBefore deleting:");
    			display(first);
    			first=delete_fornt(first);
    			printf("\nAfter deleting:");
    			display(first);
    			break;
    		case 5:
    			printf("\nBefore deleting:");
    			display(first);
    			first=delete_end(first);
    			printf("\nAfter deleting:");
    			display(first);
    			break;
    		case 6:
    			printf("\nEnter the position of element to be deleted : ");
    			scanf("%d",&pos);
				printf("\nBefore deleting:");
    			display(first);
    			first=delete_pos(first,pos);
    			printf("\nAfter deleting:");
    			display(first);
				break;
    		case 7:
    			printf("\nEnter the element to be searched : ");
    			scanf("%d",&item);
    			search(first,item);
    			break;
    		case 8:
    			printf("\nCount of elements in the linked list : %d",count(first));
    			break;
    		case 9:
    			display(first);
    			break;
		}
		printf("\n");
		printf("\nEnter your choice (0,1,2,3,4,5,6,7,8,9): ");
    	scanf("%d",&choice);
	}
	return 0;
}
