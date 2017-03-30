%{
	int linecount = 0;
%}
%%
\n linecount++;
%%
int main () {
	yylex();
	printf("Lines = %d\n", linecount);
	return 0;
}
int yywrap() {
	return 1;
}