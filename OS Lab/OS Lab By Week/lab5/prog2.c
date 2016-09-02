#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int AT(int *a, int *b, int n, int time)
{
    int i, min=0;
    for(i=0; i<n; i++)
        if (b[min] > b[i] &&a [i] <= time)
            min=i;
    return min;
}

int main()
{
    int *bt, *at, *wt, *ta, *at1;
    int n, i, j, p, time=0;
    float avg=0;
    printf("Enter no. of processes\n");
    scanf("%d", &n);
    bt=(int *)calloc(n,sizeof(int));
    at=(int *)calloc(n,sizeof(int));
    wt=(int *)calloc(n,sizeof(int));
    ta=(int *)calloc(n,sizeof(int));
    at1=(int *)calloc(n,sizeof(int));
    for(i=0; i<n; i++)
    {
        printf("Arrival, burst time for P%d?\n", i+1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        at1[i] = bt[i];
    }
    for(i=0; i<n; i++)
    {
        p=AT(at, at1, n, time);
        wt[p]= time - at[p];
        for(j=0; j<bt[p]; j++)
        {
            time++;
        }
        ta[p] = time - at[p];
        at1[p] = INT_MAX;
    }
    for(i=0; i<n; i++)
        avg+=wt[i];
    time--;
    avg/=n;
    printf("ID\tArrival\tBurst\tWaiting\tTurnAround\n");
    for(i=0; i<n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], ta[i]);
    printf("Average Time=%.2lf\n", avg);
    return 0;
}
