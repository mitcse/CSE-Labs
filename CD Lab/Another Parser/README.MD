# Simple C like parser

Parser for the grammer:

```
start -> SUBSTRACT idnum from_clause
idnum -> term, idnum | term
term -> id | num
from_clause -> FROM identifier
identifier -> id, identifier | id
```

### Usage

- `make`
- Input in any file, say `temp.c`
- Run `./notclang temp.c`
- Build and execute `rdparser.c`

### Sample Input

```
>> cat temp.c
SUBSTRACT 100, 120, 140, nope FROM beats, balls, apple
```

#### Lexer (notclang) output

```
<SUBSTRACT> <num> <,> <num> <,> <num> <,> <id> <FROM> <id> <,> <id> <,> <id> 
```

#### Parser output

```
TBA
```