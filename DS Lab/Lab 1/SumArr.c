//
//  main.c
//  SumArr
//
//  Created by Avikant Saini on 8/10/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>

int sumArr (int a[], int n) {
	int sum = 0, i;
	for (i = 0; i < n; ++i)
		sum += a[i];
	return sum;
}

int main(int argc, const char * argv[]) {
	// insert code here...
	int list[100], n, i;
	printf("Enter the number of integers: ");
	scanf("%d", &n);
	printf("\nEnter %d integers: ", n);
	for (i = 0; i < n; ++i)
		scanf("%d", &list[i]);
	
	printf("\nThe sum of integers inputted above = %d", sumArr(list, n));
	return 0;
}
