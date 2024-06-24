#include <stdio.h>
#include <stdlib.h>

void sayOHAYO();
void sayKONNITIWA();
void sayOYASUMI();

/*MEMO
-関数ポインタの宣言-
戻り値の型 (*ポインタ変数名)(引数情報);

-関数ポインタ使い方-
ポインタ変数名 = 関数名

-関数ポインタと配列-
戻り値の型 (*ポインタ変数名[配列の要素数])(引数情報);

*/
//関数定義
void sayOHAYO() {
    printf("OHAYO!\n");
}

void sayKONNITIWA() {
    printf("KONNITIWA!\n");
}

void sayOYASUMI() {
    printf("OYASUMI\n");
}

int main( int ac, char *av[])
{
    int arg;
    //バリデーションチェック
    if( ac != 2 )
    {
        printf("引数の数を指定するか、一つにしてください\n");
        return 0;
    }

    arg = atoi(av[1]);
    if( arg < 0 || 2 < arg )
    {
        printf("0~2までの値を入力してください\n");
        return 0;
    }
    //関数ポインタ宣言
    void(*p_func[3])() =  { sayOHAYO, sayKONNITIWA, sayOYASUMI };
    // p_func[0] = sayOHAYO;
    // p_func[1] = sayKONNITIWA;
    // p_func[2] = sayOYASUMI; 

    //表示
    //printf( "入力された値の(%d)の実行結果は以下です\n(%s)", arg, p_func[arg] );

    p_func[arg]();
}

