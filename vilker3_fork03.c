/* Vilius Kerutis IFF-6/7 vilekr3 */
/* Failas: vilker3_fork03.c */
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char * argv[] ){
char command[50];
int s;
pid_t p1, child, rv;
   strcpy( command, "ps -o pid,ppid,s" );
   system(command);
child = fork();
if(child == 0){
p1 = getpid();
kill(p1, SIGKILL);
system(command);
sleep(1);
}
rv = wait(&s);
system(command);
return 0;
}
