#include<stdio.h>
void in_sort(int *a,int n)
{
	int tem,j;
	for(int i=1;i<n;i++)
	{
		tem=*(a+i);
		for(j=i-1;j>=0&&*(a+j)>tem;j--)
			*(a+j+1)=*(a+j);
		*(a+j+1)=tem;
	}
}
int main()
{
	int n,i,j,tem;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter %d elements into array :",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	in_sort(&a[0],n);
	printf("\nSorted array :");
	for(i=0;i<n;i++)
		printf(" %d",a[i]);
	return 0;
}
