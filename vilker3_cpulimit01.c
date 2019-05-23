/* Vilius Kerutis IFF-6/7 vilekr3 */
/* Failas: vilker3_limits01.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/resource.h>
int kp_change_filelimit();

int kp_change_filelimit(){
   struct rlimit rl;
   int a = 1;
   int b = 0;
   getrlimit( RLIMIT_CPU, &rl );
   printf( "RLIMIT_CPU dabartinis: %ld\n", rl.rlim_cur);
   rl.rlim_cur = 1;
   rl.rlim_max = 1;
   setrlimit( RLIMIT_CPU, &rl );
   rl.rlim_cur = 0;
   rl.rlim_max = 0;
   setrlimit( RLIMIT_CORE, &rl );
   printf( "RLIMIT_CPU pakeistas: %ld\n", rl.rlim_cur );
   while((a = 1) != NULL){
   b = b + 1;
}
   printf("Skaitliukas prasisuko %d kartus", b );
   return 1;
}

int main( int argc, char *argv[] ){
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   kp_change_filelimit();
   return 0;
}
