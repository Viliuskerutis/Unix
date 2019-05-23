/* Vilius Kerutis IFF-š6/7 vilker3 */
/* Failas: vilker3_seek01.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <aio.h>

#define SIZE 1048576

int kp_test_open(const char *name);
int kp_test_close(int fd);

int kp_test_open(const char *name){
   int dskr;
   dskr = open( name, O_RDWR | O_CREAT | O_EXCL );
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
   else puts( "closed" );
   return rv;
}

int main( int argc, char * argv[] ){
   int d;
   off_t t;
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   if( argc != 2 ){
      printf( "Naudojimas:\n %s failas\n", argv[0] );
      exit( 255 );
   }
   d = kp_test_open( argv[1] );
   t = lseek( d, SIZE, SEEK_SET );
   if( t != -1 ){
   write( d, &d , 1 ); 
}
   kp_test_close( d );
   return 0;
}
