/* pagina.h */

#ifndef PAGINA_H
#define PAGINA_H

#include "articolo.h"

#define PAGINA_MAX_ARTICOLI 3

struct pagina {
  int nArticoli;
  Articolo *articoli[PAGINA_MAX_ARTICOLI];
};

typedef struct pagina Pagina;

Pagina *pagina_make();
void pagina_destroy(Pagina **unaPagina);
void pagina_inserisciArticolo(Pagina * const unaPagina, Articolo * const unArticolo);
void pagina_dump(const Pagina * const unaPagina);
Pagina *pagina_clone(const Pagina * const srcPagina);

#endif
