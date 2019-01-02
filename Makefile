CC=gcc
CFLAGS=-Wall -ansi -pedantic

main: main.o pagina.o articolo.o utils.o

pagina.o: pagina.c pagina.h articolo.h
articolo.o: articolo.c articolo.h utils.h
utils.o: utils.c utils.h

.PHONY: clean
clean:
	rm -f main *.o
