/* pagina.h */

#ifndef PAGINA_H
#define PAGINA_H

#include "articolo.h"

#define PAGINA_MAX_ARTICOLI 3

struct pagina {
  int nArticoli;
  Articolo articoli[PAGINA_MAX_ARTICOLI];
};

typedef struct pagina Pagina;

Pagina pagina_make();
void pagina_inserisciArticolo(Pagina * const unaPagina, const Articolo * const unArticolo);
void pagina_dump(const Pagina * const unaPagina);
void pagina_copy(Pagina * const dstPagina, const Pagina * const srcPagina);

#endif
