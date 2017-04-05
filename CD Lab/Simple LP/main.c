//
//	main.c
//
//	"Simple Compiler"
//	Lexer and simple parser for a small subset of the C grammer
//
//	Created by @avikantz on 4/4/17
//

/**
*	The grammar:
*
*	program -> main () { declarations  assign_stat }
*	declatations -> data_type identifier_list; declarations | e
*	data_type -> int | char
*	identifier_list -> id | id, identifier_list
*	assign_stat -> id = id; | id = num;
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------------------------------------------------------

#pragma mark - Other

int get_size(char value[16]) {
	if (strcmp(value, "int") == 0)
		return 4;
	else if (strcmp(value, "char") == 0)
		return 1;
	return 0;
}

int KEYWORD_COUNT = 4;
char *keywords[4] = {
	"main", "int", "char", "return"
};

int is_keyword(char value[16]) {
	for (int i = 0; i < KEYWORD_COUNT; ++i) {
		if (strcmp(value, keywords[i]) == 0)
			return 1;
	}
	return 0;
}

// ------------------------------------------------------------------

#pragma mark - Symbol Table Constructs

typedef struct stex {
	int id;
	char lexeme[16];
	char type[16];
	int size;
	int scope;
} ste_t;

ste_t symbol_table[16];
int ste_p = 0;

ste_t find_or_insert_st(char lexeme[16], char type[16], int size, int scope) {
	ste_t entry;
	// Check if the symbol table entry is present
	int i;
	for (i = 0; i < ste_p; ++i) {
		if (strcmp(symbol_table[i].lexeme, lexeme) == 0) {
			return symbol_table[i];
		}
	}
	strcpy(entry.lexeme, lexeme);
	entry.id = ste_p + 1;
	strcpy(entry.type, type);
	entry.size = size;
	entry.scope = scope;
	symbol_table[ste_p++] = entry;
	return entry;
}

void print_symbol_table() {
	printf("\n");
	printf("-----------    SYMBOL  TABLE    ----------\n");
	printf("------------------------------------------\n");
	printf("id |            name | type | size | scope\n");
	printf("------------------------------------------\n");
	for (int i = 0; i < ste_p; ++i) {
		ste_t entry = symbol_table[i];
		printf("%2d | %15s | %4s | %4d | %5d\n", entry.id, entry.lexeme, entry.type, entry.size, entry.scope);
	}
	printf("------------------------------------------\n");
}

// ------------------------------------------------------------------

#pragma mark - Token Constructs

typedef enum ttx {
	TOKEN_TYPE_ID,
	TOKEN_TYPE_KEYWORD,
	TOKEN_TYPE_NUM,
	TOKEN_TYPE_OP,
	TOKEN_TYPE_SPECIAL
} token_type;

typedef struct tokenx {
	token_type type;
	char value[16];
	ste_t entry;
} token_t;

token_t tokens[120];
int token_p = 0;

token_t last_keyword;
int current_scope = 0;

token_t new_token(token_type type, char value[16]) {
	token_t token;
	token.type = type;
	if (type == TOKEN_TYPE_ID) {
		if (is_keyword(value)) {
			token.type = TOKEN_TYPE_KEYWORD;
		} else {
			token.entry = find_or_insert_st(value, last_keyword.value, get_size(last_keyword.value), current_scope);
		}
	}
	strcpy(token.value, value);
	if (token.type == TOKEN_TYPE_KEYWORD) {
		last_keyword = token;
	}
	tokens[token_p++] = token;
	return token;
}

void print_token(token_t token) {
	printf("<");
	if (token.type == TOKEN_TYPE_ID) {
		ste_t entry = find_or_insert_st(token.value, last_keyword.value, get_size(last_keyword.value), current_scope);
		printf("id, %d", entry.id);
	} else if (token.type == TOKEN_TYPE_NUM) {
		printf("num, %s", token.value);
	} else {
		printf("%s", token.value);
	}
	printf("> ");
}

void print_tokens() {
	printf("\n");
	printf("--------------    TOKENS    --------------\n");
	for (int i = 0; i < token_p; ++i) {
		print_token(tokens[i]);
		if (i % 5 == 4)
			printf("\n");
	}
	printf("\n------------------------------------------\n");
}

// ------------------------------------------------------------------

#pragma mark - Recursive descent parser

#define SUCCESS_HANDLER printf("%30s: Success.\n", __PRETTY_FUNCTION__); exit(0);
#define ERROR_HANDLER printf("%30s: Error occured.\n", __PRETTY_FUNCTION__); exit(1);

#define LOG_CURRENT printf("--> %27s: %s\n", __PRETTY_FUNCTION__, tokens[pi].value);

#define CURR tokens[pi].value
#define CURRTYPE tokens[pi].type
#define CURR_EQ(name) (strcmp(CURR, name) == 0)

int pi = 0;

void program();
void declarations();
void data_type();
void identifier_list();
void assign_stat();

void program() {
	LOG_CURRENT;
	if CURR_EQ("main") {
		pi += 1;
		LOG_CURRENT;
		if CURR_EQ("(") {
			pi += 1;
			LOG_CURRENT;
			if CURR_EQ(")") {
				pi += 1;
				LOG_CURRENT;
				if CURR_EQ("{") {
					pi += 1;
					LOG_CURRENT;
					declarations();
					assign_stat();
					if CURR_EQ("}") {
						pi += 1;
						if (pi == token_p) {
							SUCCESS_HANDLER;
						} else {
							ERROR_HANDLER;
						}
					} else {
						ERROR_HANDLER;
					}
				} else {
					ERROR_HANDLER;
				}
			} else {
				ERROR_HANDLER;
			}
		} else {
			ERROR_HANDLER;
		}
	} else {
		ERROR_HANDLER;
	}
}

void declarations() {
	LOG_CURRENT;
	if (CURRTYPE == TOKEN_TYPE_ID) {
		return;
	}
	data_type();
	identifier_list();
	if CURR_EQ(";") {
		pi += 1;
		LOG_CURRENT;
		declarations();
	}
}

void data_type() {
	LOG_CURRENT;
	if (CURR_EQ("int") || CURR_EQ("char")) {
		pi += 1;
		LOG_CURRENT;
	}
}

void identifier_list() {
	LOG_CURRENT;
	if (CURRTYPE == TOKEN_TYPE_ID) {
		pi += 1;
		LOG_CURRENT;
		if CURR_EQ(",") {
			pi += 1;
			LOG_CURRENT;
			identifier_list();
		}
	} else {
		ERROR_HANDLER;
	}
}

void assign_stat() {
	LOG_CURRENT;
	if (CURRTYPE == TOKEN_TYPE_ID) {
		pi += 1;
		LOG_CURRENT;
		if CURR_EQ("=") {
			pi += 1;
			LOG_CURRENT;
			if (CURRTYPE == TOKEN_TYPE_ID || CURRTYPE == TOKEN_TYPE_NUM) {
				pi += 1;
				LOG_CURRENT;
				if CURR_EQ(";") {
					pi += 1;
					LOG_CURRENT;
				} else {
					ERROR_HANDLER;
				}
			} else {
				ERROR_HANDLER;
			}
		} else {
			ERROR_HANDLER;
		}
	} else {
		ERROR_HANDLER;
	}
}

// ------------------------------------------------------------------

#pragma mark - Utilities

int isDigit (char ch) {
	return (ch >= '0' && ch <= '9');
}

int isNumerical (char ch) {
	return (isDigit(ch) || ch == '.' || ch == 'e' || ch == 'E');
}

int isAlphabet (char ch) {
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int isValidID (char ch) {
	return (isDigit(ch) || isAlphabet(ch) || ch == '_');
}

const char *SPECIALSYMBOLS = "[]{}(),;:.#";

int isSpecialSymbol (char ch) {
	return (strchr(SPECIALSYMBOLS, ch) != NULL);
}

const char *OPERATORS = "+-*/%<>=!&|^~";

