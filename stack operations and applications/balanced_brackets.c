#include<stdio.h>
#define size 50
char s[size],top=-1;
void push(char ch)
{
	s[++top]=ch;
}
void pop()
{
	s[top--];
}
int main()
{
	char exp[50];
	int i;
	printf("\nEnter an expression : ");
	scanf("%[^\n]s",exp);
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='('||exp[i]=='['||exp[i]=='{'||exp[i]=='<')
			push(exp[i]);
		else if(exp[i]==')'||exp[i]==']'||exp[i]=='}'||exp[i]=='>')
		{
			if(exp[i]==')'&&s[top]=='('||exp[i]==']'&&s[top]=='['||exp[i]=='}'&&s[top]=='{'||exp[i]=='>'&&s[top]=='<')
				pop();
			else
			{
				printf("\nUnbalenced Brackets.");
				return 0;
			}
		}
	}
	if(s[top]!=0)
		printf("\nUnbalenced Brackets.");
	else
		printf("\nBalenced Brackets");
	return 0;
}