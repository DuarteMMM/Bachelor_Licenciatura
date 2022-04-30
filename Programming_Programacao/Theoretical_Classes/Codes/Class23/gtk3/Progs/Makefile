DB_FLAGS	= -Wall -g -ggdb 
#DB_FLAGS	= -O3

GTK_CMP		= `pkg-config --cflags --libs gtk+-3.0`
GTK_LIB		= `pkg-config --libs gtk+-3.0`

INCLUDE		= 

LIBS		=  $(GTK_LIB) -lm

LOPTS		=

CFLAGS		= $(DB_FLAGS) $(GTK_CMP)
LFLAGS		= $(DB_FLAGS)

CC		= gcc
CP		= cp
RM		= rm
LS		= ls

OBJS		= 

EXEC		= 

FAUX		= Gtk3_CssAux

DELFILES	= Gtk3_50_01_save.png Gtk3_45_09_save?.jpg

PROGS		= Gtk3_01_01 Gtk3_01_02  Gtk3_01_03 Gtk3_01_04\
			Gtk3_02_01 Gtk3_02_02 Gtk3_02_03 Gtk3_02_04\
			Gtk3_03_01 Gtk3_03_02 Gtk3_03_03 Gtk3_03_04 Gtk3_03_05 Gtk3_03_06\
			Gtk3_04_01 Gtk3_04_02\
			Gtk3_05_01 Gtk3_05_02 Gtk3_05_03 Gtk3_05_04 Gtk3_05_05\
			Gtk3_06_01 Gtk3_06_02 Gtk3_06_03\
			Gtk3_07_01 Gtk3_07_02 Gtk3_07_03 Gtk3_07_04\
			Gtk3_08_01 Gtk3_08_02 Gtk3_08_03\
			Gtk3_09_01 Gtk3_09_02 Gtk3_09_03 Gtk3_09_04 Gtk3_09_05 Gtk3_09_06 Gtk3_09_07 Gtk3_09_08\
			Gtk3_09_09 Gtk3_09_10 Gtk3_09_11 Gtk3_09_12 Gtk3_09_13 Gtk3_09_14 Gtk3_09_15 Gtk3_09_16\
			Gtk3_10_01 Gtk3_10_02 Gtk3_10_03 Gtk3_10_04\
			Gtk3_11_01 Gtk3_11_02 Gtk3_12_01 Gtk3_13_01 Gtk3_14_01\
			Gtk3_15_01 Gtk3_15_02 Gtk3_15_03 Gtk3_15_04 Gtk3_15_05\
			Gtk3_18_01 Gtk3_18_02 Gtk3_18_03\
			Gtk3_30_01 Gtk3_30_02 Gtk3_32_01 Gtk3_32_02\
			Gtk3_60_01 Gtk3_61_01 Gtk3_61_02 Gtk3_61_03\
			Gtk3_62_01 Gtk3_62_02 Gtk3_62_03 Gtk3_62_04 Gtk3_62_05 Gtk3_62_06 Gtk3_62_07 Gtk3_62_08\
			Gtk3_63_01 Gtk3_65_01 Gtk3_65_02 Gtk3_65_03 Gtk3_65_04\
			Gtk3_68_01 Gtk3_82_01 Gtk3_86_01


all: comp link

comp: 
	for fname in $(FAUX); do $(CC) $(CFLAGS) -c $$fname.c ; done
	for fname in $(PROGS); do $(CC) $(CFLAGS) -c $$fname.c ; done

link: 
	for fname in $(PROGS); do $(CC) $(LFLAGS) -o $$fname $$fname.o Gtk3_CssAux.o $(LIBS) ; done

clean:
	$(RM) -f *~ *.o $(PROGS) $(DELFILES)
