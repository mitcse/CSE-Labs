# Simple C like parser

Parser for the grammer:

```
program -> main () { declarations statement_list }
	declarations -> data-type identifier_list; declarations | e
	data_type -> int | char
	identifier_list -> id | id , identifier_list | id[number], identifier_list | id[number]
	statement_list -> statement statement_list | e
	statement -> assign_stat; | decision_stat | looping_stat
	assign_stat -> id = expn;
	expn -> simple_expn eprime
	eprime -> relop simple_expn | e
	simple_expn -> term seprime
	seprime -> addop term seprime | e
	term -> factor tprime
	tprime -> mulop factor tprime | e
	factor -> id | num
	decision_stat -> if (expn) { statement_list } dprime
	looping_stat -> while (expn) {statement_list} | for (assign_stat; expn; assign_stat) {statement_list}
	dprime -> else { statement_list } | e
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
	int x;
	char y;
	int p;
	x = p;
	x = p + x * p;
	if (x == p) {
		y = x;
	} else {
		y = p;
	}
	for (x = p; x <= p; x = x + 2) {
		y = y * 2;
	}
}
```

#### Lexer (notclang) output

```
<main> <(> <)> <{> 
	<int> <id> <;> 
	<char> <id> <;> 
	<int> <id> <;> 
	<id> <=> <id> <;> 
	<id> <=> <id> <+> <id> <*> <id> <;> 
	<if> <(> <id> <==> <id> <)> <{> 
		<id> <=> <id> <;> 
	<}> <else> <{> 
		<id> <=> <id> <;> 
	<}> 
	<for> <(> <id> <=> <id> <;> <id> <<=> <id> <;> <id> <=> <id> <+> <num> <)> <{> 
		<id> <=> <id> <*> <num> <;> 
	<}> 
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
--> void declarations(): <char>
--> void declarations(): <char>
--> void data_type(): <char>
--> void data_type(): <id>
--> void identifier_list(): <id>
--> void identifier_list(): <;>
--> void declarations(): <int>
--> void declarations(): <int>
--> void data_type(): <int>
--> void data_type(): <id>
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
--> void factor(): <;>
--> void tprime(): <;>
--> void seprime(): <;>
--> void eprime(): <;>
--> void assign_stat(): <;>
--> void assign_stat(): <id>
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
--> void addop(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <*>
--> void tprime(): <*>
--> void mulop(): <*>
--> void mulop(): <id>
--> void factor(): <id>
--> void factor(): <;>
--> void tprime(): <;>
--> void seprime(): <;>
--> void eprime(): <;>
--> void assign_stat(): <;>
--> void assign_stat(): <if>
--> void decision_stat(): <if>
--> void decision_stat(): <(>
--> void decision_stat(): <id>
--> void expn(): <id>
--> void simple_expn(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <==>
--> void tprime(): <==>
--> void seprime(): <==>
--> void eprime(): <==>
--> void relop(): <==>
--> void relop(): <id>
--> void simple_expn(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <)>
--> void tprime(): <)>
--> void seprime(): <)>
--> void decision_stat(): <{>
--> void decision_stat(): <id>
--> void statement_list(): <id>
--> void statement(): <id>
--> void assign_stat(): <id>
--> void assign_stat(): <=>
--> void assign_stat(): <id>
--> void expn(): <id>
--> void simple_expn(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <;>
--> void tprime(): <;>
--> void seprime(): <;>
--> void eprime(): <;>
--> void assign_stat(): <;>
--> void assign_stat(): <}>
--> void decision_stat(): <else>
--> void dprime(): <else>
--> void dprime(): <{>
--> void dprime(): <id>
--> void statement_list(): <id>
--> void statement(): <id>
--> void assign_stat(): <id>
--> void assign_stat(): <=>
--> void assign_stat(): <id>
--> void expn(): <id>
--> void simple_expn(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <;>
--> void tprime(): <;>
--> void seprime(): <;>
--> void eprime(): <;>
--> void assign_stat(): <;>
--> void assign_stat(): <}>
--> void dprime(): <for>
--> void looping_stat(): <for>
--> void looping_stat(): <(>
--> void looping_stat(): <id>
--> void assign_stat_loop(): <id>
--> void assign_stat_loop(): <=>
--> void assign_stat_loop(): <id>
--> void expn(): <id>
--> void simple_expn(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <;>
--> void tprime(): <;>
--> void seprime(): <;>
--> void eprime(): <;>
--> void looping_stat(): <id>
--> void expn(): <id>
--> void simple_expn(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <<=>
--> void tprime(): <<=>
--> void seprime(): <<=>
--> void eprime(): <<=>
--> void relop(): <<=>
--> void relop(): <id>
--> void simple_expn(): <id>
--> void term(): <id>
--> void factor(): <id>
--> void factor(): <;>
--> void tprime(): <;>
--> void seprime(): <;>
--> void looping_stat(): <id>
--> void assign_stat_loop(): <id>
--> void assign_stat_loop(): <=>
--> void assign_stat_loop(): <id>
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
--> void factor(): <)>
--> void tprime(): <)>
--> void seprime(): <)>
--> void eprime(): <)>
--> void looping_stat(): <{>
--> void looping_stat(): <id>
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
--> void mulop(): <num>
--> void factor(): <num>
--> void factor(): <;>
--> void tprime(): <;>
--> void seprime(): <;>
--> void eprime(): <;>
--> void assign_stat(): <;>
--> void assign_stat(): <}>
--> void looping_stat(): <}>
--> void program(): ?
void program()(): Success.
```