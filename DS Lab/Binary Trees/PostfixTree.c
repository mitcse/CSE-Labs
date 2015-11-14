//
//	PostfixTree.c
//	Evaulation of a postfix expression using binary trees.
//
//	Created by Avikant Saini on 3/11/15
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 50

#define initString (char *)malloc(SIZE * sizeof(char))

typedef enum { NO, YES } BOOL;

typedef enum { TYPE_NONE, TYPE_OPERATOR, TYPE_OPERAND } EXP_TYPE;

typedef char * String;

#pragma mark - Tree creation

typedef struct TNode {
	String data;
	EXP_TYPE type;
	struct TNode *left;
	struct TNode *right;
} TNODE_t;

typedef TNODE_t * TNODE_p_t;

TNODE_p_t initTNode (String data) {
	TNODE_p_t tnode = (TNODE_p_t)malloc(sizeof(TNODE_t));
	tnode->data = initString;
	strcpy(tnode->data, data);
	tnode->type = TYPE_NONE;
	tnode->left = NULL;
	tnode->right = NULL;
}

#pragma mark - TStack creation

typedef struct TSNode {
	TNODE_p_t data;
	struct TSNode *next;
	struct TSNode *prev;
} TSNODE_t;

typedef TSNODE_t * TSNODE_p_t;

TSNODE_p_t initTSNode (TNODE_p_t data) {
	TSNODE_p_t tsnode = (TSNODE_p_t)malloc(sizeof(TSNODE_t));
	tsnode->data = data;
	tsnode->next = tsnode;
	tsnode->prev = tsnode;
}
	
BOOL push (TSNODE_p_t *stack, TNODE_p_t data) {
	TSNODE_p_t temp = initTSNode(data);
	if (*stack == NULL) {
		*stack = temp;
		return YES;
	}
	TSNODE_p_t head = *stack;
	TSNODE_p_t last = head->prev;
	last->next = temp;
	temp->next = head;
	head->prev = temp;
	temp->prev = last;
	return YES;
}

TNODE_p_t pop (TSNODE_p_t *stack) {
	if (*stack == NULL)
		return NULL;
	TSNODE_p_t head = *stack;
	TSNODE_p_t temp = head->prev;
	if (head->next == head)
		*stack = NULL;
	else {
		TSNODE_p_t tpre = temp->prev;
		tpre->next = head;
		head->prev = tpre;
	}
	return (temp->data);
}

#pragma mark - Postfix evaulation

double evaulate (TNODE_p_t root) {
	if (root->type == TYPE_OPERAND)
		return atof(root->data);
	else if (root->type == TYPE_OPERATOR) {
		char ch = *(root->data);
		if (ch == '+')
			return (evaulate(root->left) + evaulate(root->right));
		else if (ch == '-')
			return (evaulate(root->left) - evaulate(root->right));
		else if (ch == '*')
			return (evaulate(root->left) * evaulate(root->right));
		else if (ch == '/')
			return (evaulate(root->left) / evaulate(root->right));
		else if (ch == '$' || ch == '^')
			return pow(evaulate(root->left), evaulate(root->right));
		else
			return 0;	
	}
}

int indexOf (char character, char *string) {
	char *ptr = strchr(string, character);
	if (ptr)
		return (int)(ptr - string);
	return -1;
}

BOOL isOperator (char op) {
	if (indexOf(op, "+-*/$^") != -1)
		return YES;
	return NO;
}

BOOL isNumber (char op) {
	if (op >= '0' && op <= '9')
		return YES;
	return NO;
}

BOOL isAlphabet (char op) {
	if ((op >= 'A' && op <= 'Z') || (op >= 'a' && op <= 'z'))
		return YES;
	return NO;
}

int numericValue (char character) {
	return (int)(character - 48);
}

double postfix (String exp) {
	int i, l = strlen(exp);
	TSNODE_p_t stack = NULL;
	
	TNODE_p_t root = NULL;
	
	for (i = 0; i < l; ++i) {
		char z = *(exp + i);
		
		if (isNumber(z)) {
			String str = initString;
			snprintf(str, SIZE, "%d", numericValue(z));
			root = initTNode(str);
			root->type = TYPE_OPERAND;
			push(&stack, root);
		}
			
		else if (isAlphabet(z)) {
			double numz;
			printf("\n\tEnter the value of '%c': ", z);
			scanf(" %lf", &numz);
			String str = initString;
			snprintf(str, SIZE, "%lf", numz);
			root = initTNode(str);
			root->type = TYPE_OPERAND;
			push(&stack, root);
		}
		
		else if (isOperator(z)) {
			TNODE_p_t b = pop(&stack);
			TNODE_p_t a = pop(&stack);
			String str = initString;
			snprintf(str, SIZE, "%c", z);
			root = initTNode(str);
			root->right = b;
			root->left = a;
			root->type = TYPE_OPERATOR;
			push(&stack, root);
		}
	
	}
	
	root = pop(&stack);
	
	return evaulate(root);
	
}
	

#pragma mark - main
	
int main(int argc, const char * argv[]) {
	
	String str = initString;
	
	printf("\n\tThis program will compute the value of an postfix operation.\n\te.g. 135*+ = 1 + 3 * 5 = 16.\n\n\tEnter an valid postfix expression : ");
	scanf("%s", str);
	
	double result = postfix(str);
	
	printf("\n\t Result = %.3lf.\n\n", result);
	
	return 0;
}
