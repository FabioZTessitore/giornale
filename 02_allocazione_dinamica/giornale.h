/* giornale.h */

#ifndef GIORNALE_H
#define GIORNALE_H

#include "pagina.h"

#define GIORNALE_MAX_PAGINE 40

struct giornale {
  int nPagine;
  Pagina *pagine[GIORNALE_MAX_PAGINE];
  char *nome;
};

typedef struct giornale Giornale;

Giornale *giornale_make(const char * const nomeGiornale);
void giornale_destroy(Giornale **unGiornale);
void giornale_inserisciPagina(Giornale * const unGiornale, const Pagina * const unaPagina);
void giornale_dump(const Giornale * const unGiornale);

#endif
