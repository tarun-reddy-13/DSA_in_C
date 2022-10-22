#include<stdio.h>
char l_search(int a[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
		if(key==a[i])	
			return (char)i+1;
	return 'x';
}
int main()
{
	int a[50],i,j,n,key;char x;
	printf("Enter the size of n [MAX 50]: ");
	scanf("%d",&n);
	printf("Enter %d elements into array :\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter the key value : ");
	scanf("%d",&key);
	if((x=l_search(a,n,key))!='x')
		printf("\nKey value %d found at position %d.",key,x);
	else
		printf("\nKey value not found!!!!");
	return 0;
}