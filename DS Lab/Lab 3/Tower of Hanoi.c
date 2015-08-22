//
//  Tower of Hanoi.c
//  Tower of Hanoi
//
//  Created by Avikant Saini on 8/15/15.
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>

void towerOfHanoi(int n, char *a, char *b, char *c, int *movesCount) {
	if(n != 0) {
		*movesCount += 1;
		towerOfHanoi (n-1, a, c, b, movesCount);
		printf("\n\tMove Disk '%d' from Peg '%s' to Peg '%s'", n, a, c);
		towerOfHanoi (n-1, b, a, c, movesCount);
	}
	return;
}

int main(int argc, const char * argv[]) {
	int n, movesCount = 0;
	printf("This program will solve the tower of Hanoi problem recursively.\n\tEnter the number of pegs : ");
	scanf("%d", &n);
	printf("\n\tSolve the tower as follows: \n\n");
	towerOfHanoi (n, "A", "B", "C", &movesCount);
	printf("\n\n\t\t\tTotal number of moves = %d\n\n", movesCount);
	return 0;
}
