// SumList.c
// Created by @avikantz on 08/11/15

#include <stdio.h>

long sum (int list[], int n) {
	if (n == 0)
		return 0;
	return list[n-1] + sum(list, n-1);
}

int main (int argc, const char *argv []) {
	int i, n, list[100];
	printf("This program will calculate sum of a list of integers.\n\n\tEnter number of integers: ");
	scanf("%d", &n);
	printf("\n");
	for (i = 0; i < n; ++i) {
		printf("\tEnter list[%d]: ", i+1);
		scanf("%d", &list[i]);
	}
	printf("\nThe sum of above entered integers = %ld.\n\n", sum(list, n));
}