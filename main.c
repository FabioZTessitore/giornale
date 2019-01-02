/* main.c */

#include <stdio.h>
#include "articolo.h"

int main()
{
  Articolo a = articolo_make("Titolo", "Testo");
  articolo_dump(&a);

  return 0;
}
