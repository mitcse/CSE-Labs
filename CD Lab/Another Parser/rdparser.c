//
// parserfour.c
//
// Simple parser for the grammar given
//
// Created by @avikantz on 02/22/17
//

// The grammer:

/*
	start -> SUBSTRACT idnum from_clause
	idnum -> term, idnum | term
	term -> id | num
	from_clause -> FROM identifier
	identifier -> id, identifier | id
*/

// Sample input:

/*
	SUBSTRACT abc, 100, apple FROM beats, balls
*/


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 512

#define SUCCESS_HANDLER printf("%s(): Success.\n", __PRETTY_FUNCTION__); exit(0);
#define ERROR_HANDLER printf("%s(): Error occured.\n", __PRETTY_FUNCTION__); exit(1);

#define LOG_CURRENT printf("--> %s: %s\n", __PRETTY_FUNCTION__, input[i]);

#define IF_CURR_EQ(name) if (strcmp(CURR, name) == 0)
#define CURR_EQ(name) (strcmp(CURR, name) == 0)

#define CURR input[i]

const char delimiters[] = " ";

char buffer[BUFFER_SIZE];
char input[BUFFER_SIZE][BUFFER_SIZE];	// Input array?
int k = 0;	// Total no of tokens
int i = 0; 	// Current token read...

// -------------------------

void start();
void idnum();
void term();
void from_clause();
void identifier();

void start() {
	LOG_CURRENT;
	IF_CURR_EQ("<SUBSTRACT>") {
		i += 1;
		LOG_CURRENT;
		idnum();
		from_clause();
		LOG_CURRENT;
		if (i == k-1) {
			SUCCESS_HANDLER;
		} else {
			ERROR_HANDLER;
		}
	} else {
		ERROR_HANDLER;
	}
}

void idnum() {
	LOG_CURRENT;
	term();
	LOG_CURRENT;
	IF_CURR_EQ("<,>") {
		i += 1;
		LOG_CURRENT;
		idnum();
	}
}

void term() {
	LOG_CURRENT;
	if (CURR_EQ("<id>") || CURR_EQ("<num>")) {
		i += 1;
		LOG_CURRENT;
	} else {
		ERROR_HANDLER;
	}
}

void from_clause() {
	LOG_CURRENT;
	IF_CURR_EQ("<FROM>") {
		i += 1;
		LOG_CURRENT;
		identifier();
	} else {
		ERROR_HANDLER;
	}
}

void identifier() {
	LOG_CURRENT;
	IF_CURR_EQ("<id>") {
		i += 1;
		LOG_CURRENT;
		IF_CURR_EQ("<,>") {
			i += 1;
			LOG_CURRENT;
			identifier();
		}
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
	strcpy(input[k], "$");

	start();

}

int main (int argc, char const *argv[]) {

	char *inname = (char *)malloc(BUFFER_SIZE * sizeof(char));
	int k = 0;

	// File from the output of the lexer

	FILE *infile = fopen("out.txt", "r");
	char ch;

	do {
		ch = getc(infile);
		if (ch == '\n' || ch == '\t')
			inname[k++] = ' ';
		else
			inname[k++] = ch;
	} while (ch != EOF);

	printf("%s\n", inname);

	parse_input(inname);

	return 0;
}
