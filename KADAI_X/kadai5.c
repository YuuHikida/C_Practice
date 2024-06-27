#include <stdio.h>

int
main ( void )
{
    char *prt = ( char* )0x100;
    char *prt2 = prt --;
    printf("%c",*prt2);
}

