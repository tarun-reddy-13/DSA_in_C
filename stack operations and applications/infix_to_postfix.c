#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define size 50
char s[size];
int top=-1;
void push(char ch)
{
	s[++top]=ch;
}
char pop()
{
	return s[top--];
} 
int priority(char ch)
{
	if(ch=='(')
		return 0;
	else if(ch=='+'||ch=='-')
		return 1;
	else if(ch=='*'||ch=='/'||ch=='%')
		return 3;
	return 0;
}
int main()
{
	char exp[50],pofix[50],x;
	printf("\nEnter an expression in infix format : ");
	scanf("%[^\n]s",exp);
	printf("\nPostfix expression : ");
	int i=0;
	while(exp[i]!='\0')
	{
		if(isalnum(exp[i]))
			printf("%c",exp[i]);
		else if(exp[i]=='(')
			push(exp[i]);
		else if(exp[i]==')')
			while((x=pop())!='(')
				printf("%c",x);
		else
		{
			while(priority(s[top])>=priority(exp[i]))
				printf("%c",pop());
			push(exp[i]);
		}
		i++;
	}
	while(top!=-1)
		printf("%c",pop());
	return 0;
}