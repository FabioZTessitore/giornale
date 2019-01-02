/* pagina.c */

#include <stdio.h>
#include "articolo.h"
#include "pagina.h"

Pagina pagina_make()
{
  Pagina pagina;

  pagina.nArticoli = 0;

  return pagina;
}

void pagina_inserisciArticolo(Pagina * const unaPagina, const Articolo * const unArticolo)
{
  if (unaPagina->nArticoli >= PAGINA_MAX_ARTICOLI)
    return;

  articolo_copy(&(unaPagina->articoli[ unaPagina->nArticoli ]), unArticolo);
  unaPagina->nArticoli++;
}

void pagina_dump(const Pagina * const unaPagina)
{
  int i;

  for (i = 0; i < unaPagina->nArticoli; i++) {
    articolo_dump(&(unaPagina->articoli[i]));
    puts("--------------------");
  }
}

void pagina_copy(Pagina * const dstPagina, const Pagina * const srcPagina)
{
  int i;

  dstPagina->nArticoli = srcPagina->nArticoli;

  for (i = 0; i < dstPagina->nArticoli; i++) {
    articolo_copy(&(dstPagina->articoli[i]), &(srcPagina->articoli[i]));
  }
}
