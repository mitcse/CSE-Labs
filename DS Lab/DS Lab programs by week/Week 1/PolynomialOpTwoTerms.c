#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **p;
	int **q;
	int **r;
	int x1, x2, y1, y2, i, j, m, n, flag;
	printf("Enter max powers of x and y in first polynomial\n");
	scanf("%d %d", &x1, &y1);
	printf("Enter max powers of x and y in second polynomial\n");
	scanf("%d %d", &x2, &y2);
	if (x1>x2)
	{
		m = x1;
	}
	else
	{
		m = x2;
	}
	if (y1>y2)
	{
		n = y1;
	}
	else
	{
		n = y2;
	}

	// Dynamic initialisation 2D arrays

	if (x1>x2)
	{
		if (y1>y2)
		{
			p = (int**) calloc(y1+1, sizeof(int*));
			q = (int**) calloc(y1+1, sizeof(int*));
			r = (int**) calloc(y1+1, sizeof(int*));
			for (i=0; i<=y1; i++)
			{
				p[i] = (int*) calloc(x1+1, sizeof(int));
				q[i] = (int*) calloc(x1+1, sizeof(int));
				r[i] = (int*) calloc(x1+1, sizeof(int));
			}
		}
		else
		{
			p = (int**) calloc(y2+1, sizeof(int*));
			q = (int**) calloc(y2+1, sizeof(int*));
			r = (int**) calloc(y2+1, sizeof(int*));
			for (i=0; i<=y2; i++)
			{
				p[i] = (int*) calloc(x1+1, sizeof(int));
				q[i] = (int*) calloc(x1+1, sizeof(int));
				r[i] = (int*) calloc(x1+1, sizeof(int));
			}
		}
	}
	else
	{
		if (y1>y2)
		{
			p = (int**) calloc(y1+1, sizeof(int*));
			q = (int**) calloc(y1+1, sizeof(int*));
			r = (int**) calloc(y1+1, sizeof(int*));
			for (i=0; i<=y1; i++)
			{
				p[i] = (int*) calloc(x2+1, sizeof(int));
				q[i] = (int*) calloc(x2+1, sizeof(int));
				r[i] = (int*) calloc(x2+1, sizeof(int));
			}
		}
		else
		{
			p = (int**) calloc(y2=1, sizeof(int*));
			q = (int**) calloc(y2+1, sizeof(int*));
			r = (int**) calloc(y2+1, sizeof(int*));
			for (i=0; i<=y2; i++)
			{
				p[i] = (int*) calloc(x2+1, sizeof(int));
				q[i] = (int*) calloc(x2+1, sizeof(int));
				r[i] = (int*) calloc(x2+1, sizeof(int));
			}
		}
	}
	printf("Enter coefficients of first polynomials\n");
	for (i=0; i<=x1; i++)
	{
		for (j=0; j<=y1; j++)
		{
		        printf("Enter coefficient of x^%dy^%d ", i, j);
		        scanf("%d", &p[i][j]);
		}
	}
	printf("Enter coefficients of second polynomial\n");
	for (i=0; i<=x2; i++)
	{
		for(j=0; j<=y2; j++)
		{
		        printf("Enter coefficient of x^%dy^%d ", i, j);
			scanf("%d", &q[i][j]);
		}
	}
	printf("Enter 1 for addition, 2 for multiplication ");
	scanf("%d", &flag);
	if (flag == 1)
	{
	        for (i=0; i<=m; i++)
		{
		        for (j=0; j<=n; j++)
			{
			       r[i][j] = p[i][j] + q[i][j];
			}
		}
	
	        printf("Sum of polynomials is\n");
		for (i=0; i<=m; i++)
		{
		        for(j=0; j<=n; j++)
			{
			       printf("%dx^%dy^%d ", r[i][j], i, j);
			}
		}
	}
	else if (flag == 2)
	{
	        for (i=0; i<=m; i++)
	        {
		        for (j=0; j<n; j++)
			{
			       r[i][j] = p[i][n] * q[m][j];
			}
		}
		printf("Coefficient of product of polynomial is\n");
		for (i=0; i<=m; i++)
		{
		        for (j=0; j<=n; j++)
		        {
			  printf("%d ", r[i][j]);
			}
		}
	}
	printf("\n");
        return 0;
}
