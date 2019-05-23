/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_test.c */
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <string.h>
#define BUFFLEN 1048576
static int fd[2];
static int fd2[2];
static int received_sig = 0;
int il_child( void );
int il_child2( void );
void il_catch_USR2( int );
void il_catch_USR1( int );
int kp_test_open(const char *name);
int kp_test_close(int fd);
int kp_test_openwr(const char *name);

int il_child( void ){
   int fdk, k;
   mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
   char *filename = (char*)getpid();
   char buf[BUFFLEN];
   //sleep( 1 );
   while( 1 )
      if ( received_sig == 1 ){
          printf( "Grandchild1: Received signal from grandparent!\n" );
          fdk = creat(filename, mode);
          k = kp_test_openwr(filename);
          read( fd[0], buf, sizeof( fd[0] ) );
          if( write( k, buf, sizeof( buf ) ) != sizeof( buf ) ){
      fprintf( stderr, "Klaida rasant" );
      exit( 2 );
   }
          //sleep( 1 );
      }
}

int il_child2( void ){
   int fdk, k;
   mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
   char *filename = (char*)getpid();
   char buf[BUFFLEN];
   //sleep( 1 );
   while( 1 )
      if ( received_sig == 2 ){
          printf( "Grandchild2: Received signal from grandparent!\n" );
          fdk = creat(filename, mode);
          k = kp_test_openwr(filename);
          read( fd[0], buf, sizeof( fd[0] ) );
          if( write( k, buf, sizeof( buf ) ) != sizeof( buf ) ){
      fprintf( stderr, "Klaida rasant" );
      exit( 2 );
   }

          //sleep( 1 );
      }
}

int kp_test_openwr(const char *name){
   int dskr;
   dskr = open( name, O_RDWR );
   if( dskr == -1 ){
      perror( name );
      exit(1);
   }
   printf( "dskr = %d\n", dskr );
   return dskr;
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

void il_catch_USR1( int snum ) {
   received_sig = 1;
}

void il_catch_USR2( int snum ) {
   received_sig = 2;
}


int main( int argc, char * argv[] ){
   pid_t child, parent, rv, ra, pidai[1000];
   int st, i, M, d, bytes_read;
   char buffer[BUFFLEN];
   M = sizeof( argv[1]) - atoi(argv[2]);
   parent = getpid();
   signal(SIGUSR1, il_catch_USR1);
   signal(SIGUSR2, il_catch_USR2);
   if( argc != 4 ){
      printf( "Naudojimas:\n %s failas skaicius baitai\n", argv[0] );
      return 0;
   }
   d = kp_test_open( argv[1] );
   printf( "(C) 2018 Vilius Kerutis, %s\n", __FILE__ );
   for(i = 0; i < 2; i++){
   if( getpid() == parent ){
      rv = fork();
      if(rv == 0){
      ra = fork();
      sleep(1);
        if(ra == -1){
         printf("Nepavyko sukurti anuko.\n");
        }
        else{
     pidai[i] = getpid();
     }
    }else if(rv == -1){
     printf("Nepavyko sukurti vaiko\n");
     }
  }
}
   wait( &st );
   printf( "Proceso PID = %ld  Proceso PPID = %ld\n", getpid(), getppid() );
   if(getpid() == parent){
     lseek( d, M, SEEK_SET );
     if( pipe( fd ) == -1 ){
      fprintf( stderr, "Nepavyko sukurti programinio kanalo !\n" );
      exit( 1 );
   }
     bytes_read = read( d, buffer, atoi(argv[3]) );
     if( bytes_read != -1 ){
   //printf( "Buvo sekmingai nuskaityti %d baitai\n", bytes_read );
     if( write( fd[1], &buffer, bytes_read / 2 ) != bytes_read / 2 ){
      fprintf( stderr, "Klaida rasant" );
      exit( 2 );
   }else{
    if( write( fd2[1], &buffer, bytes_read / 2 ) != bytes_read / 2 ){
      fprintf( stderr, "Klaida rasant" );
      exit( 2 );
   }
    }
    }
   kill(pidai[0], SIGUSR1);
   kill(pidai[1], SIGUSR2);
}
   return 0;
}
