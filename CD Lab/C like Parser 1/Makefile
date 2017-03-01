# Makefile

IDIR =include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=src
LDIR =lib

LIBS=-lm

_DEPS = common.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

_OBJ = util.o lexer.o preprocessor.o test.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

notclang: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *.o $(OBJ)