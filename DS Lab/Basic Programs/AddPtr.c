// AddPtr.c
// Created by @avikantz on 08/11/15

#include <stdio.h>

void add(int *a, int *b, int *s) {
	*s = *a + *b;
}

int main(int argc, const char *argv[]) {
	int a, b, s;
	printf("Enter two numbers: ");
	scanf("%d%d", &a, &b);
	add(&a, &b, &s);
	printf("\n\t%d + %d = %d\n\n", a, b, s);
	return 0;
} 
