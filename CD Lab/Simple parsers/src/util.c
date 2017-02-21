// 
// util.c
//
// Utility functions
// 
// Created by @avikantz on 01/26/17
//

#include "util.h"

const char *KEYWORDS[KEYWORD_COUNT] = {
	"void", 	"int",		"char",		"float",	"double",	"long",		"short",	"switch",	
	"case",		"enum",		"register",	"break",	"typedef",	"extern",	"return",	"union",	
	"continue",	"for",		"signed",	"auto",		"do",		"if",		"else",		"while",	
	"default",	"goto",		"sizeof",	"volatile",	"const",	"float",	"static",	"unsigned"
};

#pragma mark - Utility functions

BOOL isDigit (char ch) {
	return (ch >= '0' && ch <= '9');
}

BOOL isNumerical (char ch) {
	return (isDigit(ch) || ch == '.' || ch == 'e' || ch == 'E');
}

BOOL isAlphabet (char ch) {
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

BOOL isValidID (char ch) {
	return (isDigit(ch) || isAlphabet(ch) || ch == '_');
}

BOOL isLowerCase (char ch) {
	return (ch >= 'a' || ch <= 'z'); 
}

BOOL isUpperCase (char ch) {
	return (ch >= 'A' && ch <= 'Z'); 
}

const char *SPECIALSYMBOLS = "[]{}(),;:.#";

BOOL isSpecialSymbol (char ch) {
	return (strchr(SPECIALSYMBOLS, ch) != NULL);
}

const char *OPERATORS = "+-*/%<>=!&|^~";

BOOL isOperator (char ch) {
	return (strchr(OPERATORS, ch) != NULL);
}

const char *OPERATOR_NAMES[52] = {
	"+", 	"ADD",
	"-",	"SUB",
	"*",	"MUL",
	"/",	"DIV",
	"%",	"MOD",
	"+=",	"ADD ASS",
	"-=",	"SUB ASS",
	"*=",	"MUL ASS",
	"/=",	"DIV ASS",
	"%=",	"MOD ASS",
	"=",	"ASS",
	">",	"GT",
	"<",	"LT",
	"!",	"NOT",
	">=",	"GE",
	"<=",	"LE",
	"==",	"EQ",
	"!=",	"NE",
	"&",	"BAND",
	"|",	"BOR",
	"~",	"BNOT",
	"^",	"BXOR",
	">>",	"BRS",
	"<<",	"BLS",
	"&&",	"LAND",
	"||",	"LOR"
};

char *operator_name (char *op) {
	int i;
	char *opname = (char *)malloc(10 * sizeof(char));
	for (i = 0; i < 2 * 26; i += 2) {
		if (strcmp(OPERATOR_NAMES[i], op) == 0) {
			strcpy(opname, OPERATOR_NAMES[i+1]);
			return opname;
		}
	}
	return NULL;
}

token_type_t get_token_type (char *keyword) {
	int i = 0;
	for (i = 0; i < KEYWORD_COUNT; ++i) {
		if (strcmp(keyword, KEYWORDS[i]) == 0) {
			return i;
		}
	}
	return TOKEN_TYPE_ID;
}

const char * get_token_type_string (token_type_t type) {
	if (type == TOKEN_TYPE_FUNC)
		return "FUNC";
	if (type <= TOKEN_TYPE_SHORT)
		return KEYWORDS[type];
	return "-";
}

size_t get_token_size (token_type_t type) {
	switch (type) {
		case TOKEN_TYPE_INT: 
		case TOKEN_TYPE_FLOAT: return 4;
		case TOKEN_TYPE_CHAR: return 1;
		case TOKEN_TYPE_SHORT: return 2;
		case TOKEN_TYPE_LONG: 
		case TOKEN_TYPE_DOUBLE: return 8;
		case TOKEN_TYPE_VOID: return 0;
		default: return 0;
	}
}

#pragma mark - Symbol table entries

st_entry_t new_symbol_table_entry (char name[128], token_type_t type, size_t size, token_scope_t scope, int nargs, char return_type[128]) {
	st_entry_t entry;
	strcpy(entry.name, name);
	entry.type = type;
	entry.size = size;
	entry.scope = scope;
	entry.nargs = nargs;
	strcpy(entry.return_type, return_type);
	return entry;
}

st_node_p_t init_st_node (st_entry_t entry) {
	st_node_p_t node = (st_node_p_t)malloc(sizeof(st_node_t));
	node->entry = entry;
	node->next = NULL;
	return node;
}

// Finds a symbol table entry by its name, inserts it otherwise
st_node_p_t find_or_insert_st (st_node_p_t *head, st_entry_t entry, BOOL *inserted) {
	if (*head == NULL) {
		*head = init_st_node(entry);
		(*head)->entry.id = 1;
		*inserted = YES;
		return *head; // Only one node, currently inserted.
	}
	int id = 1;
	st_node_p_t temp = *head;
	while (temp->next != NULL) {
		if (strcmp(temp->entry.name, entry.name) == 0 /*&& temp->entry.scope == entry.scope*/) {
			*inserted = NO;
			return temp;
		}
		temp = temp->next;
		id = temp->entry.id;
	}
	if (strcmp(temp->entry.name, entry.name) == 0 /*&& temp->entry.scope == entry.scope*/) {
		*inserted = NO;
		return temp;
	}
	if (id > 0) {
		temp->next = init_st_node(entry);
		temp->next->entry.id = id + 1;
		*inserted = YES;
		return temp->next;
	} else {
		*inserted = NO;
		return NULL;
	}
}

// Finds a symbol table entry by its name, inserts it otherwise
st_node_p_t find_in_st (st_node_p_t *head, st_entry_t entry) {
	if (*head == NULL) {
		return NULL;
	}
	st_node_p_t temp = *head;
	while (temp->next != NULL) {
		if (strcmp(temp->entry.name, entry.name) == 0  /*&& temp->entry.scope == entry.scope*/) {
			return temp;
		}
		temp = temp->next;
	}
	if (strcmp(temp->entry.name, entry.name) == 0  /*&& temp->entry.scope == entry.scope*/) {
		return temp;
	}
	return NULL;
}

void print_symbol_table (st_node_p_t head) {

	if (head == NULL) {
		return;
	}

	// Finish this...

	printf("\n------------------------------------------------------------\n");
	printf("---------------------- SYMBOL TABLE ------------------------\n");
	printf("------------------------------------------------------------\n");

	printf("ID \t| TYPE \t\t| SIZE\t| SCOPE\t| NARGS\t| RET \t| ARGS \t| NAME\n");

	st_node_p_t temp = head;
	while (temp != NULL) {

		st_entry_t entry = temp->entry;

		printf("%d \t| ", entry.id);
		printf("%8s %d \t| ", get_token_type_string(entry.type), entry.type);
		printf("%ld \t| ", entry.size);
		printf("%c \t| ", (entry.scope == TOKEN_SCOPE_LOCAL) ? 'L' : 'G');
		printf("%d \t| ", entry.nargs);
		printf("%s \t| ", entry.return_type);
		printf("{ ");
		for (int i = 0; i < 16; ++i) {
			if (entry.args[i] == 1) {
				printf("%d ", i);
			}
		}
		printf("} \t| ");
		printf("\"%s\" \n", entry.name);

		temp = temp->next;

	}

	printf("------------------------------------------------------------\n");

}



#pragma mark - Token buffer

tnode_p_t init_tnode (char *name) {
	tnode_p_t node = (tnode_p_t)malloc(sizeof(tnode_t));
	strcpy(node->name, name);
	node->next = node;
	node->prev = node;
	return node;
}

// Insert a arbritary token to the token DLL
tnode_p_t insert_token (tnode_p_t *head, char *token) {
	if (*head == NULL) {
		*head = init_tnode(token);
		return *head;
	}
	tnode_p_t root = *head;
	tnode_p_t temp = init_tnode(token);
	temp->next = root;
	temp->prev = root->prev;
	root->prev = temp;
	root->prev->next = temp;
	return temp;
}

// Print the token buffer list.
void print_token_buffer (tnode_p_t head) {
	printf("Token buffer stack: ");
	tnode_p_t temp = head->prev;
	while (temp->prev != head) {
		printf("%s <-> ", temp->name);
		temp = temp->prev;
	}
	printf("%s", temp->name);
	printf("\n\n");
}

