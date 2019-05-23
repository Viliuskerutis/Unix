/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_libtest02.c */
#include <stdio.h>
#include "vilker3_testlib02.h"

int main( int argc, char *argv[] ){
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   vilker3_libvar02 = 4.2;
   vp_testlib( 864100913 );
   return 0;
}
