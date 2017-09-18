IDIR=../include
IDIR2=/usr/local/include
CC=g++
CFLAGS=-I$(IDIR)
TFLAG=-T$(IDIR2)

LIB=/usr/local/lib/libgtest.a
ODIR=obj

_DEPS = string_soma.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = testa_string_soma_stdin.o string_soma.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

SRC = testa_string_soma.c string_soma.c

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testa_string_soma_stdin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

coverage: $(OBJ)
	$(CC) $(CFLAGS) -ftest-coverage -fprofile-arcs -g $^ -o $@

test: $(SRC)
	$(CC) $(CFLAGS) $(TFLAG) -pthread $^ $(LIB) -o $@