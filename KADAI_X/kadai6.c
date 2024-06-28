# include <stdio.h>
#include <math.h>
//浮動小数点表示

int
main( void )
{
    float  i =  3.123456789f;    //3.12345672
    double j =  3.123456789;    //3.123456789
    printf( "f:(%f)\n",i );     //3.123457
    printf( "g:(%g)\n",j );     //3.12346

    float intPart_float = floor( i );   //3
    double intPart_double = floor( j ); //3
    //円周率
    int int_x = 3.123456789;

    //もしくは以下

    printf( "intPart_float:(%f)\n", intPart_float );
    printf( "intPart_double:(%g)\n", intPart_double );//3

    float  fracPart_float  = i - intPart_float;
    double fracPart_double = j - intPart_double;
    float x = fracPart_double - int_x ;
    
    printf( "floatの小数点表示:(%f)\n", fracPart_float ); //0.123456717
    printf( "doubleの小数点表示:(%g)\n", fracPart_float ); //0.12345678900000001
    
}