#include <stdio.h>
#include <stdlib.h>

int main()
{
    int proc1[10], bur1[10], pri1[10], proc2[10], bur2[10], pri2[10], sys, temp, i, j, n, k=0, t=0;
    printf("Number of processes?\n");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("1 for system 2 for user, process id, burst time and priority of P%d\n", i+1);
        scanf("%d", &sys);
        if(sys == 1)
        {
            scanf("%d", &proc1[k]);
            scanf("%d", &bur1[k]);
            scanf("%d", &pri1[k]);
            k++;
        }
        else
        {
            scanf("%d", &proc2[t]);
            scanf("%d", &bur2[t]);
            scanf("%d", &pri2[t]);
            t++;
        }
    }
    for(i=0; i<k-1; i++)
    {
        for(j=i+1; j<k; j++)
        {
            if(pri1[i] > pri1[j])
            {
                temp=proc1[i];
                proc1[i]=proc1[j];
                proc1[j]=temp;

                temp=bur1[i];
                bur1[i]=bur1[j];
                bur1[j]=temp;

                temp=pri1[i];
                pri1[i]=pri1[j];
                pri1[j]=temp;
            }
        }
    }
    for(i=0; i<t-1; i++)
    {
        for(j=i+1; j<t; j++)
        {
            if(pri2[i] > pri2[j])
            {
                temp=proc2[i];
                proc2[i]=proc2[j];
                proc2[j]=temp;

                temp=bur2[i];
                bur2[i]=bur2[j];
                bur2[j]=temp;

                temp=pri2[i];
                pri2[i]=pri2[j];
                pri2[j]=temp;
            }
        }
    }
    printf("ID\tburst time\tpriority\tcategory\n");
    for(i=0; i<k; i++)
        printf("%d \t\t %d \t\t %d \t\t system process\n",proc1[i],bur1[i],pri1[i]);
    for(i=0; i<t; i++)
         printf("%d \t\t %d \t\t %d \t\t user process\n",proc2[i],bur2[i],pri2[i]);
    return 0;
}
