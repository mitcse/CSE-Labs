#include<stdio.h>

long moves = 0;

void tower (int n, char from, char intermediate, char to)
{
	moves++;
	if (n == 1)
	{
		printf("Move disc 1 from %c to %c\n", from, to);
		return;
	}
	else
	{
		tower (n-1, from, to, intermediate);
		printf("Move disc %d from %c to %c\n", n, from, to);
		tower (n-1, intermediate, from, to);
	}
}

int main()
{
	int n;
	printf("Enter number of discs\n");
	scanf("%d", &n);
	tower(n, 'A', 'B', 'C');
	printf("Total moves taken is %li\n", moves);
	return 0;
}
