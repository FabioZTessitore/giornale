CC=gcc
CFLAGS=-Wall -ansi -pedantic

TEST_LDLIBS=-lcunit

main: main.o giornale.o pagina.o articolo.o utils.o

test: test.o giornale.o pagina.o articolo.o utils.o
	$(CC) $^ -o $@ $(TEST_LDLIBS)

main.o: main.c giornale.h pagina.h articolo.h
giornale.o: giornale.c giornale.h pagina.h utils.h
pagina.o: pagina.c pagina.h articolo.h
articolo.o: articolo.c articolo.h utils.h
utils.o: utils.c utils.h

test.o: test.c giornale.h pagina.h articolo.h utils.h

.PHONY: clean
clean:
	rm -f main test *.o
