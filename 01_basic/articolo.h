/* articolo.h */

#ifndef ARTICOLO_H
#define ARTICOLO_H

#define ARTICOLO_TITOLO_MAX_LEN 80
#define ARTICOLO_TESTO_MAX_LEN 1024

struct articolo {
  char titolo[ARTICOLO_TITOLO_MAX_LEN];
  char testo[ARTICOLO_TESTO_MAX_LEN];
};

typedef struct articolo Articolo;

Articolo articolo_make(const char * const ilTitolo, const char * const ilTesto);
void articolo_dump(const Articolo * const unArticolo);
void articolo_copy(Articolo * const dstArticolo, const Articolo * const srcArticolo);

#endif
