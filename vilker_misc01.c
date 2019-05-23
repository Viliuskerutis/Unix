/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_misc01.c */
#include <sys/types.h>
#include <sys/stat.h>

int main( int argc, char *argv[] ){
   int status;
   status = mkdir("/export/home/vilker3/mkdirtest", 0777 );
   printf( "Statusas: %d \n", status );
}
