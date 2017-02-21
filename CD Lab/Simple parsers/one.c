//
// parsertwo.c
//
// Simple parser for the grammar given
//
// Created by @avikantz on 02/15/17
//

/**

S  -> a | -> | ( T )
T  -> S T'
T' -> , S T' | e

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 256

#define SUCCESS_HANDLER printf("%s(): Success.\n", __PRETTY_FUNCTION__); exit(1);
#define ERROR_HANDLER printf("%s(): Error occured.\n", __PRETTY_FUNCTION__); exit(1);

#define LOG_CURRENT printf("--> %s: %s\n", __PRETTY_FUNCTION__, input[i]);

#define CURR input[i]

const char delimiters[] = " ";

char buffer[BUFFER_SIZE];
char input[BUFFER_SIZE][BUFFER_SIZE];	// Input array?
int k = 0;	// Total no of tokens
int i = 0; 	// Current token read...

// -------------------------

void S ();
void T ();
void T1 ();

// -------------------------

void S () {
	LOG_CURRENT;
	if (strcmp(input[i], "a") == 0) {
		i += 1;
	} else if (strcmp(input[i], "->") == 0) {
		i += 1;
	} else if (strcmp(input[i], "(") == 0) {
		i += 1;
		T();
		if (strcmp(input[i], ")") == 0) {
			i += 1;
		}
	} else {
		ERROR_HANDLER;
	}
	if (strcmp(input[i], "$") == 0) {
		SUCCESS_HANDLER;
	}
}

void T () {
	LOG_CURRENT;
	S();
	T1();
}

void T1 () {
	LOG_CURRENT;
	if (strcmp(input[i], ",") == 0) {
		i += 1;
		S();
		T1();
	} else {
		return;
	}
}

// ----------------------------

void parse_input (char *inname) {

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
			// printf("%s - ", input[k-1]);
		}

	} while (token != NULL);
	strcpy(input[k++], "$");

	S();

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

	printf("%s\n", inname);

	parse_input(inname);

	return 0;
}