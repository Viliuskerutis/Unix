
/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_readdir01.c */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <inttypes.h>

int main( int argc, char *argv[] ){
   DIR *d;
   int dfd;
   struct dirent *dp;

   if ((d = fdopendir((dfd = open( getcwd( NULL, pathconf( ".", _PC_PATH_MAX) ), O_RDONLY)))) == NULL) {
        fprintf(stderr, "Cannot open directory\n");
        exit(1);
    }
    while ((dp = readdir(d)) != NULL) {
         printf( "failo vardas: %s\n", dp->d_name );
         printf( "i-node: %d \n\n", (int)dp->d_ino );
    }
    closedir(d);
    return 0;
}
