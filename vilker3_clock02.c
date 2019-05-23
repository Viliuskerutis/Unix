/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_clock02.c */
#include <time.h>
#include <stdio.h>

int main( int argc, char *argv[] ){
   time_t result;
   result = time(NULL);
    printf("Laikas lokaliam formate: %s",
        asctime(localtime(&result)));
    printf("Laikas UTC(GMT) formate: %s", asctime(gmtime(&result)));
   return 0;
}
