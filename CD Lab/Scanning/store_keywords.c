// Recognize keywords in 'C' program.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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

int existsInArray (char foundKeywords[256][256], int fk, char *word) {
	int i;
	for (i = 0; i < fk; ++i) {
		if (strcmp(word, foundKeywords[i]) == 0)
			return 1;
	}
	return 0;
}

int main (int argc, const char * argv []) {

	char inname[128];
	printf("Enter input filename: ");
	scanf(" %s", inname);

	FILE *input = fopen(inname, "r");

	char foundKeywords[256][256];
	int fk = 0;

	char buffer[1024];
	int k;
	while (fgets(buffer, 1024, input) > 0) {
		char *cp = (char *)malloc(1024 * sizeof(char));
		strcpy(cp, buffer);
		if (strlen(cp) < 2)
			continue;
		char *token = (char *)malloc(256 * sizeof(char));
		do {
			token = strsep(&cp, delimiters);
			if (token != NULL) {
				if (isKeyword(token)) {
					if (!existsInArray(foundKeywords, fk, token)) {
						strcpy(foundKeywords[fk++], token);
					}
				}
			}
		} while (token != NULL);
	}

	printf("Keywords found: \n");
	int i;
	for (i = 0; i < fk; ++i) {
		printf("%s\n", foundKeywords[i]);
	}

	fclose(input);

	return 0;

}