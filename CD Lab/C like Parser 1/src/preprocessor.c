//
// Discard preprocessor directives and comments from the file
//
// Created by @avikantz on 01/26/17
//

#include "preprocessor.h"

/**
*	remove_directives (char *)
*	input: <filename>
*	output: file named "pr_<filename>" with preprocessor directives and comments removed.
*/

char *remove_directives (char *inname) {

	FILE *input = fopen(inname, "r");

	char *outname = (char *)malloc(128 * sizeof(char));
	snprintf(outname, 128, "pr_%s", inname);

	FILE *output = fopen(outname, "w+");

	char ch;
	do {
		ch = getc(input); // Get character from input file.

		if (ch == '#') { // If a #if found, loop till you find the next '\n'
			
			ch = getc(input);
			if (ch == 'i' || ch == 'd' || ch == 'u' || ch == 'p') {
				while (ch != '\n') { 
					ch = getc(input);
				}
				// ch = getc(input); // If you want to delete the line too
				ungetc(ch, input);
			} else {
				putc('#', output);
				// putc(ch, output);
			}

		} else if (ch == '/') {

			ch = getc(input);

			if (ch == '/') { // Single line comments remove till the line ends.
				while (ch != '\n') {
					ch = getc(input);
				}

			} else if (ch == '*') { // Multi line comments, remove till '*/' comes.

				do {
					ch = getc(input);

					if (ch == '*') {
						ch = getc(input);
						if (ch == '/') {
							ch = getc(input);
							break;
						}
					}

				} while (YES);

			} else {
				putc('/', output);
			}
		}

		putc(ch, output);

	} while (ch != EOF);

	fclose(input);
	fclose(output);

	return outname;

}

