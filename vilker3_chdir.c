
/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_chdir.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int kp_test_chdir();
int kp_test_chdir(){
   int chd;
   chd = chdir(".");
   puts( chd );
   free( chd );
   return 1;
}
int main(){
   kp_test_chdir();
   return 0;
}
