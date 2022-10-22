#include<stdio.h>
void sort(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i]<a[j])
			{
				a[i]=a[i]^a[j];
				a[j]=a[i]^a[j];
				a[i]=a[i]^a[j];
			}
}
char bin_search(int a[],int key,int n)
{
	int l=0,r=n-1,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(key==a[mid])
			return (char)mid+1;
		else if(key>a[mid])
			l=mid+1;
		else
			r=mid-1;
	}
	return 'x';
}
int main()
{
	int n,i,key;char x;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter %d elements into array :\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nSorted array : ");
	sort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nEnetr the key value to be searched : ");
	scanf("%d",&key);
	if((x=bin_search(a,key,n))!='x')
		printf("\nKey value %d found at position %d",key,x);
	else
		printf("\nKey value not found!!!");
	return 0;
}