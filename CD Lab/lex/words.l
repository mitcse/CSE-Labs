%{
	int cno = 0, wno = 0, lno = 0, bno = 0;
%}

character [a-zA-Z]
digit [0-9]
word ({character}|{digit})+
line \n

%%

{ line } { cno++; lno++; }
{ word } { wno++; cno + = strlen(yytext); }
" " bno++;
\t bno+ = 4;
. { cno++; }

%%
int yywrap() {
	return 1;
}

int main(void)
{
  yylex();
  printf("\nNumber of characters: %d", cno);
  printf("\nNumber of words   : %d", wno);
  printf("\nNumber of lines   : %d", lno);
  printf("\nNumber of blanks  : %d\n", bno);
  return 0;
}