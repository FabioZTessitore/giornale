/* articolo.c */

#include <stdio.h>
#include "articolo.h"
#include "utils.h"

Articolo articolo_make(const char * const ilTitolo, const char * const ilTesto)
{
  Articolo unArticolo;

  strSafeCopy(unArticolo.titolo, ilTitolo, ARTICOLO_TITOLO_MAX_LEN);
  strSafeCopy(unArticolo.testo, ilTesto, ARTICOLO_TESTO_MAX_LEN);

  return unArticolo;
}

void articolo_dump(const Articolo * const unArticolo)
{
  puts(unArticolo->titolo);
  putchar('\n');
  puts(unArticolo->testo);
  putchar('\n');
}
