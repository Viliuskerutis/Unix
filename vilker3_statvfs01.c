/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_stat01.c */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include <langinfo.h>
#include <stdint.h>
#include <sys/statvfs.h>
#include <fcntl.h>

int main( int argc, char *argv[] ){
   struct stat buffer;
   int status;
   struct statvfs fsbuffer;
   int fsstatus;
   status = stat( argv[1] , &buffer);
   fsstatus = statvfs( argv[1] , &fsbuffer );
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

   printf( "Failu sistemos bloko dydis: %d \n", (int)fsbuffer.f_bsize );
   printf( "Failu sistemos tipas: %d \n", fsbuffer.f_basetype[FSTYPSZ] );
   printf( "Failu sistemos dydis: %d baitu\n", (int)(fsbuffer.f_blocks * fsbuffer.f_frsize) );
   printf( "Maksimalus failo kelio/vardo ilgis: %d \n", (int)fsbuffer.f_namemax );
   if ( fsbuffer.f_flag == ST_RDONLY) {
         printf( "File system is read-only\n");
     }
   if ( fsbuffer.f_flag == ST_NOSUID) {
         printf( "File system does not support setuid/setgid-bit semantics.\n");
     }
   if ( fsbuffer.f_flag == ST_NOTRUNC) {
         printf( "File system does not truncate files longer than NAME_MAX.\n");
     }
return 0;
}
