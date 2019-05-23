/* Kestutis Paulikas KTK kespaul */
/* Failas: kespaul_test_lib01a.c */
#include <stdio.h>
#include "kespaul_lib01.h"
int main(){
   printf( "(C) 2013 kestutis Paulikas, %s\n", __FILE__ );
   kespaul_libfunc01( "Library test 1" );
   kespaul_libvar01 = 5.1;
   kespaul_libfunc01( "Library test 2" );
   return 0;
}
