# Variables
IDIR = include
SDIR = src
ODIR = obj
LDIR = lib
BDIR = bin

CC     = gcc -Wall -Wextra -Werror -Wfatal-errors
CFLAGS = -I$(IDIR)
CLIBS  = -lm -lstdc++

.DEFAULT_GOAL := all
.PHONY: all run clean

_DEPS = Debug.h HelperFunctions.h MClass.h
DEPS  = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o MClass.o HelperFunctions.o
OBJ  = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: run

run: $(BDIR)/Feigenbaum
	$(BDIR)/Feigenbaum

$(BDIR)/Feigenbaum: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(CLIBS)

$(ODIR)/%.o: $(SDIR)/%.C $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*
