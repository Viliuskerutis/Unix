/* Vilius Kerutis IFF-6/7 vilker3 */
/* Failas: vilker3_misc01.c */
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int change_directory(int fd) {
    fchdir(fd);
}
int main() {
    int dir = open("/var/lib", O_RDONLY);
   // chdir("/tmp");
    change_directory(dir);
}
