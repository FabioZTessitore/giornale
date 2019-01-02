/* main.c */

#include <stdio.h>
#include "pagina.h"
#include "articolo.h"

int main()
{
  Articolo a1 = articolo_make("Titolo 1", "Testo 1");
  Articolo a2 = articolo_make("Titolo 2", "Testo 2");

  Pagina p = pagina_make();
  pagina_inserisciArticolo(&p, &a1);
  pagina_inserisciArticolo(&p, &a2);

  pagina_dump(&p);

  return 0;
}
