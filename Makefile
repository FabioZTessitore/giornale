CC=gcc
CFLAGS=-Wall -ansi -pedantic

main: main.o articolo.o utils.o

articolo.o: articolo.c articolo.h utils.h
utils.o: utils.c utils.h

.PHONY: clean
clean:
	rm -f main *.o
