#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


static int display_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf) {
    printf("%-40s\n", fpath);
    return 0;           /* To tell nftw() to continue */
}


int
main(int argc, char *argv[])
{
    int flag = FTW_PHYS;


    if (nftw( "." , display_info, 20, flag) == -1)
    {
        perror("nftw");
        exit(EXIT_FAILURE);
    }


    exit(EXIT_SUCCESS);
}
