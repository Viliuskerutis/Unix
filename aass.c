/* Kestutis Paulikas KTK kespaul */
/* Failas: kespaul_wait01.c */
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main( int argc, char * argv[] ){
   pid_t child, rv;
   int st;
   printf( "(C) 2013 kestutis Paulikas, %s\n", __FILE__ );
   child = fork();
   if( child == 0 ){
      sleep(5);
      return 5;
   }
   printf( "Child PID = %ld\n", (long)child );
   rv = wait( &st );
   printf( "wait() = %ld\nst = %x\n", (long)rv, st );
   printf( "Child exit code = %d\n", WEXITSTATUS(st) );
   return 0;
}
