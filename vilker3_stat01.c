/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_stat01.c */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <langinfo.h>
#include <stdint.h>

int main( int argc, char *argv[] ){
   struct stat buffer;
   int status;

   status = lstat( argv[1] , &buffer);
   printf ("Informacija apie objekta: ");
   printf ( argv[1] );
   printf ( "\nSavininko ID: %-8d\n", buffer.st_uid );
   printf( "Objekto dydis: %d\n", (int)buffer.st_size);
   printf( "i-node: %d \n", (int)buffer.st_ino );
   printf("Failo leidimai: ");
   printf( (S_ISDIR(buffer.st_mode)) ? "d" : "-");
   printf( (buffer.st_mode & S_IRUSR) ? "r" : "-");
   printf( (buffer.st_mode & S_IWUSR) ? "w" : "-");
   printf( (buffer.st_mode & S_IXUSR) ? "x" : "-");
   printf( (buffer.st_mode & S_IRGRP) ? "r" : "-");
   printf( (buffer.st_mode & S_IWGRP) ? "w" : "-");
   printf( (buffer.st_mode & S_IXGRP) ? "x" : "-");
   printf( (buffer.st_mode & S_IROTH) ? "r" : "-");
   printf( (buffer.st_mode & S_IWOTH) ? "w" : "-");
   printf( (buffer.st_mode & S_IXOTH) ? "x" : "-");
   printf("\n");
   if ((buffer.st_mode & S_IFMT) == S_IFREG) {
         printf( "Failo tipas: regular file\n");
           }
   if ((buffer.st_mode & S_IFMT) == S_IFSOCK) {
         printf( "Failo tipas: socket\n");
           }
   if ((buffer.st_mode & S_IFMT) == S_IFLNK) {
         printf( "Failo tipas: symbolic link\n");
           }
   if ((buffer.st_mode & S_IFMT) == S_IFBLK) {
         printf( "Failo tipas: block device\n");
           }
   if ((buffer.st_mode & S_IFMT) == S_IFDIR) {
         printf( "Failo tipas: directory\n");
           }
   if ((buffer.st_mode & S_IFMT) == S_IFCHR) {
         printf( "Failo tipas: character device\n");
           }
   if ((buffer.st_mode & S_IFMT) == S_IFIFO) {
         printf( "Failo tipas: FIFO\n");
           }
return 0;
}
