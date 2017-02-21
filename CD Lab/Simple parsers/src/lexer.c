//
// lexer.c
//
// Lexical analyzer, generates symbol table
//
// Created by @avikantz on 01/27/17
//

#define PRINT_CODE YES
#define DEBUG_MODE NO

#include "lexer.h"

BOOL isKeyword (char buffer[BUFFER_SIZE]) {
	int i;
	for (i = 0; i < KEYWORD_COUNT; ++i) {
		if (strcmp(KEYWORDS[i], buffer) == 0)
			return YES;
	}
	return NO;
}

BOOL isDataType (char buffer[BUFFER_SIZE]) {
	int i;
	for (i = 0; i < 7; ++i) {
		if (strcmp(KEYWORDS[i], buffer) == 0)
			return YES;
	}
	return NO;
}

void emit_tokens (char *inname) {

	FILE *input = fopen(inname, "r");

	char outname[128];
	snprintf(outname, 128, "out.txt");
	FILE *output = fopen(outname, "w+");

	char ch, lch;
	char buffer[BUFFER_SIZE]; int k = 0;

	st_node_p_t symbol_table = NULL;

	tnode_p_t token_head = init_tnode("$");

	int scope_flag = 0;
	int nargs = 0;

	do {
		
		ch = getc(input);

		if (ch == ' ' || ch == '\t') { // Simply discard the blank space

			if (ch == '\t') {
				if (PRINT_CODE) printf("\t");
				fprintf(output, "\t");
			}

		} else if (ch == '\n') { // Put the next line on the output buffer
	
			if (PRINT_CODE) printf("\n");
			fprintf(output, "\n");
		
		} else if (ch == '\"' && lch != '\\') { // Wait till the string ends
			
			k = 0;
			buffer[k++] = ch;
			
			do {
				ch = getc(input);
				buffer[k++] = ch;
			} while (ch != '\"');
			
			buffer[k++] = EOS;

			if (PRINT_CODE) printf("\"%s\" ", buffer);
			fprintf(output, "\"%s\" ", buffer);

		} else if (ch == '\'' && lch != '\\') { // Wait till the character stream ends
			
			k = 0;
			
			do {
				ch = getc(input);
				buffer[k++] = ch;
			} while (ch != '\'');
			
			buffer[k-1] = EOS; // Don't want "'" in there.

			if (PRINT_CODE) printf("%s ", buffer);
			fprintf(output, "%s ", buffer);

		} else if (isAlphabet(ch)) { // Take the identifier...

			k = 0;

			while (isValidID(ch)) {
				buffer[k++] = ch;
				ch = getc(input);
				if (k > BUFFER_SIZE) {
					printf("Error: Buffer overflow (isAlphabet)! %s\n", buffer);
					return;
				}
			}
			ungetc(ch, input); // Put the last character back in the buffer, cause the while loop takes one more
			buffer[k++] = EOS;

			// Check for keywords here.
			if (isKeyword(buffer)) {
				
				if (PRINT_CODE) printf("%s ", buffer);
				fprintf(output, "%s ", buffer);

				char *prevToken = token_head->prev->name;
				if (strcmp(buffer, "if") == 0) {
					if (strcmp(prevToken, "else") == 0) {
						if (DEBUG_MODE) printf("ELSE-IF detected.\n");
					} else {
						if (DEBUG_MODE) printf("IF detected.\n");
					}
				} else if (strcmp(buffer, "else") == 0) {
					if (DEBUG_MODE) printf("ELSE detected.\n");
				}

				// Append the keyword to the token buffer
				insert_token(&token_head, buffer);
				if (DEBUG_MODE) print_token_buffer(token_head);

			} else {
				// Create an arbitary entry
				// TODO: determine the type of the entry.
				
				st_entry_t new_entry = new_symbol_table_entry(buffer, TOKEN_TYPE_ID, sizeof(int), TOKEN_SCOPE_LOCAL, 0, "-");

				BOOL inserted;
				st_node_p_t stnode = find_or_insert_st(&symbol_table, new_entry, &inserted);

				if (stnode != NULL && inserted) {
					// New token is inserted to the symbol table
					char *prevToken = token_head->prev->name; // Get the previous token to determine the type
					if (isKeyword(prevToken)) {
						// Previous token is a keyword, it's a variable declaration, do relevant operations.
						if (DEBUG_MODE) printf("New token <%s, %s> is inserted to ST.\n", buffer, token_head->prev->name);

						// Set size and type for the symbol table entry
						stnode->entry.type = get_token_type(prevToken);
						stnode->entry.size = get_token_size(stnode->entry.type);

						// Set scope
						stnode->entry.scope = (scope_flag == 0) ? TOKEN_SCOPE_GLOBAL : TOKEN_SCOPE_LOCAL; // Don't really see the relevance of it.

					} else {
						// Previous token is not a keyword, prehaps it's a function name ?
					}
				} else {	
					// printf("Token [%s] referenced again.", buffer);
				}

				if (PRINT_CODE) printf("id ");
				fprintf(output, "id ");

				// Append the token to the token head
				insert_token(&token_head, buffer);

			}

		} else if (isDigit(ch)) { // Take the numbers separately

			k = 0;
			while (isNumerical(ch)) {
				buffer[k++] = ch;
				ch = getc(input);
				if (k > BUFFER_SIZE) {
					printf("Error: Buffer overflow (isDigit): %s\n", buffer);
					return;
				}
			}
			ungetc(ch, input); // Put the last character back in the buffer, cause the while loop takes one more
			buffer[k++] = EOS;
			if (PRINT_CODE) printf("num ");
			fprintf(output, "num ");

		} else if (isSpecialSymbol(ch)) {

			if (PRINT_CODE) printf("%c ", ch); // Just print the god damn special symbol
			fprintf(output, "%c ", ch);

			// Array indices
			if (ch == '[') {
				// Array is declared or referenced
				char *prevToken = token_head->prev->name;
				char *prevPrevToken = token_head->prev->prev->name;
				if (DEBUG_MODE) printf("Prev = %s, PrevPrev = %s\n", prevToken, prevPrevToken);
				if (isDataType(prevPrevToken) && !(isKeyword(prevToken))) {
					// Assume array declarations are of the form <keyword> <identifier> [NUM]
					char buffer[BUFFER_SIZE];
					strcpy(buffer, prevToken);
					st_entry_t new_entry = new_symbol_table_entry(buffer, TOKEN_TYPE_ID, sizeof(int), TOKEN_SCOPE_LOCAL, 0, "-");
					st_node_p_t stnode = find_in_st(&symbol_table, new_entry);
					if (stnode != NULL) {
						stnode->entry.nargs = 9; // Find and get size here.
						if (DEBUG_MODE) printf("Array declaration: %s\n", stnode->entry.name);
					}
				}
			}

			// Count the levels of scope.
			else if (ch == '{') {
				scope_flag += 1;
			} else if (ch == '}') {
				scope_flag -= 1;
			}

			// Detect functions and shit
			else if (ch == '(') {
				char *prevToken = token_head->prev->name;
				if (isKeyword(prevToken)) {
					// Beginning of a if, for, while, etc.

				} else {
					// Beginning of a function
					char tkb[BUFFER_SIZE];
					strcpy(tkb, prevToken);
					st_entry_t new_entry = new_symbol_table_entry(tkb, TOKEN_TYPE_ID, sizeof(int), TOKEN_SCOPE_LOCAL, 0, "-");
					st_node_p_t stnode = find_in_st(&symbol_table, new_entry);
					if (stnode != NULL) {
						if (strcmp(stnode->entry.return_type, "-") == 0) {
							strcpy(stnode->entry.return_type, get_token_type_string(stnode->entry.type));
						}
						stnode->entry.type = TOKEN_TYPE_FUNC;
						nargs = 1;
						insert_token(&token_head, "(");
					}
				}

			} else if (ch == ',') {
				if (nargs > 0) {
					nargs += 1;
				}

			} else if (ch == ')') {
				// printf("---- nargs = %d | ", nargs);
				if (nargs > 0) {
					int argx[16] = {0};
					tnode_p_t temp = token_head->prev;
					while (strcmp(temp->name, "(") != 0) {
						// printf("%s <-> ", temp->name);
						if (!isKeyword(temp->name)) {
							st_entry_t new_entry = new_symbol_table_entry(temp->name, TOKEN_TYPE_ID, sizeof(int), TOKEN_SCOPE_LOCAL, 0, "-");
							st_node_p_t stnode = find_in_st(&symbol_table, new_entry);
							if (stnode != NULL) {
								// printf(" << %s >>", stnode->entry.name);
								argx[stnode->entry.id] = 1;
							} 
						}
						temp = temp->prev;
					}
					// printf("%s", temp->name);
					temp = temp->prev;
					// printf(" ^%s^ ", temp->name);
					st_entry_t new_entry = new_symbol_table_entry(temp->name, TOKEN_TYPE_ID, sizeof(int), TOKEN_SCOPE_LOCAL, 0, "-");
					st_node_p_t stnode = find_in_st(&symbol_table, new_entry);
					if (stnode != NULL) {
						stnode->entry.nargs = nargs;
						// printf(" << %s >>", stnode->entry.name);
						// argx[stnode->entry.id] = 1;
						for (int i = 0; i < 16; ++i) {
							stnode->entry.args[i] = argx[i];
							// printf("%d", stnode->entry.args[i]);
						}
						// printf("\n");
					} 

					// printf(" ----\n");
				}

				nargs = 0;
			}

		} else if (isOperator(ch)) {

			k = 0;
			while (isOperator(ch) || ch == ' ' || ch == '\t') { // To detect terms like "< =" 
				if (isOperator(ch)) {
					buffer[k++] = ch;
				}
				ch = getc(input);
			}
			buffer[k++] = EOS;
			ungetc(ch, input); // Put the last character back in the buffer, cause the while loop takes one more

			char *opname = operator_name(buffer);
			if (opname != NULL) {
				if (PRINT_CODE) printf("%s ", buffer);
				fprintf(output, "%s ", buffer);
				// printf("<%s, %s> ", opname, buffer);
				// fprintf(output, "<%s, %s> ", opname, buffer);
			}

		}

		lch = ch;

	} while (ch != EOF);

	// Print the symbol table for the glory of the Sontaran Empire
	// print_token_buffer(token_head);

}