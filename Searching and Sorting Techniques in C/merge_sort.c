#include<stdio.h>
void merge(int a[],int l,int mid,int r)
{
	int n1,n2,i,j=0,k=l;
	n1=mid-l+1;
	n2=r-mid;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
		L[i]=a[i+l];
	for(j=0;j<n2;j++)
		R[j]=a[j+mid+1];
	i=0;j=0;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}
void merge_sort(int a[],int l,int r)
{
	int mid;
	if(l<r)
	{
		mid=(l+r)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
int main()
{
	int n,i;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter %d elements into array : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int l=0,r=n-1;
	merge_sort(a,l,r);
	printf("\nSorted array : ");
	for(i=0;i<n;i++)
		printf(" %d",a[i]);
	return 0;
}