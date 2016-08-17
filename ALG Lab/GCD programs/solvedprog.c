#include<stdio.h>

int gcd(int a, int b)
{  
      int t,counter = 0;  
      while (b != 0) 
      {  
        t = b;  
        b = a % b;  
	counter++;
        a = t;  
      }  
      printf("number of operations %d\n", counter);
      return a;  
}
void fibonacci(int n)
{
	int i,arr[40];	
	int first = 0, second = 1, next;
	arr[0] = first; 
	arr[1] = second;
	for(i=2; i<=n; i++)
	{
		next = first + second;
		arr[i] = next;
		first = second;
		second = next;
	}
	printf("testing with fibonacci\n");
	for(i=0;i<n;i++)
	{
		printf("GCD of %d and %d is %d\n", arr[i], arr[i+1], gcd(arr[i], arr[i+1]));
	}	
	
}

void main()
{
	int a,b,i;
	int n;
	printf("enter numbers\n");
	scanf("%d %d", &a, &b);
	printf("GCD of %d and %d is %d\n", a, b, gcd(a,b));
	printf("range of fibonacci series?\n");
	scanf("%d",&n);
	fibonacci(n);
}	  	
