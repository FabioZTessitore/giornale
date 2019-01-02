/* articolo.c */

#include <stdio.h>
#include <stdlib.h>
#include "articolo.h"
#include "utils.h"

Articolo *articolo_make(const char * const ilTitolo, const char * const ilTesto)
{
  Articolo *unArticolo = (Articolo *)malloc(sizeof(Articolo));

  unArticolo->titolo = strAllocAndSafeCopy(ilTitolo);
  unArticolo->testo = strAllocAndSafeCopy(ilTesto);

  return unArticolo;
}

void articolo_destroy(Articolo **unArticolo)
{
  if (*unArticolo == NULL)
    return;

  strSafeFree(&((*unArticolo)->titolo));
  strSafeFree(&((*unArticolo)->testo));
  free(*unArticolo);
  *unArticolo = NULL;
}

void articolo_dump(const Articolo * const unArticolo)
{
  puts(unArticolo->titolo);
  putchar('\n');
  puts(unArticolo->testo);
  putchar('\n');
}

Articolo *articolo_clone(const Articolo * const srcArticolo)
{
  Articolo *dstArticolo = (Articolo *)malloc(sizeof(Articolo));

  dstArticolo->titolo = strAllocAndSafeCopy(srcArticolo->titolo);
  dstArticolo->testo = strAllocAndSafeCopy(srcArticolo->testo);

  return dstArticolo;
}
