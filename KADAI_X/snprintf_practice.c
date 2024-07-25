#include <stdio.h>

int main()
{
    char x[10];
    char y[] = "こんにちは、私の名前はジョンスミスです。１０サイズ以上の文字列を作成します";
    
    // (void)snprintf(x, sizeof(x), "%.*s", (int)sizeof(x), y);
    (void)snprintf(x, sizeof(x), "%.*s", (int)sizeof(x),
         "こんにちは、私の名前はジョンスミスです。１０サイズ以上の文字列を作成します");
    
    printf("kotae=%s",x);
    /*
    //出力結果:Korega=こんに%
    (void)snprintf(x,sizeof(x),y);
    printf("korega=%s",x);
    */
}