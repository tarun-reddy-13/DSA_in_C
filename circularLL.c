#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x=(NODE) malloc(sizeof (struct node));
    if(x==NULL)
    {
        printf("NO MEMORY \n");
        exit(0);
    }
    return x;
}

NODE insert_front(NODE last,int item)
{
    NODE temp;
    temp=getnode();
   
    temp->data=item;
    temp->link=temp;
   
    if(last==NULL)
    {
        last=temp;
        return last;
    }
    temp->link=last->link;
    last->link=temp;
   
    return last;
}
NODE insert_rear(NODE last,int item)
{
    NODE temp;
    temp=getnode();
   
    temp->data=item;
    temp->link=temp;
   
    if(last==NULL)
    {
        last=temp;
        return last;
    }
    temp->link=last->link;
    last->link=temp;
   
    last=temp;
   
    return last;
}

NODE del_front(NODE last)
{
    NODE temp;
    if(last==NULL)
    {
        printf("LIST EMPTY\n");
        return last;
    }
    if(last->link==last)
    {
        temp=last;
        printf("\nElement Deleted from the LIST is %d\n",last->data);
        free(temp);
        last=NULL;
        return last;
    }
    temp=last->link;
    printf("\nElement Deleted from the LIST is %d\n",temp->data);
    last->link=temp->link;
    temp->link=NULL;
    free(temp);
    return last;
}

NODE del_rear(NODE last)
{
    NODE temp;
    if(last==NULL)
    {
        printf("LIST EMPTY\n");
        return last;
    }
    temp=last;
    while(last->link!=temp)
    {
    	last=last->link;
	}
	printf("\nElement to be deleted : %d",temp->data);
	last->link=temp->link;
	return last;
}
void display(NODE last)
{
    NODE temp;
    if(last==NULL)
    {
        printf("LIST EMPTY");
    }
    else
    {
        temp=last->link;
        printf("\n The Content of the CIRCULAR LINKED LIST IS\n");
        while(temp->link!=last->link)
        {
            printf("-->%d",temp->data);
            temp=temp->link;
        }
       printf("-->%d",temp->data);
    }
}
int main()
{
    NODE last=NULL;
    printf("Welcome to CLL Implementation");
    last=insert_front(last,20);
    last=insert_front(last,5);
    last=insert_front(last,15);
    last=insert_front(last,10);
    last=insert_front(last,100);
    display(last);
   
    last=insert_rear(last,200);
    display(last);
   
    last=insert_front(last,1000);
    display(last);
   
    last=del_front(last);
    display(last);
   
   del_rear(last);
   display(last);
    return 0;
}