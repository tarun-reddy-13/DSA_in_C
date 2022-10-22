#include<stdio.h>
#define size 50
char s[size],top=-1;
void push(char x)
{
	s[++top]=x;
}
char pop()
{
	return s[top--];
}
int main()
{
	char str[50],rev[50],i,j;
	printf("\nEnter any string : ");
	scanf("%[^\n]s",str);
	for(i=0;str[i]!='\0';i++)
		push(str[i]);
	j=0;
	while(top!=-1)
		rev[j++]=pop();
	printf("\nReversed string : %s",rev);
	return 0;	
}