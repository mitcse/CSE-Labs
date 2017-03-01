# Simple C like parser

Parser for the grammer:

```
program -> main () { declarations assign_stat }
declarations -> data-type identifier_list; declarations | e
data_type -> int | char
identifier_list -> id | id , identifier_list
assign_stat -> id = id; | id = num;
```

### Usage

- `make`
- Input in any file, say `temp.c`
- Run `./notclang temp.c`
- Build and execute `rdparser.c`