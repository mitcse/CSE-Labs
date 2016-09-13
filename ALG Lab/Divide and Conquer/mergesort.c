#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

void merge (int *arr, int start, int mid, int end) 
{
	int *temp = (int *)calloc(end + 1, sizeof(int));
	int i = start;
	int s = start, m = mid + 1;	
	while ((s <= mid) && (m <= end)) 
        {
                count = count + 1;
		if (*(arr + s) < *(arr + m))
			*(temp + i++) = *(arr + s++);
		else
			*(temp + i++) = *(arr + m++);
	}
	while (s <= mid)
		*(temp + i++) = *(arr + s++);
	while (m <= end)
		*(temp + i++) = *(arr + m++);
	for (i = start; i <= end; ++i)
		*(arr + i) = *(temp + i);
}

void mergeSort (int *arr, int start, int end)
{
	int mid;
	if (start < end) 
        {
		mid = (start + end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main () 
{	
	int n, i;
	printf("Enter number of elements in the array\n");
	scanf(" %d", &n);	
	int *arr = (int *)calloc(n, sizeof(int));
	printf("Enter %d elements\n", n);
	for (i = 0; i < n; ++i)
		scanf(" %d", (arr + i));
	mergeSort(arr, 0, n - 1);
	printf("Sorted\n");
	for (i = 0; i < n; ++i)
		printf("%d\n", arr[i]);
        printf("Count is %d\n", count);
        return 0;
}
