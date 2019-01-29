#include "CUnit/Basic.h"
#include "utils.h"
#include "articolo.h"
#include "pagina.h"
#include "giornale.h"

/* Istruzioni di compilazione ed esecuzione:
 *
 * $ make test
 * $ ./test
 */

/* suite Utils */
int suite_utils_init()
{
  /* nothing to do */

  return 0;
}

int suite_utils_cleanup()
{
  /* nothing to do */

  return 0;
}

void test_StringCopy()
{
  /* given */
  char dst1[80];
  char dst2[3];
  char *src1 = "Hello";
  char *src2 = "Hello World";
  char *src3 = "Bye";

  /* when */
  strSafeCopy(dst1, src1, 80);
  strSafeCopy(dst2, src1, 3);
  /* then */
  CU_ASSERT_STRING_EQUAL(dst1, src1);
  CU_ASSERT_NSTRING_EQUAL(dst2, src1, 2);

  /* when */
  strSafeCopy(dst1, src2, 80);
  strSafeCopy(dst2, src2, 3);
  /* then */
  CU_ASSERT_STRING_EQUAL(dst1, src2);
  CU_ASSERT_NSTRING_EQUAL(dst2, src2, 2);

  /* when */
  strSafeCopy(dst1, src3, 80);
  strSafeCopy(dst2, src3, 3);
  /* then */
  CU_ASSERT_STRING_EQUAL(dst1, src3);
  CU_ASSERT_NSTRING_EQUAL(dst2, src3, 2);
}
/* end suite Utils */

/* suite Articolo */
int suite_articolo_init()
{
  /* nothing to do */

  return 0;
}

int suite_articolo_cleanup()
{
  /* nothing to do */

  return 0;
}

void test_Articolo()
{
  Articolo art = articolo_make("Titolo", "Testo");

  CU_ASSERT_STRING_EQUAL(art.titolo, "Titolo");
  CU_ASSERT_STRING_EQUAL(art.testo, "Testo");
}

void test_ArticoloCopy()
{
  Articolo art = articolo_make("Titolo", "Testo");
  Articolo art2;

  articolo_copy(&art2, &art);

  CU_ASSERT_STRING_EQUAL(art2.titolo, "Titolo");
  CU_ASSERT_STRING_EQUAL(art2.testo, "Testo");
}
/* end suite Articolo */

/* suite Pagina */
int suite_pagina_init()
{
  /* nothing to do */

  return 0;
}

int suite_pagina_cleanup()
{
  /* nothing to do */

  return 0;
}

void test_Pagina()
{
  Pagina pag = pagina_make();

  CU_ASSERT_EQUAL(pag.nArticoli, 0);
}

void test_PaginaAddArticolo()
{
  Pagina pag = pagina_make();
  Articolo art = articolo_make("Titolo", "Testo");
  pagina_inserisciArticolo(&pag, &art);

  CU_ASSERT_EQUAL(pag.nArticoli, 1);
  CU_ASSERT_STRING_EQUAL(pag.articoli[0].titolo, "Titolo");
  CU_ASSERT_STRING_EQUAL(pag.articoli[0].testo, "Testo");
}

void test_PaginaCopy()
{
  Pagina pag = pagina_make();
  Pagina pag2;
  Articolo art;

  pagina_copy(&pag2, &pag);
  CU_ASSERT_EQUAL(pag2.nArticoli, 0);

  art = articolo_make("Titolo", "Testo");
  pagina_inserisciArticolo(&pag, &art);
  pagina_copy(&pag2, &pag);
  CU_ASSERT_EQUAL(pag2.nArticoli, 1);
  CU_ASSERT_STRING_EQUAL(pag2.articoli[0].titolo, "Titolo");
  CU_ASSERT_STRING_EQUAL(pag2.articoli[0].testo, "Testo");
}

void test_PaginaMaxArticoli()
{
  Pagina pag;
  Articolo art = articolo_make("Titolo", "Testo");
  int i;
  for (i = 0; i < PAGINA_MAX_ARTICOLI; i++) {
    pagina_inserisciArticolo(&pag, &art);
  }

  CU_ASSERT_EQUAL(pag.nArticoli, PAGINA_MAX_ARTICOLI);

  
  pagina_inserisciArticolo(&pag, &art);
  CU_ASSERT_EQUAL(pag.nArticoli, PAGINA_MAX_ARTICOLI);
}
/* end suite Pagina */

