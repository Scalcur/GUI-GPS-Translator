#=======================================================
#
#      Authors:    Kosorotova Valeria
#                  Pasechnikov Vyacheslav
#
#      15/8/2021
#
#=======================================================

# change application name here (executable output name)
TARGET=gui_gps_translator

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`  
GLIB=`pkg-config --cflags --libs glib-2.0`
GIOLIB=`pkg-config --cflags --libs gio-2.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) $(GLIB) $(GIOLIB) -Wl,--export-all-symbols

OBJ_1= main.o 
OBJ_2= algorithm.o
OBJ_3= gui_gps_translator-resources.o

OBJS = $(OBJ_1) $(OBJ_2) $(OBJ_3)

all: gui_gps_translator-resources.c gui_gps_translator-resources.h gui_gps_translator 
	
    
gui_gps_translator: $(OBJS)
	$(LD) -o $(TARGET) build/$(OBJ_1) build/$(OBJ_2) build/$(OBJ_3) $(LDFLAGS) -mwindows

main.o: src/main.c
	$(CC) -c $(CCFLAGS) src/main.c $(GTKLIB) $(GLIB) $(GIOLIB) -o build/main.o

algorithm.o: src/algorithm.c
	$(CC) -c $(CCFLAGS) src/algorithm.c $(GTKLIB) $(GLIB) $(GIOLIB) -o build/algorithm.o

gui_gps_translator-resources.c:
	glib-compile-resources --target=src/gui_gps_translator-resources.c --sourcedir=glade --generate-source --c-name gui_gps_translator glade/gui_gps_translator.gresource.xml

gui_gps_translator-resources.h:
	glib-compile-resources --target=src/gui_gps_translator-resources.h --sourcedir=glade --generate-header --c-name gui_gps_translator glade/gui_gps_translator.gresource.xml

gui_gps_translator-resources.o: src/gui_gps_translator-resources.c
	$(CC) -c $(CCFLAGS) src/gui_gps_translator-resources.c $(GTKLIB) $(GLIB) $(GIOLIB) -o build/gui_gps_translator-resources.o

clean:
	rm -f build/*.o $(TARGET)