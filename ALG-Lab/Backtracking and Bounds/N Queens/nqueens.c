// 
// nqueens.c
// Placing n queens using backtracking
//

#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define MAX 50

typedef enum { NO, YES } BOOL;

int n;

void printBoard (int board[MAX][MAX]) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf(" %c", (board[i][j]) ? 'X': '-');
		}
		printf("\n");
	}
	printf("\n");
}

// Called when queens are placed from 0 to col - 1
BOOL isSafe (int board[MAX][MAX], int row, int col) {
	
	int i, j;
	
	// For the row check every column before this
	for (i = 0; i < col; ++i) {
		if (board[row][i])
			return NO;
	}

	// Check upper left diagonal
	for (i = row, j = col; i >= 0 && j >= 0; --i, --j) {
		if (board[i][j])
			return NO;
	}

	// Check lower left diagonal
	for (i = row, j = col; i < n && j >= 0; ++i, --j) {
		if (board[i][j])
			return NO;
	}

	return YES;

}

// Place queens in column = col
BOOL placeQueens (int board[MAX][MAX], int col) {

	if (col == n) {
		return YES; // All of the queens are placed.
	}

	// For this column, try placing all queens one by one... 

	int i;

	for (i = 0; i < n; ++i) {

		if (isSafe(board, i, col)) {

			board[i][col] = 1; // Try placing here

			if (placeQueens(board, col + 1)) { // If leads to a solution
				return YES;
			}

			board[i][col] = 0; // Backtrack

		}

	}

	return NO;

}

// int main (int argc, const char * argv []) {

// 	clock_t st, et;
// 	double tt;

// 	FILE *outfile = fopen("nqueens.csv", "w+");
// 	fprintf(outfile, "Input size, Time, Solution?\n");

// 	n = 4;
// 	int board[MAX][MAX];

// 	int i, j;

// 	do {

// 		BOOL soln;

// 		for (i = 0; i < n; ++i) {
// 			for (j = 0; j < n; ++j) {
// 				board[i][j] = 0;
// 			}
// 		}

// 		st = clock();

// 		soln = placeQueens(board, 0);

// 		et = clock();

// 		tt = (double)(et - st)/CLOCKS_PER_SEC;

// 		fprintf(outfile, "%d, %.6lf, %d\n", n, tt, soln);
// 		printf("%d, %.6lf, %d\n", n, tt, soln);

// 		n += 1;

// 	} while (n <= 24);

// 	fclose(outfile);

// }

int main (int argc, const char * argv []) {

	if (argc > 1) {
		n = atol(argv[1]);
	} else {
		printf("Enter the size of the board: ");
		scanf(" %d", &n);
	}

	int board[MAX][MAX];

	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			board[i][j] = 0;
		}
	}

	if (placeQueens(board, 0)) {
		printf("Solution exists:\n");
		printBoard(board);
	} else {
		printf("No soluton exists.\n");
	}

}