/* suite Giornale */
int suite_giornale_init()
{
  /* nothing to do */

  return 0;
}

int suite_giornale_cleanup()
{
  /* nothing to do */

  return 0;
}

void test_Giornale()
{
  Giornale g = giornale_make("Titolo");

  CU_ASSERT_EQUAL(g.nPagine, 0);
  CU_ASSERT_STRING_EQUAL(g.nome, "Titolo");
}

void test_GiornaleAddPagina()
{
  Giornale g = giornale_make("Titolo Giornale");
  Pagina pag = pagina_make();
  Articolo art = articolo_make("Titolo", "Testo");
  pagina_inserisciArticolo(&pag, &art);
  giornale_inserisciPagina(&g, &pag);

  CU_ASSERT_EQUAL(g.nPagine, 1);
  CU_ASSERT_STRING_EQUAL(g.pagine[0].articoli[0].titolo, "Titolo");
  CU_ASSERT_STRING_EQUAL(g.pagine[0].articoli[0].testo, "Testo");
}

void test_GiornaleMaxPagine()
{
  Giornale g = giornale_make("Titolo Giornale");
  Pagina pag = pagina_make();
  Articolo art = articolo_make("Titolo", "Testo");
  int i;

  pagina_inserisciArticolo(&pag, &art);

  for (i = 0; i < GIORNALE_MAX_PAGINE; i++) {
    giornale_inserisciPagina(&g, &pag);
  }

  CU_ASSERT_EQUAL(g.nPagine, GIORNALE_MAX_PAGINE);

  giornale_inserisciPagina(&g, &pag);
  CU_ASSERT_EQUAL(g.nPagine, GIORNALE_MAX_PAGINE);
}
/* end suite Giornale */

int main()
{
  CU_pSuite pSuiteUtils = NULL;
  CU_pSuite pSuiteArticolo = NULL;
  CU_pSuite pSuitePagina = NULL;
  CU_pSuite pSuiteGiornale = NULL;

  /* inizializza il registro dei test */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* suite Utils */
  pSuiteUtils = CU_add_suite("Utils", suite_utils_init, suite_utils_cleanup);
  if (NULL == pSuiteUtils) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if (NULL == CU_add_test(pSuiteUtils, "test string copy", test_StringCopy))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* suite Articolo */
  pSuiteArticolo = CU_add_suite("Articolo", suite_articolo_init, suite_articolo_cleanup);
  if (NULL == pSuiteArticolo) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if ((NULL == CU_add_test(pSuiteArticolo, "test making Articolo", test_Articolo)) ||
      (NULL == CU_add_test(pSuiteArticolo, "test copying Articolo", test_ArticoloCopy)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* suite Pagina */
  pSuitePagina = CU_add_suite("Pagina", suite_pagina_init, suite_pagina_cleanup);
  if (NULL == pSuitePagina) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if ((NULL == CU_add_test(pSuitePagina, "test making Pagina", test_Pagina)) ||
      (NULL == CU_add_test(pSuitePagina, "test add Articolo to Pagina", test_PaginaAddArticolo)) ||
      (NULL == CU_add_test(pSuitePagina, "test copying Pagina", test_PaginaCopy)) ||
      (NULL == CU_add_test(pSuitePagina, "test Pagina max Articoli", test_PaginaMaxArticoli)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* suite Giornale */
  pSuiteGiornale = CU_add_suite("Giornale", suite_giornale_init, suite_giornale_cleanup);
  if (NULL == pSuiteGiornale) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  if ((NULL == CU_add_test(pSuiteGiornale, "test making Giornale", test_Giornale)) ||
      (NULL == CU_add_test(pSuiteGiornale, "test add Pagina to Giornale", test_GiornaleAddPagina)) ||
      (NULL == CU_add_test(pSuiteGiornale, "test Giornale max Pagine", test_GiornaleMaxPagine)))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }


  /* esegue i test */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();

  return CU_get_error();
}
