# Simple C like parser

Parser for the grammer:

```
program -> main () { declarations statement_list }
declarations -> data-type identifier_list; declarations | e
data_type -> int | char
identifier_list -> id | id , identifier_list | id[number], identifier_list | id[number]
statement_list -> statement statement_list | e
statement -> assign_stat;
assign_stat -> id = expn;
expn -> simple_expn eprime
eprime -> relop simple_expn | e
simple_expn -> term seprime
seprime -> addop term seprime | e
term -> factor tprime
tprime -> mulop factor tprime | e
factor -> id | num
relop -> == | != | <= | >= | > | <
addop -> + | -
mulop -> * | / | %
```

### Usage

- `make`
- Input in any file, say `temp.c`
- Run `./notclang temp.c`
- Build and execute `rdparser.c`

### Sample Input

```
>> cat temp.c
main () {
	int a;
	int arr[10];
	char b, c;
	a = a + 10
	b = a * c
}
```

#### Lexer (notclang) output

```
<main> <(> <)> <{> 
	<int> <id> <;> 
	<int> <id> <[> <num> <]> <;> 
	<char> <id> <,> <id> <;> 
	<id> <=> <id> <+> <num> 
	<id> <=> <id> <*> <id> 
<}>
```

#### Parser output

```
--> void program(): <main>
--> void program(): <(>
--> void program(): <)>
--> void program(): <{>
--> void program(): <int>
--> void declarations(): <int>
--> void data_type(): <int>
--> void data_type(): <id>
--> void identifier_list(): <id>
--> void identifier_list(): <;>
--> void declarations(): <int>
--> void declarations(): <int>
--> void data_type(): <int>
--> void data_type(): <id>
--> void identifier_list(): <id>
--> void identifier_list(): <[>
--> void identifier_list(): <num>
--> void identifier_list(): <]>
--> void identifier_list(): <;>
--> void declarations(): <char>
--> void declarations(): <char>
--> void data_type(): <char>
--> void data_type(): <id>
--> void identifier_list(): <id>
--> void identifier_list(): <,>
--> void identifier_list(): <id>
--> void identifier_list(): <;>
--> void declarations(): <id>
--> void declarations(): <id>
--> void statement_list(): <id>
--> void statement(): <id>
--> void assign_stat(): <id>
--> void assign_stat(): <=>
--> void assign_stat(): <id>
--> void expn(): <id>
--> void simple_expn(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <+>
--> void tprime(): <+>
--> void seprime(): <+>
--> void addop(): <+>
--> void addop(): <num>
--> void term(): <num>
--> void factor(): <num>
--> void factor(): <id>
--> void tprime(): <id>
--> void seprime(): <id>
--> void eprime(): <id>
--> void statement_list(): <id>
--> void statement(): <id>
--> void assign_stat(): <id>
--> void assign_stat(): <=>
--> void assign_stat(): <id>
--> void expn(): <id>
--> void simple_expn(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <*>
--> void tprime(): <*>
--> void mulop(): <*>
--> void mulop(): <id>
--> void factor(): <id>
--> void factor(): <}>
--> void tprime(): <}>
--> void seprime(): <}>
--> void eprime(): <}>
--> void program(): ?
void program()(): Success.
```