/* Vilius Kerutis IFF-6/7 */
/* Failas: vilker3_mmap02.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <string.h>

int kp_test_open_wo(const char *name);
int kp_test_open_ro(const char *name);
int kp_test_close(int fd);
void* kp_test_mmapw( int d, int k );
int kp_test_munmap( void *a, int size );

int kp_test_munamp( void *a, int size ){
   int rv;
   rv = munmap( a, size );
   if( rv != 0 ){
      puts( "munmap failed" );
      abort();
   }
   return 1;
}
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
   dskr = open( name, O_RDWR | O_CREAT | O_TRUNC, 0640 );
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
void* kp_test_mmapw( int d, int k ){
   void *b = NULL;
   void *a = NULL;
   struct stat buffer;
   int status;
   status = fstat(k, &buffer);
   lseek( d, (size_t)buffer.st_size - 1, SEEK_SET );
   write( d, &d , 1 );
   printf( "Dydis: %d\n", (int)buffer.st_size );
   a = mmap( NULL, (size_t)buffer.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, d, 0);
   b = mmap( NULL, (size_t)buffer.st_size, PROT_READ, MAP_SHARED, k, 0 );
   if( a == MAP_FAILED || b == MAP_FAILED ){
      perror( "mmap failed" );
      abort();
   }
   memcpy( a, b, (size_t)buffer.st_size );
   kp_test_munamp( a, (size_t)buffer.st_size );
   kp_test_munamp( b, (size_t)buffer.st_size );
 return a;
}
int main( int argc, char * argv[] ){
   int d;
   int k;
   void *a = NULL;
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   if( argc != 3 ){
      printf( "Naudojimas:\n %s failas failas\n", argv[0] );
      exit( 255 );
   }
   k = kp_test_open_ro( argv[1] );
   d = kp_test_open_wo( argv[2] );
   a = kp_test_mmapw( d, k );
   kp_test_close( d );
   kp_test_close( k );
   return 0;
}
