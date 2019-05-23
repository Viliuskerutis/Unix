/* Vilius Kerutis IFF-6/7 */
/* Failas: vilker3_nice01.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <time.h>

int main( int argc, char * argv[] ){
   int nc;
   clock_t start, end;
   double cpu_time_used;
   time_t begtime, result, endresult;
   start = clock();
   result = time(NULL);
   begtime = time(NULL);
   endresult = (int)result + 5;
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   if( argc != 2 ){
      printf( "Naudojimas:\n %s skaicius\n", argv[0] );
      exit( 255 );
   }
   nc = nice( atoi(argv[1]) );
   if( nc == -1 ){
      printf( "Nepavyko pakeisti prioriteto.\n" );
      exit( 255 );
   }
   printf( "Prioritetas pakeistas i: %d\n", atoi( argv[1] ) );
   while( result != endresult ){
    result = time(NULL);
   }
   result = time(NULL);
   printf("Pradzios laikas: %s", asctime(localtime(&begtime)));
   printf("Pabaigos laikas: %s", asctime(localtime(&result)));
   printf("Laiku skirtumas: %ds\n", (int)(result - begtime) );
   end = clock();
   cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf( "CPU sunaudotas laikas: %f\n", cpu_time_used );
   return 0;
}

