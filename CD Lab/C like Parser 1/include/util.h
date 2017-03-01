//
// util.h
//
// Utility functions
//
// Created by @avikantz on 01/26/17
//

#ifndef IMPORT_STUFF
#define IMPORT_STUFF
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#endif

#ifndef KEYWORD_COUNT
#define KEYWORD_COUNT 32
extern const char *KEYWORDS[KEYWORD_COUNT];
#endif

typedef enum { NO, YES } BOOL;

// Checks if a character is a digit (duh)
BOOL isDigit (char);

// Checks for digit, '.', or 'E'/'e'
BOOL isNumerical (char);

// Checks if a character is an alphabet (duh)
BOOL isAlphabet (char);

// Checks if a character is a valid identifier character (letter, digit, or _)
BOOL isValidID (char);

// Checks if a character is a uppercase
BOOL isLowerCase (char);

// Checks if a character is a lowercase
BOOL isUpperCase (char);

// Checks if a character is a special symbol
BOOL isSpecialSymbol (char);

// Checks if the character is start of an operator
BOOL isOperator (char);

// Returns the operator name of the operator, null if not found. E.g. "<=" is "LE" (Less than Equal to), "^" is "BXOR" (Bitwise XOR)
char *operator_name (char *);

#pragma mark - Symbol table

typedef enum token_type {
	TOKEN_TYPE_VOID,
	TOKEN_TYPE_INT,
	TOKEN_TYPE_CHAR,
	TOKEN_TYPE_FLOAT,
	TOKEN_TYPE_DOUBLE,
	TOKEN_TYPE_LONG,
	TOKEN_TYPE_SHORT,
	TOKEN_TYPE_FUNC = 89,
	TOKEN_TYPE_ID = 99,
} token_type_t;

token_type_t get_token_type(char *);
const char * get_token_type_string (token_type_t);

size_t get_token_size(token_type_t);

typedef enum token_scope {
	TOKEN_SCOPE_LOCAL,
	TOKEN_SCOPE_GLOBAL
} token_scope_t;

typedef struct st_entry {
	int id;
	char name[128];
	token_type_t type;
	size_t size;
	token_scope_t scope;
	int nargs;
	char return_type[128];	
	int args[16]; 			// Assuming no function will have more than 16 args.
} st_entry_t;

// Retruns a new symbol table entry
st_entry_t new_symbol_table_entry (char name[128], token_type_t type, size_t size, token_scope_t scope, int nargs, char return_type[128]);

typedef struct st_node {
	st_entry_t entry;
	struct st_node *next;
} st_node_t, *st_node_p_t;

st_node_p_t init_st_node (st_entry_t);

// Finds a symbol table entry by its name, returns the corresponding element; else inserts it and returns the new element
st_node_p_t find_or_insert_st (st_node_p_t *, st_entry_t, BOOL *);
st_node_p_t find_in_st (st_node_p_t *, st_entry_t);

void print_symbol_table (st_node_p_t);

#pragma mark - Token buffer

typedef struct tnode {
	char name[128];
	struct tnode *next;
	struct tnode *prev;
} tnode_t, *tnode_p_t;

tnode_p_t init_tnode (char *);
tnode_p_t insert_token (tnode_p_t *, char *);

void print_token_buffer (tnode_p_t);
