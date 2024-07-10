#include <string.h> 
#include <stdio.h>
#include <stdlib.h>


int
main ( void )
{
    // char *prt = ( char* )0x100;
    // char *prt2 = prt --;
    // printf("%c",*prt2);

    int array[10];
    size_t xx_size = sizeof(array)/sizeof(array[0]);
    
    // char *x = (char *)malloc(xx_size);
    char *x;
    memset(x,0x00,xx_size);
    printf("thisis=%p",x);
    return 0;
}

