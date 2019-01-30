/* main.c */

#include <stdio.h>
#include "giornale.h"
#include "pagina.h"
#include "articolo.h"

int main()
{
  Articolo *a1 = articolo_make("Titolo 1", "Testo 1");
  Articolo *a2 = articolo_make("Titolo 2", "Testo 2");

  Pagina *p = pagina_make();
  Giornale *g = giornale_make("GitHub Journal");

  pagina_inserisciArticolo(p, a1);
  pagina_inserisciArticolo(p, a2);

  giornale_inserisciPagina(g, p);

  giornale_dump(g);

  articolo_destroy(&a1);
  articolo_destroy(&a2);
  pagina_destroy(&p);
  giornale_destroy(&g);

  return 0;
}
