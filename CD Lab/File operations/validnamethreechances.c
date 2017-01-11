// Gives the user three chances to enter a valid file name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef char * string;
typedef enum { NO, YES } BOOL;

BOOL isValidName(string fname) {
	// string invalidChars = "!@%^*~|\\";
	// int i;
	// for (i = 0; i < strlen(invalidChars); ++i) {
	// 	if (strchr(fname, invalidChars[i]) != NULL)
	// 		return NO;
	// }
	// return YES;
	return (access(fname, F_OK) != -1);
}

int main (int argc, const char * argv []) {

	printf("Let's play a game. Guess a file name in the current directory.\n");

	string fname = (string)malloc(128 * sizeof(char));

	int ntries = 0;
	do {
		if (ntries > 0) {
			printf("Strike %d! \n", ntries);
		}
		printf("Enter the file name%s: ", (ntries == 0)?"":" again");
		scanf(" %s", fname);
		if (isValidName(fname)) {
			printf("File '%s' exists in the directory. Woo-hoo!\n", fname);
			exit(0);
		}
		ntries += 1;
	} while (ntries < 3);

	if (!isValidName(fname)) {
		printf("You're out! You could not get a correct filename in three tries!\n");
	}

	return 0;

}