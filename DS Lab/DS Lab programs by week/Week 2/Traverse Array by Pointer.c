#include<stdio.h>
int main()
{
  int i, a[100], n;
  printf("Enter array size: ");
  scanf("%d", &n);
  printf("Enter array elements: \n");
  for(i=0; i<n; i++)
  {
    scanf("%d", a+i);
  }
  int *frontPtr = a;
  i = 0;
  printf("Print forward\n");
  while (i<n)
  {
    printf("%d ", *frontPtr);
    frontPtr++;
    i++;
  }
  printf("\n");
  int *backPtr = &a[n-1];
  i = 0;
  printf("Print backward\n");
  while (i<n)
  {
    printf("%d ", *backPtr);
    backPtr--;
    i++;
  }
  printf("\n");
  return 0;
}
