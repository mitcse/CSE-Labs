// Discard blanks from a file

#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char * argv []) {

	char inname[128];
	printf("Enter input filename: ");
	scanf(" %s", inname);

	FILE *input = fopen(inname, "r");

	char outname[128];
	snprintf(outname, 128, "sr_%s", inname);

	FILE *output = fopen(outname, "w+");

	char ch;
	do {
		ch = getc(input); // Get character from input file.
		if (ch != ' ' && ch != '\n' && ch != '\r') {
			putc(ch, output); // Put if not a space, next line or return.
		}
	} while (ch != EOF);

	fclose(input);
	fclose(output);

	return 0;

}