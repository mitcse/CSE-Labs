%{
	int pos_int = 0;
	int neg_int = 0;
	int pos_float = 0;
	int neg_float = 0;
%}

DIGIT [0-9]
%%

\+?{DIGIT}+	pos_int++;
-{DIGIT}+	neg_int++;

\+?{DIGIT}*\.{DIGIT}+	pos_float++;
-{DIGIT}*\.{DIGIT}+		neg_float++;
. ;
%%

int yywrap() {
	return 1;
}

int main() {
	yylex();
	printf("\nPositive numbers: %d", pos_int);
	printf("\nNegative numbers: %d", neg_int);
	printf("\nPositive fractions: %d", pos_float);
	printf("\nNegative fractions: %d\n", neg_float);
	return 0;
}