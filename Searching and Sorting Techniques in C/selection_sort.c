#include<stdio.h>
void s_sort(int *a,int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++) 
			if(*(a+min)>*(a+j)) 
				min=j;
		if(min!=i)
		{
			*(a+i)=*(a+i)^*(a+min);
			*(a+min)=*(a+i)^*(a+min);
			*(a+i)=*(a+i)^*(a+min);
		}
	}
}
int main()
{
	int n,i;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter %d elements into array : ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	s_sort(&a[0],n);
	printf("\nSorted array : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}