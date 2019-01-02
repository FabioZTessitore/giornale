/* articolo.h */

#ifndef ARTICOLO_H
#define ARTICOLO_H

struct articolo {
  char *titolo;
  char *testo;
};

typedef struct articolo Articolo;

Articolo *articolo_make(const char * const ilTitolo, const char * const ilTesto);
void articolo_destroy(Articolo **unArticolo);
void articolo_dump(const Articolo * const unArticolo);
Articolo *articolo_clone(const Articolo * const srcArticolo);

#endif
