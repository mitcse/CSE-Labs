#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct htnode {
	char *title;
	float value;
	struct htnode *left, *right;
} node_t, *node_p_t;

node_p_t initNode (char *title, float value) {
	node_p_t node = (node_p_t)malloc(sizeof(node_t));
	node->title = (char *)malloc(20 * sizeof(char));
	strcpy(node->title, title);
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

node_p_t nodes[100];
node_p_t head;

int n;
int i, j;

void input () {
	printf("Enter number of characters: ");
	scanf(" %d", &n);
	char *title = (char *)malloc(20 * sizeof(char));
	float value;
	for (i = 0; i < n; ++i) {
		printf("Character [%d], enter symbol and value: ", i);
		scanf(" %s", title);
		scanf(" %f", &value);
		node_p_t node = initNode(title, value);
		nodes[i] = node;
	}
}

void sort () {
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n - 1 - i; ++j) {
			node_p_t a = nodes[j];
			node_p_t b = nodes[j+1];
			if (a->value < b->value) {
				node_p_t c = a;
				nodes[j] = b;
				nodes[j+1] = c;
			}
		}
	}
}

void printNode (node_p_t node, char *str) {
	printf(" %s [%s, %.2f]\n", str, node->title, node->value);
}

void huffman () {
	do {
		sort();
		if (n > 1) {
			node_p_t a = nodes[n-1];
			node_p_t b = nodes[n-2];
			// printNode(a, "A");
			// printNode(b, "B");
			node_p_t c = initNode("*", a->value + b->value);
			c->left = a;
			c->right = b;
			// printNode(c, "C");
			nodes[n-2] = c;
			n -= 1;
		}
	} while (n > 1);
	head = nodes[0];
}

void printCode (node_p_t root, char *code) {
	if (root == NULL) {
		return;
	}
	if (root->left == NULL && root->right == NULL) {
		printf("  %s\t|  %.2lf\t|  %s\n", root->title, root->value, code);
	} else {
		if (code == NULL) {
			code = (char *)malloc(20 * sizeof(char));
		}
		int len = strlen(code);
		char *a = (char *)malloc(20 * sizeof(char));
		strcpy(a, code);
		a[len] = '0';
		printCode(root->left, a);
		char *b = (char *)malloc(20 * sizeof(char));
		strcpy(b, code);
		b[len] = '1';
		printCode(root->right, b);
	}
}

int main (int argc, char const * argv[]) {
	input();
	huffman();
	printCode(head, NULL);
	return 0;
}

/** 
	Sample input:
	5
	A 0.35
	B 0.1
	C 0.2
	D 0.2
	E 0.15

	Sample output:
	  D	|  0.20	|  00
	  C	|  0.20	|  01
	  B	|  0.10	|  100
	  E	|  0.15	|  101
	  A	|  0.35	|  11

*/