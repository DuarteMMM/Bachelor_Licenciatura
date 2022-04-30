DB_FLAGS	= -g -ggdb 
#DB_FLAGS	= -O3

CFLAGS		= $(DB_FLAGS) -fPIC
LFLAGS		= $(DB_FLAGS)

OBJS_PESS	= Utils.o UtilsVect.o

PROGS		= TestProg_01 TestProg_02 TestProg_03 TestProg_04 

LIB_NAME	= libPessoal.a 
LIB_NAME_SO	= libPessoal.so

LIBS		= -lm

AR		= ar
CC		= gcc
CP		= cp
CPP		= g++
RM		= rm

all: comp lib lib_so link

comp: $(OBJS_PESS) TestProg_01.o TestProg_02.o TestProg_03.o TestProg_04.o 

link: $(PROGS) TestProg_01_a TestProg_01_so

comp: $(OBJS_PESS)

# Compilacao dos ficheiro ".c"

Utils.o: Utils.c Utils.h
	$(CC) $(CFLAGS) -c Utils.c

UtilsVect.o: UtilsVect.c UtilsVect.h Utils.h
	$(CC) $(CFLAGS) -c UtilsVect.c

TestProg_01.o: TestProg_01.c Utils.h
	$(CC) $(CFLAGS) -c TestProg_01.c

TestProg_02.o: TestProg_02.c Utils.h UtilsVect.h
	$(CC) $(CFLAGS) -c TestProg_02.c

TestProg_03.o: TestProg_03.c Utils.h UtilsVect.h
	$(CC) $(CFLAGS) -c TestProg_03.c

TestProg_04.o: TestProg_04.c Utils.h UtilsVect.h
	$(CC) $(CFLAGS) -c TestProg_04.c

# Biblioteca estatica

lib: comp
	$(AR) rsv $(LIB_NAME) $(OBJS_PESS)

# Biblioteca 'shared'

lib_so: comp
	$(CC) --share -o $(LIB_NAME_SO) $(OBJS_PESS)

# Link dos programas

TestProg_01: TestProg_01.o
	$(CC) $(LFLAGS) -o TestProg_01 TestProg_01.o $(LIB_NAME) $(LIBS)

TestProg_02: TestProg_02.o
	$(CC) $(LFLAGS) -o TestProg_02 TestProg_02.o $(LIB_NAME) $(LIBS)

TestProg_03: TestProg_03.o
	$(CC) $(LFLAGS) -o TestProg_03 TestProg_03.o $(LIB_NAME) $(LIBS)

TestProg_04: TestProg_04.o
	$(CC) $(LFLAGS) -o TestProg_04 TestProg_04.o $(LIB_NAME) $(LIBS)

# Link com a biblioteca estatica

TestProg_01_a: TestProg_01.o
	$(CC) $(LFLAGS) -o TestProg_01_a TestProg_01.o libPessoal.a -lm

# Link com a biblioteca shared

TestProg_01_so: TestProg_01.o
	$(CC) $(LFLAGS) -o TestProg_01_so TestProg_01.o -L./ -lPessoal -lm 

#
# Copiar para a directoria em que estao as "shared libraries".
# Isto tem de ser feito com privilegios, logo com cuidado.
#
#    make copy_to_lib
#
copy_to_lib:
	cp -i libPessoal.so /usr/lib/.

# Limpa ficheiros antigos e compilados e bibliotecas

clean:
	$(RM) -f *~ *.o $(LIB_NAME) $(LIB_NAME_SO) $(PROGS) TestProg_01_a TestProg_01_so
