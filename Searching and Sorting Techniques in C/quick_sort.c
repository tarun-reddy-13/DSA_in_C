#include<stdio.h>
void swap(int *a,int *b)
{
	int tem;
	tem=*a;
	*a=*b;
	*b=tem;
}
int partition(int a[],int l,int r)
{
	int i,j,pivot;
	pivot=a[l];
	i=l;j=r;
	while(i<j)
	{
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
			swap(&a[i],&a[j]);
	}
	swap(&a[l],&a[j]);
	return j;
}
void q_sort(int a[],int l,int r)
{
	int loc;
	if(l<r)
	{
		loc=partition(a,l,r);
		q_sort(a,l,loc-1);
		q_sort(a,loc+1,r);
	}
}
int main()
{
	int n,i;
	printf("\nENter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter %d elements : ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	q_sort(a,0,n-1);
	printf("\nSorted array :");
	for(i=0;i<n;i++)
		printf(" %d",a[i]);
	return 0;
}