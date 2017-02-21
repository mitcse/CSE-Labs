//
// parsertwo.c
//
// Simple parser for the grammar given
//
// Created by @avikantz on 02/15/17
//

/**



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

const char delimiters[] = " ";

char buffer[BUFFER_SIZE];
char input[BUFFER_SIZE][BUFFER_SIZE];	// Input array?
int k = 0;	// Total no of tokens
int i = 0; 	// Current token read...

// -------------------------

void E ();
void E1 ();
void T ();
void T1();
void F ();

// -------------------------

void E () {
	T();
	E1();
	if (strcmp(input[i], "$") == 0) {
		SUCCESS_HANDLER;
	}
}

void E1 () {
	LOG_CURRENT;
	if (strcmp(input[i], "+") == 0) {
		i += 1;
		T();
		E1();
	} else {
		return;
	}
}

void T () {
	LOG_CURRENT;
	F();
	T1();
}

void T1 () {
	LOG_CURRENT;
	if (strcmp(input[i], "*") == 0) {
		i += 1;
		F();
		T1();
	} else {
		return;
	}
}

void F () {
	LOG_CURRENT;
	if (strcmp(input[i], "(") == 0) {
		i += 1;
		E();
		if (strcmp(input[i], ")") == 0) {
			i += 1;
		}
	} else if (strcmp(input[i], "id") == 0) {
		i += 1;
	} else {
		ERROR_HANDLER;
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
		if (token != NULL && strlen(token) > 0) {
			strcpy(input[k++], token);
			// printf("%s || ", input[k-1]);
		}

	} while (token != NULL);
	strcpy(input[k++], "$");

	E();

}

int main (int argc, char const *argv[]) {
	
	char *inname = (char *)malloc(128 * sizeof(char));

	FILE *infile = fopen("out.txt", "r");
	fgets(inname, BUFFER_SIZE, infile);
	inname[strlen(inname) - 1] = '\0';

	printf("%s\n", inname);

	parse_input(inname);

	return 0;
}