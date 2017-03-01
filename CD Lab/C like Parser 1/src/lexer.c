//
// lexer.c
//
// Lexical analyzer, generates symbol table
//
// Created by @avikantz on 01/27/17
//

#define PRINT_CODE YES
#define DEBUG_MODE NO

#include "lexer.h"

BOOL isKeyword (char buffer[BUFFER_SIZE]) {
	int i;
	for (i = 0; i < KEYWORD_COUNT; ++i) {
		if (strcmp(KEYWORDS[i], buffer) == 0)
			return YES;
	}
	return NO;
}

BOOL isDataType (char buffer[BUFFER_SIZE]) {
	int i;
	for (i = 0; i < 7; ++i) {
		if (strcmp(KEYWORDS[i], buffer) == 0)
			return YES;
	}
	return NO;
}

void emit_tokens (char *inname) {

	FILE *input = fopen(inname, "r");

	char outname[128];
	snprintf(outname, 128, "out.txt");
	FILE *output = fopen(outname, "w+");

	char ch, lch;
	char buffer[BUFFER_SIZE]; int k = 0;

	int scope_flag = 0;
	int nargs = 0;

	do {
		
		ch = getc(input);

		if (ch == ' ' || ch == '\t') { // Simply discard the blank space

			if (ch == '\t') {
				if (PRINT_CODE) printf("\t");
				fprintf(output, "\t");
			}

		} else if (ch == '\n') { // Put the next line on the output buffer
	
			if (PRINT_CODE) printf("\n");
			fprintf(output, "\n");
		
		} else if (ch == '\"' && lch != '\\') { // Wait till the string ends
			
			k = 0;
			buffer[k++] = ch;
			
			do {
				ch = getc(input);
				buffer[k++] = ch;
			} while (ch != '\"');
			
			buffer[k++] = EOS;

			if (PRINT_CODE) printf("<str> ");
			fprintf(output, "<str> ");

		} else if (ch == '\'' && lch != '\\') { // Wait till the character stream ends
			
			k = 0;
			
			do {
				ch = getc(input);
				buffer[k++] = ch;
			} while (ch != '\'');
			
			buffer[k-1] = EOS; // Don't want "'" in there.

			if (PRINT_CODE) printf("<char> ");
			fprintf(output, "<char> ");

		} else if (isAlphabet(ch)) { // Take the identifier...

			k = 0;

			while (isValidID(ch)) {
				buffer[k++] = ch;
				ch = getc(input);
				if (k > BUFFER_SIZE) {
					printf("Error: Buffer overflow (isAlphabet)! %s\n", buffer);
					return;
				}
			}
			ungetc(ch, input); // Put the last character back in the buffer, cause the while loop takes one more
			buffer[k++] = EOS;

			// Check for keywords here.
			if (isKeyword(buffer)) {
				
				if (PRINT_CODE) printf("<%s> ", buffer);
				fprintf(output, "<%s> ", buffer);

			} else {

				if (PRINT_CODE) printf("<id> ");
				fprintf(output, "<id> ");

			}

		} else if (isDigit(ch)) { // Take the numbers separately

			k = 0;
			while (isNumerical(ch)) {
				buffer[k++] = ch;
				ch = getc(input);
				if (k > BUFFER_SIZE) {
					printf("Error: Buffer overflow (isDigit): %s\n", buffer);
					return;
				}
			}
			ungetc(ch, input); // Put the last character back in the buffer, cause the while loop takes one more
			buffer[k++] = EOS;
			if (PRINT_CODE) printf("<num> ");
			fprintf(output, "<num> ");

		} else if (isSpecialSymbol(ch)) {

			if (PRINT_CODE) printf("<%c> ", ch); // Just print the god damn special symbol
			fprintf(output, "<%c> ", ch);

		} else if (isOperator(ch)) {

			k = 0;
			while (isOperator(ch) || ch == ' ' || ch == '\t') { // To detect terms like "< =" 
				if (isOperator(ch)) {
					buffer[k++] = ch;
				}
				ch = getc(input);
			}
			buffer[k++] = EOS;
			ungetc(ch, input); // Put the last character back in the buffer, cause the while loop takes one more

			char *opname = operator_name(buffer);
			if (opname != NULL) {
				if (PRINT_CODE) printf("<%s> ", buffer);
				fprintf(output, "<%s> ", buffer);
			}

		}

		lch = ch;

	} while (ch != EOF);

}