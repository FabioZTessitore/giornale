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

  unaPagina->articoli[ unaPagina->nArticoli ] = articolo_make(unArticolo->titolo, unArticolo->testo);
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
