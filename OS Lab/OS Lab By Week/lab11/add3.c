#include <stdio.h>
#include <stdlib.h>

void sstf(int noq, int qu[10], int st, int visit[10])
{
  int min,s=0,p,i;
  while(1)
  {
    min=999;
    for(i=0;i<noq;i++)
      if (visit[i] == 0)
      {
        if(min > abs(st - qu[i]))
        {
          min = abs(st-qu[i]);
          p = i;
        }
      }
    if(min == 999)
      break;
    visit[p]=1;
    s=s + min;
    st = qu[p];
  }
  printf("Total seek time : %d\n", s);
  printf("Average seek time : %.2f\n", s/(float)noq);
}

int main()
{
  int i, n, noq, st;
  printf("Maximum disk size?\n");
  scanf("%d", &n);
  printf("Number of queue elements?\n");
  scanf("%d", &noq);
  int *qu = (int*) calloc(noq, sizeof(int));
  int *visit = (int *) calloc(noq, sizeof(int));
  printf("Enter work queue\n");
  for (i=0; i<noq; i++)
  {
    scanf("%d", &qu[i]);
    visit[i] = 0;
  }
  printf("Enter initial head position\n");
  scanf("%d", &st);
  sstf(noq, qu, st, visit);
  return 0;
}
