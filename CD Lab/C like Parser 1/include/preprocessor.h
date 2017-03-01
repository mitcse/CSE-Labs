//
// preprocessor.h
//
// Discard preprocessor directives and comments from the file
//
// Created by @avikantz on 01/26/17
//

#ifndef COMMON_H
#define COMMON_H
#include "common.h"
#endif

/**
*	remove_directives (char *)
*	input: <filename>
*	output: file named "pr_<filename>" with preprocessor directives and comments removed.
*	return: file name "pr_<filename>"
*/
char *remove_directives (char *);
