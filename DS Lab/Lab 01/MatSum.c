//
//  main.c
//  MatSum
//
//  Created by Avikant Saini on 8/10/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>

void printMat(char name[50], int a[100][100], int r, int c) {
	printf("\n%s\n", name);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j)
			printf("\t%d", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

void inputMat(char name[50], int a[100][100], int r, int c) {
	printf("\n");
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			printf("Enter %s(%d, %d): ", name, i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n");
}

void addMat(int a[100][100], int b[100][100], int s[100][100], int r, int c) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			s[i][j] = a[i][j] + b[i][j];
		}
	}
}

int main(int argc, const char * argv[]) {
	int a[100][100], b[100][100], s[100][100], ar, ac, br, bc;
	printf("Enter dimensions of matrix A : ");
	scanf("%d%d", &ar, &ac);
	inputMat("A", a, ar, ac);
	
	printf("\nEnter dimensions of matrix B : ");
	scanf("%d%d", &br, &bc);
	inputMat("B", b, br, bc);
	
	if(ar != br || ac != bc) {
		printf("\nCannot be added!");
		return 9;
	}
	
	
	addMat(a, b, s, ar, ac);
	
	printMat("Matrix A", a, ar, ac);
	printMat("Matrix B", b, br, bc);
	printMat("Matrix S = Mat A + Mat B", s, ar, ac);
	
    return 0;
}
