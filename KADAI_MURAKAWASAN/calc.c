#include <stdio.h>
#include <stdlib.h>

int calc(int a, int b);

int
calc(int a, int b)
{
    while( b != 0 )
    {
        int tmp = b;
        b = a % b;
        a = tmp ;
    }
    return a;
}

int
main( int ac, char *av[] )
{
    //バリデーションチェック
    if( ac >= 4)
    {
        printf("引数の数値を3つ以上いれないでください\n");
        return 0;
    }
    
    int a , b, tmp, r;
    //int変換
    a = atoi(av[1]);
    b = atoi(av[2]);

    //入れ替え
    if(a < b)
    {
        tmp = a;
        a   = b;
        b   = tmp;
    }
    //ユークリッド互除法
    // r = a % b;
    // while( r != 0 )
    // {
    //     a = b;
    //     b = r;
    //     r = a % b;
    // }
    int result = calc( a,b );
    //表示
    if( result == 1 )
    {
        printf("(%d)と(%d)は素です\n", a, b );
    }
    else
    {
        printf("(%d)と(%d)は素ではないです\n", a, b );
    }
    
}
