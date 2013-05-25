CC=gcc
CFLAGS=-O3 -Wall -ansi
INCLUDE=.
APPNAME=callmewash
INSTALL_PATH=/usr/bin/

$(APPNAME):io.o wash.o _time.o func.o
	$(CC) -o $(APPNAME) io.o wash.o _time.o func.o
io.o:io.h io.c head.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c io.c
wash.o:io.h io.c head.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c wash.c
_time.o:_time.h _time.c head.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c _time.c
func.o:
	$(CC) -I$(INCLUDE) $(CFLAGS) -c func.c

.PHONY:clean install uninstall
clean:
	rm -f *.o *.txt
install:
	mv $(APPNAME) $(INSTALL_PATH)
uninstall:
	rm -f $(INSTALL_PATH)/$(APPNAME)
