#include <stdio.h>
#include <stdlib.h>

void scan(int noq, int qu[10], int st)
{
  int i, j, s=0;
  for(i=0; i<noq; i++)
  {
    if(st < qu[i])
    {
      for(j=i-1; j>= 0;j--)
      {
        s=s+abs(st - qu[j]);
        st = qu[j];
      }
      s = s + abs(st - 0);
      st = 0;
      for(j = 1;j < noq;j++)
      {
        s= s + abs(st - qu[j]);
        st = qu[j];
      }
      break;
    }
  }
  printf("Total seek time : %d\n", s);
  printf("Average seek time : %.2f\n", s/(float) noq);
}

int main()
{
  int i, j, n, noq, st, t;
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
  for (i=0; i<noq; i++)
  {
    for (j=i+1; j<noq; j++)
    {
      if (qu[i] > qu[j])
      {
        t = qu[i];
        qu[i] = qu[j];
        qu[j] = t;
      }
    }
  }
  scan(noq, qu, st);
  return 0;
}
