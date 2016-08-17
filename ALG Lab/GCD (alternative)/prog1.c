#include <stdio.h>
#include <stdlib.h>

int count = 0;
long cnt[20] = {0};

long findGCD (long m, long n, int mode, int pairno)
{
    long min = 0;
    if (m==0 || n==0)
        printf("One or more inputs is zero\n");
    if (m>n)
        min = n;
    else
        min = m;
    while (min > 0)
    {
        if (mode == 0)
            count = count+1;
        else
            cnt[pairno] = cnt[pairno]+1;
        if (m%min == 0)
        {
            if (n%min == 0)
                return min;
        }
        min-=1;
    }
}

int main()
{
    printf("Enter two numbers\n");
    long x, y;
    int i;
    scanf("%li %li", &x, &y); 
    printf("GCD of number is : %li\n", findGCD(x,y, 0, 500));
    printf("count is %d\n", count);
    long fib[20];
    fib[0] = 0;
    fib[1] = 1;
    for (i=2; i<20; i++)
        fib[i] = fib[i-1] + fib[i-2];
    for (i=0; i<20; i++)
    {
        printf("fib number %d of %li and %li gcd %li\n", i, fib[i], fib[i+1], findGCD(fib[i], fib[i+1], 1, i));
        printf("counting %li\n", cnt[i]);
    }
    return 0;
}
