CC	= gcc
RM	= rm

all: comp link

comp: Prog28_04.o Prog28_04_FazContas.o

link: Prog28_04.o Prog28_04_FazContas.o
	$(CC) -o Prog28_04 Prog28_04.o Prog28_04_FazContas.o

Prog28_04.o: Prog28_04.c Prog28_04_FazContas.h
	$(CC) -c Prog28_04.c

Prog28_04_FazContas.o: Prog28_04_FazContas.c Prog28_04_FazContas.h
	$(CC) -c Prog28_04_FazContas.c

clean:
	$(RM) -f *.o Prog28_04
