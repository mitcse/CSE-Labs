//
// parsertwo.c
//
// Simple parser for the grammar given
//
// Created by @avikantz on 02/22/17
//

/**

program -> main () { declarations assign_stat }
declarations -> data-type identifier_list; declarations | e
data_type -> int | char
identifier_list -> id | id , identifier_list
assign_stat -> id = id; | id = num;

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

#define IF_CURR_EQ(name) if (strcmp(CURR, name) == 0)

#define CURR input[i]

const char delimiters[] = " ";

char buffer[BUFFER_SIZE];
char input[BUFFER_SIZE][BUFFER_SIZE];	// Input array?
int k = 0;	// Total no of tokens
int i = 0; 	// Current token read...

// -------------------------

void program();
void declarations();
void data_type();
void identifier_list();
void assign_stat();

// -------------------------

void program() {
	IF_CURR_EQ("<main>") {
		i += 1;
		IF_CURR_EQ("<(>") {
			i += 1;
			IF_CURR_EQ("<)>") {
				i += 1;
				IF_CURR_EQ("<{>") {
					i += 1;
					declarations();
					assign_stat();
					IF_CURR_EQ("<}>") {
						// i += 1;
						printf("%s\n", input[i]);
						IF_CURR_EQ("$") {
							SUCCESS_HANDLER;
						}
					} else {
						ERROR_HANDLER;
					}
				} else {
					ERROR_HANDLER;
				}
			} else {
				ERROR_HANDLER;
			}
		} else {
			ERROR_HANDLER;
		}
	} else {
		ERROR_HANDLER;
	}
}

void declarations() {
	LOG_CURRENT;
	if (strcmp(CURR, "<int>") == 0 || strcmp(CURR, "<char>") == 0) {
		data_type();
		identifier_list();
		IF_CURR_EQ("<;>") {
			i += 1;
			LOG_CURRENT;
			declarations();
		} else {
			ERROR_HANDLER;
		}
	}
}

void data_type() {
	LOG_CURRENT;
	if (strcmp(CURR, "<int>") == 0 || strcmp(CURR, "<char>") == 0) {
		i += 1;
		LOG_CURRENT;
	} else {
		ERROR_HANDLER;
	}
}

void identifier_list() {
	LOG_CURRENT;
	IF_CURR_EQ("<id>") {
		i += 1;
		LOG_CURRENT;
		IF_CURR_EQ("<,>") {
			i += 1;
			LOG_CURRENT;
			identifier_list();
		}
	}
}

void assign_stat() {
	LOG_CURRENT;
	IF_CURR_EQ("<id>") {
		i += 1;
		LOG_CURRENT;
		IF_CURR_EQ("<=>") {
			i += 1;
			LOG_CURRENT;
			if (strcmp(CURR, "<id>") == 0 || strcmp(CURR, "<num>") == 0) {
				i += 1;
				LOG_CURRENT;
				IF_CURR_EQ("<;>") {
					i += 1;
					LOG_CURRENT;
					return;
				} else {
					ERROR_HANDLER;
				}
			} else {
				ERROR_HANDLER;
			}
		} else {
			ERROR_HANDLER;
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
	strcpy(input[k++], "$");

	program();

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