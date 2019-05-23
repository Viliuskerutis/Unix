
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

#define BUFFLEN 1048576

int kp_test_open_ro(const char *name);
int kp_test_open_wo(const char *name);
int kp_test_close(int fd);

int kp_test_open_ro(const char *name){
   int dskr;
   dskr = open( name, O_RDONLY );
   if( dskr == -1 ){
      perror( name );
      exit(1);
   }
   return dskr;
}

int kp_test_open_wo(const char *name){
   int dskr;
   dskr = open( name, O_WRONLY | O_CREAT | O_TRUNC );
   if( dskr == -1 ){
      perror( name );
      exit(1);
   }
   return dskr;
}

int kp_test_close(int fd){
   int rv;
   rv = close( fd );
   if( rv != 0 ) perror ( "close() failed" );
   return rv;
}

int main( int argc, char * argv[] ){
   ssize_t dr;
   ssize_t dw;
   char buffer[BUFFLEN];
   int bytes_read;
   int bytes_write;
   if( argc != 4  ){
      printf( "Naudojimas:\n %s failas failas baitai\n", argv[0] );
      exit( 255 );
   }
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   dr = kp_test_open_ro( argv[1] );
   dw = kp_test_open_wo( argv[2] );
   bytes_read = read( dr, buffer, atoi(argv[3]) );
   if( bytes_read != -1){
   bytes_write = write( dw, buffer, (size_t)bytes_read );
}
   if( bytes_read == bytes_write ){
   printf( "Buvo sekmingai nuskaityti ir irasyti %d baitai\n", bytes_read );
}
  kp_test_close( dr );
  kp_test_close( dw );
   return 0;
}
