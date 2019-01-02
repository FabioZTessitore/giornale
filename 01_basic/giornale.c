/* giornale.c */

#include <stdio.h>
#include "giornale.h"
#include "pagina.h"
#include "utils.h"

Giornale giornale_make(const char * const nomeGiornale)
{
  Giornale giornale;

  giornale.nPagine = 0;
  strSafeCopy(giornale.nome, nomeGiornale, GIORNALE_NOME_MAX_LEN);

  return giornale;
}

void giornale_inserisciPagina(Giornale * const unGiornale, const Pagina * const unaPagina)
{
    if (unGiornale->nPagine >= GIORNALE_MAX_PAGINE)
      return;

    pagina_copy(&(unGiornale->pagine[ unGiornale->nPagine ]), unaPagina);
    unGiornale->nPagine++;
}

void giornale_dump(const Giornale * const unGiornale)
{
  int i;

  printf("   --- %s ---\n\n", unGiornale->nome);

  for (i = 0; i < unGiornale->nPagine; i++) {
    printf("Pagina #%d\n", i+1);
    pagina_dump(&(unGiornale->pagine[i]));
    puts("****************************************\n");
  }
}
