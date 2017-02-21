//
// parserone.c
//
// Simple parser for the grammar given
//
// Created by @avikantz on 02/15/17
//

/**

E ->	num T
T -> 	* num T | e

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 256

#define SUCCESS_HANDLER printf("%s: Success.\n", __PRETTY_FUNCTION__); exit(1);
#define ERROR_HANDLER printf("%s: Error occured.\n", __PRETTY_FUNCTION__); exit(1);

const char delimiters[] = " ";

char buffer[BUFFER_SIZE];
char input[BUFFER_SIZE][BUFFER_SIZE];	// Input array?
int k = 0;	// Total no of tokens
int i = 0; 	// Current token read...

// -------------------------

void E();
void T();

// -------------------------

void E () {
	if (strcmp(input[i], "num") == 0) {
		i += 1;
		T();
	} else {
		ERROR_HANDLER;
	}
	if (strcmp(input[i], "$") == 0) {
		SUCCESS_HANDLER;
	}
}

void T () {
	if (strcmp(input[i], "*") == 0) {
		i += 1;
		if (strcmp(input[i], "num") == 0) {
			i += 1;
			T();
		} else {
			ERROR_HANDLER;
		}
	} else {
		
	}
}

// ----------------------------

void parse_input_one (char *inname) {

	strcpy(buffer, inname);

	// Make a temp copy of the string
	char *cp = (char *)malloc(BUFFER_SIZE * sizeof(char));
	strcpy(cp, buffer);

	char *token = (char *)malloc(256 * sizeof(char));

	do {
		// strsep - extract token from string, returns null if token is not found.
		token = strsep(&cp, delimiters);
		if (token != NULL) {
			strcpy(input[k++], token);
			// printf("%s,", input[k-1]);
		}

	} while (token != NULL);
	strcpy(input[k++], "$");

	E();

}

int main (int argc, char const *argv[]) {
	
	char *inname = (char *)malloc(128 * sizeof(char));
	if (argc < 2) {
		printf("Enter input: ");
		fgets(inname, BUFFER_SIZE, stdin);
		inname[strlen(inname) - 1] = '\0';
	} else {
		strcpy(inname, argv[1]);
	}

	parse_input_one(inname);

	return 0;
}