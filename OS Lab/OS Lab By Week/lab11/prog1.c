#include <stdio.h>
#include <stdlib.h>

int main()
{
  int queue[20], n, head, i, j, k, seek=0, max, diff;
  float aver;
  printf("Max disk range?\n");
  scanf("%d", &max);
  printf("Queue request size?\n");
  scanf("%d", &n);
  printf("Queue?\n");
  for(i=1; i<=n; i++)
    scanf("%d", &queue[i]);
  printf("Initial head at?\n");
  scanf("%d", &head);
  queue[0] = head;
  for(j=0; j<=n-1; j++)
  {
    diff = abs(queue[j+1]-queue[j]);
    seek += diff;
    printf("From %d to %d with seek %d\n", queue[j], queue[j+1], diff);
  }
  printf("total seek time = %d\n", seek);
  aver = seek/(float)n;
  printf("average seek time = %.2f\n", aver);
  return 0;
}
