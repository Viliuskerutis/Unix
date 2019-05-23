/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_pathconf.c */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

long do_pathconf(const char *path, int flag);

long do_pathconf(const char *path, int flag){
long k;
k = pathconf( path , flag );
return k;
}

int main( int argc, char *argv[] ){
   long result_path;
   long result_name;
   if( argc != 2 ){
      printf( "Naudojimas:\n %s turi buti ivestas failo ar katalogo kelias.", argv[0] );
      exit( 255 );
   }
   result_path = do_pathconf( argv[1] , _PC_PATH_MAX);
   printf( "result PATH_MAX = %ld\n", result_path );
   result_name = do_pathconf( argv[1] , _PC_NAME_MAX);
   printf( "result NAME_MAX = %ld\n", result_name );
   return 0;
}
