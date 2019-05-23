/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_testlib02.c */
#include <stdio.h>
#include "vilker3_testlib02.h"
double vilker3_libvar02;
int vp_testlib( int a ){
   printf( "Dynamic library for testing, %s\n", __FILE__ );
   printf( "\tparameter: \"%d\"\n", a );
   printf( "\tlib variable = %f\n", vilker3_libvar02 );
   return 0;
}
