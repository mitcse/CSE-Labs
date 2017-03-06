//
// parsertwo.c
//
// Simple parser for the grammar given
//
// Created by @avikantz on 02/22/17
//

// The grammer:

/*
	program -> main () { declarations statement_list }
	declarations -> data-type identifier_list; declarations | e
	data_type -> int | char
	identifier_list -> id | id , identifier_list | id[number], identifier_list | id[number]
	statement_list -> statement statement_list | e
	statement -> assign_stat;
	assign_stat -> id = expn;
	expn -> simple_expn eprime
	eprime -> relop simple_expn | e
	simple_expn -> term seprime
	seprime -> addop term seprime | e
	term -> factor tprime
	tprime -> mulop factor tprime | e
	factor -> id | num
	relop -> == | != | <= | >= | > | <
	addop -> + | -
	mulop -> * | / | %
*/

// Sample input:

/*
	main () {
		int a;
		int arr[10];
		char b, c;
		a = a + 10;
		b = a * c;
	}
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
#define CURR_EQ(name) (strcmp(CURR, name) == 0)

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
void statement_list();
void statement();
void assign_stat();
void expn();
void eprime();
void simple_expn();
void seprime();
void term();
void tprime();
void factor();
void relop();
void addop();
void mulop();

// -------------------------

void program() {
	LOG_CURRENT;
	IF_CURR_EQ("<main>") {
		i += 1;
		LOG_CURRENT;
		IF_CURR_EQ("<(>") {
			i += 1;
			LOG_CURRENT;
			IF_CURR_EQ("<)>") {
				i += 1;
				LOG_CURRENT;
				IF_CURR_EQ("<{>") {
					i += 1;
					LOG_CURRENT;
					declarations();
					statement_list();
					IF_CURR_EQ("<}>") {
						i += 1;
						LOG_CURRENT;
						if (i == k-1) {
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
	if (CURR_EQ("<int>") || CURR_EQ("<char>")) {
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
	if (CURR_EQ("<int>") || CURR_EQ("<char>")) {
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
			identifier_list();
		} else IF_CURR_EQ("<[>") {
			i += 1;
			LOG_CURRENT;
			IF_CURR_EQ("<num>") {
				i += 1;
				LOG_CURRENT;
	 			IF_CURR_EQ("<]>") {
	 				i += 1;
	 				LOG_CURRENT;
					IF_CURR_EQ("<,>") {
						i += 1;
						identifier_list();
					} else {
						return;
					}
				} else {
					ERROR_HANDLER;
				}
			} else {
				ERROR_HANDLER;
			}
		}
	}
}

void statement_list() {
	LOG_CURRENT;
	statement();
	IF_CURR_EQ("<id>") {
		statement_list();
	}
}

void statement() {
	LOG_CURRENT;
	IF_CURR_EQ("<id>") {
		assign_stat();
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
			expn();
			LOG_CURRENT;
			IF_CURR_EQ("<;>") {
				i += 1;
				LOG_CURRENT;
				return;
			}
		} else {
			ERROR_HANDLER;
		}
	}
}

void expn() {
	LOG_CURRENT;
	if (CURR_EQ("<id>") || CURR_EQ("<num>")) {
		simple_expn();
		eprime();
	} else {
		ERROR_HANDLER;
	}
}

void eprime() {
	LOG_CURRENT;
	if (CURR_EQ("<==>") || CURR_EQ("<!=>") || CURR_EQ("<<=>") || CURR_EQ("<>=>") || CURR_EQ("<<>") || CURR_EQ("<>>")) {
		relop();
		simple_expn();
	}
}

void simple_expn() {
	LOG_CURRENT;
	if (CURR_EQ("<id>") || CURR_EQ("<num>")) {
		term();
		seprime();
	}
}

void seprime() {
	LOG_CURRENT;
	if (CURR_EQ("<+>") || CURR_EQ("<->")) {
		addop();
		term();
		seprime();
	}
}

void term() {
	LOG_CURRENT;
	if (CURR_EQ("<id>") || CURR_EQ("<num>")) {
		factor();
		tprime();
	} else {
		ERROR_HANDLER;
	}
}

void tprime() {
	LOG_CURRENT;
	if (CURR_EQ("<*>") || CURR_EQ("</>") || CURR_EQ("<%>")) {
		mulop();
		factor();
		tprime();
	}
}

void factor() {
	LOG_CURRENT;
	if (CURR_EQ("<id>") || CURR_EQ("<num>")) {
		i += 1;
		LOG_CURRENT;
	} else {
		ERROR_HANDLER;
	}
}

void relop() {
	LOG_CURRENT;
	if (CURR_EQ("<==>") || CURR_EQ("<!=>") || CURR_EQ("<<=>") || CURR_EQ("<>=>") || CURR_EQ("<<>") || CURR_EQ("<>>")) {
		i += 1;
		LOG_CURRENT;
	} else {
		ERROR_HANDLER;
	}
}

void addop() {
	LOG_CURRENT;
	if (CURR_EQ("<+>") || CURR_EQ("<->")) {
		i += 1;
		LOG_CURRENT;
	} else {
		ERROR_HANDLER;
	}
}

void mulop() {
	LOG_CURRENT;
	if (CURR_EQ("<*>") || CURR_EQ("</>") || CURR_EQ("<%>")) {
		i += 1;
		LOG_CURRENT;
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