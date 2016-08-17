#include<stdio.h>
#include<stdlib.h>

void middleSchool(int m, int n)
{
    int mm, nn;
    mm=m;
    nn=n;
    int gcd=1, flag, count=0, i, t, j;
    if(m<n)
        t=m;
    else
        t=n;
    for(i=3;i<=t/2;i++)
    {
        flag=1;
        for(j=2;j<i;j++)
	{
	    if(i%j==0)
	    {
		flag=0;
		break;
	    }
	}
        while(1)
        {
            count++;
            if(m%i==0 && n%i==0)
	    {
	        m=m/i;
	        n=n/i;
	        gcd*=i;	
	    }
            else
                break;
        }
    }
    while(1)
    {
        count++;
        if(m%2==0 && n%2==0)
	{
	    m=m/2;
	    n=n/2;
	    gcd*=2;	
	}
        else
            break;
    }
    printf("GCD of %d and %d is %d and count is %d\n", mm, nn, gcd, count);
}

int main()
{
    int m, n, i;
    int fib[18];
    fib[0] = 0;
    fib[1] = 1;
    for (i=2; i<18; i++)
        fib[i] = fib[i-2] + fib[i-1];
    printf("Enter m and n\n");
    scanf("%d %d", &m, &n);
    middleSchool(m, n);
    for (i=0; i<17; i++)
        middleSchool(fib[i], fib[i+1]);
    return 0;
}
