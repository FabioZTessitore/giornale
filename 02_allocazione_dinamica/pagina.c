/* pagina.c */

#include <stdio.h>
#include <stdlib.h>
#include "articolo.h"
#include "pagina.h"

Pagina *pagina_make()
{
  Pagina *pagina = (Pagina *)malloc(sizeof(Pagina));
  int i;

  pagina->nArticoli = 0;

  for (i = 0; i < PAGINA_MAX_ARTICOLI; i++) {
    pagina->articoli[i] = NULL;
  }

  return pagina;
}

void pagina_destroy(Pagina **unaPagina)
{
  int i;

  if (*unaPagina == NULL) {
    return;
  }

  for (i = 0; i < PAGINA_MAX_ARTICOLI; i++) {
    articolo_destroy(&((*unaPagina)->articoli[i]));
  }

  free(*unaPagina);
  *unaPagina = NULL;
}

void pagina_inserisciArticolo(Pagina * const unaPagina, const Articolo * const unArticolo)
{
  if (unaPagina->nArticoli >= PAGINA_MAX_ARTICOLI)
    return;

  unaPagina->articoli[ unaPagina->nArticoli ] = articolo_clone(unArticolo);
  unaPagina->nArticoli++;
}

void pagina_dump(const Pagina * const unaPagina)
{
  int i;

  for (i = 0; i < unaPagina->nArticoli; i++) {
    articolo_dump(unaPagina->articoli[i]);
    puts("--------------------");
  }
}

Pagina *pagina_clone(const Pagina * const srcPagina)
{
  Pagina *dstPagina = (Pagina *)malloc(sizeof(Pagina));
  int i;

  dstPagina->nArticoli = srcPagina->nArticoli;

  for (i = 0; i < dstPagina->nArticoli; i++) {
    dstPagina->articoli[i] = articolo_clone(srcPagina->articoli[i]);
  }

  return dstPagina;
}
