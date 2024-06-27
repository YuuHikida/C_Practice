#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*ご指摘MEMO
引数が空の時はvoid
'int' mainなのでreturn 
エラーなら-1をreturn

関数の'()'を外すとポインタになる
*/
void sayOHAYO( void );
void sayKONNITIWA( void );
void sayOYASUMI( void );

/*MEMO
-関数ポインタの宣言-
戻り値の型 (*ポインタ変数名)(引数情報);

-関数ポインタ使い方-
ポインタ変数名 = 関数名

-関数ポインタと配列-
戻り値の型 (*ポインタ変数名[配列の要素数])(引数情報);

*/
//関数定義
void sayOHAYO( void )
{
    printf("OHAYO!\n");
}

void sayKONNITIWA( void )
{
    printf("KONNITIWA!\n");
}

void sayOYASUMI( void )
{
    printf("OYASUMI\n");
}

int 
main( int ac, char *av[])
{
    int arg;
    //バリデーションチェック
    if( ac != 2 )
    {
        printf("引数の数を指定するか、一つにしてください\n");
        return -1;
    }
    
    if( !isdigit( *av[1] ) )
    {
        printf("数値を入力してください\n");
        return -1;
    }
    arg = atoi(av[1]);
    // if( arg == 0 )
    // {
    //     printf("数値を入力してください\n");
    //     return -1;
    // }
    if( arg < 0 || 2 < arg )
    {
        printf("0~2までの値を入力してください\n");
        return -1;
    }
    //関数ポインタ宣言
    void(*p_func[3])() =  { sayOHAYO, sayKONNITIWA, sayOYASUMI };
    // p_func[0] = sayOHAYO;
    // p_func[1] = sayKONNITIWA;
    // p_func[2] = sayOYASUMI; 

    //表示
    //printf( "入力された値の(%d)の実行結果は以下です\n(%s)", arg, p_func[arg] );
    //表示-解-
    p_func[arg]();
    return 0;
}

