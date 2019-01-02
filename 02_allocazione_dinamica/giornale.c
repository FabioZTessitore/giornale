/* giornale.c */

#include <stdio.h>
#include <stdlib.h>
#include "giornale.h"
#include "pagina.h"
#include "utils.h"

Giornale *giornale_make(const char * const nomeGiornale)
{
  Giornale *giornale = (Giornale *)malloc(sizeof(Giornale));
  int i;

  giornale->nPagine = 0;
  giornale->nome = strAllocAndSafeCopy(nomeGiornale);

  for (i = 0; i < GIORNALE_MAX_PAGINE; i++) {
    giornale->pagine[i] = NULL;
  }

  return giornale;
}

void giornale_destroy(Giornale **unGiornale)
{
  int i;

  if (*unGiornale == NULL) {
    return;
  }

  for (i = 0; i < GIORNALE_MAX_PAGINE; i++) {
    pagina_destroy(&((*unGiornale)->pagine[i]));
  }

  free(*unGiornale);
  *unGiornale = NULL;
}

void giornale_inserisciPagina(Giornale * const unGiornale, Pagina * const unaPagina)
{
    if (unGiornale->nPagine >= GIORNALE_MAX_PAGINE)
      return;

    unGiornale->pagine[ unGiornale->nPagine ] = unaPagina;
    unGiornale->nPagine++;
}

void giornale_dump(const Giornale * const unGiornale)
{
  int i;

  printf("   --- %s ---\n\n", unGiornale->nome);

  for (i = 0; i < unGiornale->nPagine; i++) {
    printf("Pagina #%d\n", i+1);
    pagina_dump(unGiornale->pagine[i]);
    puts("****************************************\n");
  }
}
