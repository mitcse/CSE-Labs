#include<stdio.h>
#include<stdlib.h>
int count=0;
void merge(int a[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;

	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	     L[i]=a[l+i];
	for(j=0;j<n2;j++)
	     R[j]=a[m+1+j];

	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[i])
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
void mergesort(int a[],int l,int r)
{ 
	count++;
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
int main()
{
	int n;
	int a[100];
	printf("enter the size of array\n");
	scanf("%d",&n);
	printf("\nenter the array elements\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("Sorted Array\n");
	for(int i=0;i<n;i++)
	{
	 	printf("%d \t",a[i]);
	}
	printf("\nopcount %d",count);
}