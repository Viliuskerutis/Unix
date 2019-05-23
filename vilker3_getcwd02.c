
/* Vilius Kerutis IFF-6/7 vilker3  */
/* Failas: vilker3_getcwd02.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int kp_test_open(const char *name);
int kp_test_getcwd();

int kp_test_getcwd(){
   char *cwd;
   cwd = getcwd( NULL, pathconf( ".", _PC_PATH_MAX) );
   puts( cwd );
   free( cwd );
   return 1;
}
int kp_test_open(const char *name){
   int dskr;
   dskr = open( name, O_RDONLY );
   if( dskr == -1 ){
      perror( name );
      exit(1);
   }
   printf( "dskr = %d\n", dskr );
   return dskr;
}
int main( int argc, char *argv[] ){
   int d;
   kp_test_getcwd();
   if( argc != 2 ){
      printf( "Naudojimas:\n %s failas_ar_katalogas\n", argv[0] );
      exit( 255 );
   }
   d = kp_test_open( argv[1] );
   chdir( "/tmp" );
   kp_test_getcwd();
   fchdir( d );
   kp_test_getcwd();
   return 0;
}
