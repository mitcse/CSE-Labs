//
//  Postfix.c
//  Evaulation of Postfix Operation
//
//  Created by Avikant Saini on 8/30/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define INT_MAX 32767

int main(int argc, const char * argv[]) {
	
	int i, j, n, m;
	
	printf("\n\tEnter number of rows: ");
	scanf("%d", &n);
	
	int ** arr = (int **)calloc(n + 1, sizeof(int *));
	
	for (i = 0; i < n; ++i) {
	
		printf("\n\tEnter number of elements in row %d : ", i+1);
		scanf("%d", &m);
		
		*(arr + i) = (int *)calloc(m + 2, sizeof(int));
		
		*(*(arr + i) + 0) = m;
		
		int min = INT_MAX;
		for (j = 2; j < m + 2; ++j) {
			int element;
			printf("\n\tEnter element %d of row %d: ", j-1, i+1);
			
			scanf("%d", &element);
			*(*(arr + i) + j) = element;
			
			if (element < min)
				min = element;
		}
		*(*(arr + i) + 1) = min;
	}
	
	printf("\n\n");
	
	int row;
	printf("\n\tEnter the row you want minimum element from: ");
	scanf("%d", &row);
	
	printf("\n\tArray: \n");
	for(i = 0; i < n; ++i) {
		m = *(*(arr + i) + 0);
		for (j = 2; j < m + 2; ++j)
			printf ("\t%d", *(*(arr + i) + j));	
		printf("\t |:| %d\n", *(*(arr + i) + 1));
	}
	
	printf("\n\tThe minimum element in row %d = ", row);
	m = *(*(arr + row - 1) + 0);
	printf ("\t%d", *(*(arr + row - 1) + 1));
	
	printf("\n\n");
	
	return 0;
}
