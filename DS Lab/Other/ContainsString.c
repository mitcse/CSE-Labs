//
//	ContainsString.c
//	Check if a string contains another string.
//
//	Created by Avikant Saini on 11/14/15
//  Copyright © 2015 avikantz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
#define initString(size) (char *)malloc(size * sizeof(char));

typedef char * String;

typedef enum { NO, YES } BOOL;

BOOL containsString (String string, String substring) {
	String tstr = string;
	String tsub = substring;
	String tsubend = substring + strlen(substring);
	while (*tstr != '\0') {
		while (*tsub != '\0' && *tstr == *tsub) {
			tstr++;
			tsub++;
		}
		if (tsub == tsubend)
			return YES;
		else
			tsub = substring;
		tstr++;
	}
	return NO;
}

#pragma mark - Main

int main (int argc, const char * argv []) {
	
	char ch;
	String string = initString(SIZE);
	String substring = initString(SIZE);
	do {
		printf("\n\tEnter the string: ");
		scanf(" %s", string);
		printf("\tEnter the substring: ");
		scanf(" %s", substring);
		
		if (containsString(string, substring))
			printf("\n\t'%s' is contained in '%s'.", substring, string);
		else
			printf("\n\t'%s' is not present in '%s'.", substring, string);
		
		printf("\n\tContinue (y/n): ");
		scanf(" %c", &ch);
		
	} while (ch == 'y');
	
	printf("\n\n");
	
}