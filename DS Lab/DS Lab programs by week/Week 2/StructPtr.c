#include<stdio.h>

typedef struct
{
  int roll;
  char name[20];
} STUDENT;

int main()
{
  int n;
  printf("Enter number of student details you want to input\n");
  scanf("%d", &n);
  STUDENT s[100];
  printf("Enter roll and name of student respectively\n");
  int i;
  STUDENT * const ptrBeg = s;
  STUDENT * const ptrLast = s + n - 1;
  for (i=0; i<n; i++)
    {
      scanf("%d %s", &(ptrBeg+i)->roll, &(ptrBeg+i)->name);
    }
  STUDENT *trav1;
  STUDENT temp; 
  for (i=0; i<n; i++)
    {
      for (trav1 = ptrBeg; trav1<ptrLast; trav1++)
	{
	  if ((trav1->roll) > ((trav1+1)->roll))
	    {
	      temp = *trav1;
	      *trav1 = *(trav1+1);
	      *(trav1+1) = temp;
	    }
	}
    }
  printf("Sorted array is\n");
  for (i=0; i<n; i++)
    {
      printf("Roll : %d Name : %s\n", s[i].roll, s[i].name);
    }
  return 0;
}
