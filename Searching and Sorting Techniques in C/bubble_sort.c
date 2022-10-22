#include<stdio.h>
void b_sort(int *p,int n)
{
	int pass,comp,tem;
	for(pass=0;pass<n-1;pass++)
		for(comp=0;comp<=n-pass-1;comp++)
			if((*(p+comp)>*(p+comp+1)))
			{
				tem=*(p+comp);
				*(p+comp)=*(p+comp+1);
				*(p+comp+1)=tem;
			}
}
int main()
{
	int n,pass,comp,i;
	printf("\nEnter the size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter %d elements into array : ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	b_sort(&a[0],n);
	printf("\nSorted aray : ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
