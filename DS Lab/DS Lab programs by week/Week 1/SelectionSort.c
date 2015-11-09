#include<stdio.h>

void SelSort(int arr[], int size)
{
  int pos, i, j, temp;
  for (i=0; i<size; i++)
    {
      pos = i;
      for (j=i+1; j<size; j++)
	{
	  if (arr[pos] > arr[i])
	    {
	      pos = j;
	    }
	}
      temp = arr[pos];
      arr[pos] = arr[i];
      arr[i] = temp;
    }
  printf("Sorted array is ");
  for (i=0; i<size; i++)
    {
      printf("%d\n",arr[i]);
    }
}

int main()
{
  int a[100], i, n;
  printf("Enter array size\n");
  scanf("%d",&n);
  printf("Enter array\n");
  for (i=0; i<n; i++)
    {
      scanf("%d", &a[i]);
    }
  SelSort(a,n);
  return 0;
}
