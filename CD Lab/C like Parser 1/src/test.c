// 
// test.c
//
// Testing the 'compiler'
//
// Created by @avikantz on 01/26/17
//

#include "preprocessor.h"
#include "lexer.h"

int main (int argc, const char * argv []) {

	char inname[128];
	if (argc < 2) {
		printf("Enter file name: ");
		scanf(" %s", inname);
	} else {
		strcpy(inname, argv[1]);
	}

	emit_tokens(inname);

	return 0;

}
