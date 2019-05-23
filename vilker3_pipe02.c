/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_pipe02.c */

#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int kp_test_open(const char *name);
int kp_test_openwr();
int kp_test_close(int fd);

int kp_test_openwr(){
   int d;
   d = open( "result.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
   if( d == -1 ){
      perror( "Nepavyko atidaryti rezultatu failo.\n" );
      exit(1);
   }
   printf( "dskr = %d\n", d );
   return d;
}

int kp_test_open(const char *name){
   int dskr;
   dskr = open( name, O_RDONLY );
   if( dskr == -1 ){
      perror( name );
      exit(1);
   }
   printf( "dskr = %d\n", dskr );
   return dskr;
}
int kp_test_close(int fd){
   int rv;
   rv = close( fd );
   if( rv != 0 ) perror ( "close() failed" );
   else puts( "closed" );
   return rv;
}

int main ( int argc, char *argv[] ){
   int fd[2];
   pid_t pid, x;
   int status;
   int d, k;
   char buffer[10000];
   char buf[10000];
   ssize_t bytes_read;
   long size;
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   if( argc != 2 ){
      printf( "Naudojimas:\n %s failas\n", argv[0] );
      exit( 255 );
   }

   if( pipe( fd ) == -1 ){
      fprintf( stderr, "Nepavyko sukurti programinio kanalo !\n" );
      exit( 1 );
   }
   pid = fork();
   if( pid == 0 ){
      sleep( 1 );
      if( read( fd[0], buf, size ) != size ){
        fprintf(stderr, "Klaida skaitant" );
        exit( 5 );
       }
      printf ( "(vaikas) Skaitau kanalo turini.\n");
      k = kp_test_openwr();
      write( k, buf, size );
      exit( 1 );
   }
   else if( pid == -1 ){
      fprintf ( stderr, "Nepavyko sukurti vaiko !\n" );
      exit( 4 );
   }
   else{
      d = kp_test_open( argv[1] );
      fseek(struct FILE *argv[1], 0, SEEK_END); // seek to end of file
      size = ftell(struct FILE *argv[1]); // get current file pointer
      fseek(struct FILE *argv[1], 0, SEEK_SET); // seek back to beginning of file
      read(d, buffer, size);
      printf("(tevas) Dedu failo %s turini i kanala\n", argv[1] );
      if( write( fd[1], buffer, size ) != size ){
      fprintf( stderr, "Klaida rasant" );
      exit( 2 );
      }
      x = wait( &status );
      kp_test_close( d );
      return 0;
   }
   return 0;
}
