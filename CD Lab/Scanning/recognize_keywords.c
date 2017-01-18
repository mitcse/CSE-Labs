// Recognize keywords in 'C' program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

// List of tokens
const char *keywords[32] = {
	"auto",
	"double",
	"int",
	"struct",
	"break",
	"else",
	"long",
	"switch",
	"case",
	"enum",
	"register",
	"typedef",
	"char",
	"extern",
	"return",
	"union",
	"continue",
	"for",
	"signed",
	"void",
	"do",
	"if",
	"static",
	"while",
	"default",
	"goto",
	"sizeof",
	"volatile",
	"const",
	"float",
	"short",
	"unsigned"
};

// list of delimiters
const char delimiters[] = " .,;:!-()\n\t";

int isKeyword (char *word) {
	int i;
	for (i = 0; i < 32; ++i) {
		if (strcmp(word, keywords[i]) == 0) {
			return 1;
		}
	}
	return 0;
}

void printUpperCase (char *word) {
	int l = strlen(word);
	char z;
	int i;
	for (i = 0; i < l; ++i) {
		z = word[i];
		printf("%c", z > 96 ? z - 32 : z);
	}
	printf("\n");
}

int main (int argc, const char * argv []) {

	char inname[128];
	printf("Enter input filename: ");
	scanf(" %s", inname);

	FILE *input = fopen(inname, "r");

	char buffer[1024];
	int k;

	while (fgets(buffer, 1024, input) > 0) {

		// Make a temp copy of the string
		char *cp = (char *)malloc(1024 * sizeof(char));
		strcpy(cp, buffer);
			
		char *token = (char *)malloc(256 * sizeof(char));

		do {
			// strsep - extract token from string, returns null if token is not found.
			token = strsep(&cp, delimiters);
			if (token != NULL) {
				if (isKeyword(token)) {
					printUpperCase(token);
				}
			}

		} while (token != NULL);
	}

	fclose(input);

	return 0;

}