int isOperator (char ch) {
	return (strchr(OPERATORS, ch) != NULL);
}

// ------------------------------------------------------------------

#pragma mark - Lexer

#define BUFFER_SIZE 128

void emit_tokens (char *infile) {
	
	FILE *input = fopen(infile, "r");

	char buffer[16];
	int k = 0;

	current_scope = 0;
	char ch, lch;

	token_t token;

	do {

		ch = getc(input);

		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
			// Discard space
		}

		// IDs begin with an alphabet and then may contains numbers, characters or '_'
		else if (isAlphabet(ch)) {
			k = 0;
			while (isValidID(ch)) {
				buffer[k++] = ch;
				ch = getc(input);
			}
			ungetc(ch, input);
			buffer[k++] = '\0';
			token = new_token(TOKEN_TYPE_ID, buffer);
		}

		// Numbers
		else if (isDigit(ch)) {
			k = 0;
			while (isNumerical(ch)) {
				buffer[k++] = ch;
				ch = getc(input);
			}
			ungetc(ch, input);
			buffer[k++] = '\0';
			token = new_token(TOKEN_TYPE_NUM, buffer);
		}

		else if (isSpecialSymbol(ch)) {
			if (ch == '{') {
				current_scope += 1;
			} else if (ch == '}') {
				current_scope -= 1;
			}
			k = 0;
			buffer[k++] = ch;
			buffer[k++] = '\0';
			token = new_token(TOKEN_TYPE_SPECIAL, buffer);
		}

		else if (isOperator(ch)) {
			k = 0;
			while (isOperator(ch) || ch == ' ' || ch == '\t') {
				if (isOperator(ch)) {
					buffer[k++] = ch;
				}
				ch = getc(input);
			}
			buffer[k++] = '\0';
			ungetc(ch, input);
			token = new_token(TOKEN_TYPE_OP, buffer);
		}

		lch = ch;

	} while (ch != EOF);

	print_tokens();
	print_symbol_table();

	program();

}

// ------------------------------------------------------------------

#pragma mark - Test suites

void test_tokens() {
	new_token(TOKEN_TYPE_ID, 		"main");
	new_token(TOKEN_TYPE_SPECIAL, 	"(");
	new_token(TOKEN_TYPE_SPECIAL, 	")");
	new_token(TOKEN_TYPE_SPECIAL, 	"{");
	current_scope = 1;
	new_token(TOKEN_TYPE_ID, 		"int");
	new_token(TOKEN_TYPE_ID, 		"apple");
	new_token(TOKEN_TYPE_SPECIAL, 	",");
	new_token(TOKEN_TYPE_ID, 		"banana");
	new_token(TOKEN_TYPE_SPECIAL, 	";");
	new_token(TOKEN_TYPE_ID, 		"char");
	new_token(TOKEN_TYPE_ID, 		"custard");
	new_token(TOKEN_TYPE_SPECIAL, 	";");
	new_token(TOKEN_TYPE_ID, 		"apple");
	new_token(TOKEN_TYPE_OP, 		"=");
	new_token(TOKEN_TYPE_NUM, 		"5");
	new_token(TOKEN_TYPE_SPECIAL, 	";");
	new_token(TOKEN_TYPE_SPECIAL, 	"}");
	print_tokens();
	print_symbol_table();
}

// ------------------------------------------------------------------

int main(int argc, const char *argv[]) {
	emit_tokens("input.c");
	return 0;
}
