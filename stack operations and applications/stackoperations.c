#include<stdio.h>
#define size 50
int s[size];
int top=-1;
void display()
{
	if(top!=-1)
	{
		printf("\nStack contents : ");
		for(int i=top;i>-1;i--)
			printf(" %d",s[i]);
	}
	else
		printf("\nStack empty\n");
}
void push()
{
	int x;
	if(top==size-1)
	{
		printf("\nStack overflow\n");	
	}
	else
	{
		printf("\nEnter the element to be pushed into stack : ");
		scanf("%d",&x);
		top+=1;
		s[top]=x;
		printf("\nPush operation success.\n");
	}
}
void pop()
{
	if(top!=-1)
	{
		printf("\nPopped element : %d",s[top--]);
	}
	else
	{
		printf("\nStack Underflow\n");
	}
}
void peek()
{
	if(top!=-1)
	{
		printf("\nPeek element : %d",s[top]);
	}
	else
		printf("\nStack Empty\n");
}
void isfull()
{
	if(top==size-1)
		printf("\nStack full!!!\n");
	else
		printf("\nElements can be inserted...\n");
}
void isempty()
{
	if(top==-1)
		printf("\nStack empty!!!\n");
	else
		printf("\nElements present in stack...\n");
}
int main()
{
	int ch;
	printf("\n1. push\n2. pop\n3. peek\n4. display\n5. isfull\n6. isempty\n7. exit\n\nEnter Your choice to perform operations on string : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: push();	display();break;
		case 2: pop();display();break;
		case 3: peek();display();break;
		case 4: display();break;
		case 5: isfull();break;
		case 6: isempty();break;
		case 7: return 0;
	}
	printf("\n");
	main();
}