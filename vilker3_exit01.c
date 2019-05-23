#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void functionA () {
   printf("This is functionA\n");
}

void functionB () {
   printf("This is functionB\n");
}

void functionC () {
   printf("This is functionC\n");
}

int main () {
   /* register the termination function */
   atexit( functionA );
   atexit( functionB );
   atexit( functionC );
   printf("Starting  main program...\n");
   /* exit(255); */
   /* abort(); */
   /* return(255); */
   /* _Exit(255); */
   /* _exit(255); */
   printf("Exiting main program...\n");

   return(0);
}
