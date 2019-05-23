/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_fork02.c */
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main( int argc, char * argv[] ){
pid_t p1, p2, p3, p4;
p1 = getpid();
p2 = getppid();
printf( "Tevas: PID: %ld  PPID: %ld \n", p1, p2 );
fork();
p3 = getpid();
p4 = getppid();
printf( "PID: %ld  PPID: %ld \n", p3, p4 );
kill(p1, SIGKILL);
p3 = getpid();
p4 = getppid();
sleep(1);
printf( "Procesai po tevo proseco pabaigos: \nPID: %ld  PPID: %ld \n", p3, p4 );
return 0;
}
