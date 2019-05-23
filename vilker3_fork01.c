/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_fork01a.c */
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main( int argc, char * argv[] ){
pid_t p1, p2;
fork();
fork();
p1 = getpid();
p2 = getppid();
printf( "PID: %ld   PPID: %ld \n", p1, p2 );
return 0;
}
