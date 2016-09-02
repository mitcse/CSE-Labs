#include <stdio.h>  
 
int wt[10], bt[10], at[10], tat[10], n;  
float awt, atat;

void input()
{  
    printf("Number of processes?\t");  
    scanf("%d", &n);  
    int i;  
    for(i=0; i<n; i++)  
    {
        printf("Arrival Time of process %d?\t", i+1);  
        scanf("%d", &at[i]);         
        printf("Burst Time of process %d?\t", i+1);  
        scanf("%d", &bt[i]);         
    }  
}

void sort()
{
    int i, j, temp;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {    
            if(at[j] < at[i])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
		
		temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
}

void calculate()
{  
    wt[0]=0;  
    atat = tat[0] = bt[0];  
    int btt = bt[0];
    int i;  
    for(i=1; i<n; i++)
    {  
        wt[i] = btt - at[i];  
        btt += bt[i];        
        awt += wt[i];     
        tat[i] = wt[i] + bt[i];   
        atat += tat[i];    
    }  
    atat/=n;  
    awt/=n;       
}
  
void display()
{  
    int i;  
    printf("ID\tArrival\tBurst\tWaiting\tTurnAround\n");  
    for(i=0;i<n;i++)
        printf("%2d\t%2d\t%2d\t%2d\t%2d\n", i+1, at[i], bt[i], wt[i], tat[i]); 
    printf("Average Waiting Time:%.2f\nAverage Turn Around Time:%.2f\n", awt, atat);
}
    
int main()
{         
    input(); 
    sort(); 
    calculate();  
    display();   
    return 0;  
 }  
