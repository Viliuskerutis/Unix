/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_rw01.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <aio.h>

#define BUFFLEN 10000

int kp_test_close(FILE *fd);

int kp_test_close(FILE *fd){
   int rv;
   rv = fclose( fd );
   if( rv != 0 ) perror ( "close() failed" );
   return rv;
}

int main( int argc, char * argv[] ){
   FILE *dr;
   FILE *dw;
   char buffer[BUFFLEN];
   int bytes_read;
   int bytes_write;
   if( argc != 4  ){
      printf( "Naudojimas:\n %s failas failas baitai\n", argv[0] );
      exit( 255 );
   }
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   dr = fopen( argv[1], "r" );
   dw = fopen( argv[2], "w" );
   bytes_read = fread( buffer, sizeof(buffer[0]), atoi(argv[3]), dr );
   if( bytes_read != -1){
   bytes_write = fwrite( buffer, sizeof(buffer[0]), atoi(argv[3]), dw );
}
   if( bytes_read == bytes_write ){
   printf( "Buvo sekmingai nuskaityti ir irasyti %d baitai\n", bytes_read );
}
  kp_test_close( dr );
  kp_test_close( dw );
   return 0;
}
