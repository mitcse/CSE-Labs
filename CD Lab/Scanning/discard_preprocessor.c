// Discard preprocessor directives from a file

#include <stdio.h>
#include <stdlib.h>

int main (int argc, const char * argv []) {

	char inname[128];
	printf("Enter input filename: ");
	scanf(" %s", inname);

	FILE *input = fopen(inname, "r");

	char outname[128];
	snprintf(outname, 128, "pr_%s", inname);

	FILE *output = fopen(outname, "w+");

	char ch;
	do {
		ch = getc(input); // Get character from input file.
		if (ch == '#') { // If a #if found, loop till you find the next '\n'
			while (ch != '\n') { 
				ch = getc(input);
			}
			// ch = getc(input); // If you want to delete the line too
		}
		putc(ch, output);
	} while (ch != EOF);

	fclose(input);
	fclose(output);

	return 0;

}