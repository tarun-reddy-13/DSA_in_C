#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define size 50
int s[size],top=-1;
void push(float ch)
{
	s[++top]=ch;
}
float pop()
{
	return s[top--];
}
int main()
{
	char exp[50];
	float a,b;
	int i;
	printf("\nEnter any expression in postfix form : ");
	scanf("%[^\n]s",exp);
	for(i=0;exp[i]!='\0';i++)
	{
		if(isdigit(exp[i]))
			push((float)exp[i]-48);
		else
		{
			b=pop();
			a=pop();
			switch(exp[i])
			{
				case '+': push(a+b);break;
				case '-': push(a-b);break;
				case '*': push(a*b);break;
				case '/': push(a/b);break;
				case '%': push(fmod(a,b));break;
				case '^': push(pow(a,b));break;
			}
		}
	}
	printf("\nResult : %0.2f",pop());
	return 0;
}