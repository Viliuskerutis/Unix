/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_dynload02.c */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int (*fptr)( int s );
double *pd;

int main(){
   void *dl;
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   dl = dlopen( "libvilker302.so", RTLD_LAZY | RTLD_LOCAL );
   if( dl == NULL ){
      puts( dlerror() );
      exit(1);
   }
   pd = dlsym( dl, "vilker3_libvar02" );
   if( pd == NULL ){
      puts( dlerror() );
      exit(1);
   }
   *(void**)(&fptr) = dlsym( dl, "vp_testlib" );
   if( fptr == NULL ){
      puts( dlerror() );
      exit(1);
   }
   *pd = 5.2;
   (*fptr)( 12345 );
   dlclose( dl );
   return 0;
}
