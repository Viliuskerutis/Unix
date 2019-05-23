#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <string.h>
#define size 1048576

int kp_test_openw(const char *name);

int kp_test_openw(const char *name){
   int dskr;
   dskr = open( name, O_RDONLY );
   if( dskr == -1 ){
      perror( name );
      exit( 255 );
   }
   printf( "dskr = %d\n", dskr );
   return dskr;
}

int main( int argc, char * argv[] ){
   pid_t pid, pid2, pid3, rv;
   int st, d, k;
   void *a = NULL;
   void *b = NULL;
   if( argc != 4 ){
      printf( "Naudojimas:\n %s failas failas bitai\n", argv[0] );
      exit( 255 );
   }
   pid = fork();

   if( pid == 0 ){  //vaikas
   pid2 = fork();
     if(pid2 > 0){  //vaikas
     pid3 = fork();
         if(pid3 == 0){   //anukas2
k = kp_test_openw( argv[2] );
   lseek( k, size - 1, SEEK_SET );
   write( k, &k , 1 );
   b = mmap( NULL, size, PROT_READ, MAP_SHARED, k, 0 );
    if( b == MAP_FAILED ){
      perror( "mmap failed" );
      abort();
   }else{
    printf("vel zjbs zjbs\n");
  }
         }
     }
     if(pid2 == 0){  //anukas1
   d = kp_test_openw( argv[1] );
   lseek( d, size - 1, SEEK_SET );
   write( d, &d , 1 );
   a = mmap( NULL, size, PROT_READ, MAP_SHARED, d, 0 );
    if( a == MAP_FAILED ){
      perror( "mmap failed" );
      abort();
   }else{
    printf("zjbs\n");
  }
 }
   }
   if(pid > 0){
   sleep(1);
   }
   if(pid == -1){
   printf("Nepavyko sukurti vaiko.\n");
   }
   printf( "Proceso PID = %ld  Proceso PPID = %ld\n", (long)getpid(), (long)getppid() );
   rv = wait( &st );
   return 0;
}
