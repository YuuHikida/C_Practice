#include <stdio.h>

void test_A()
{
    char x[100];
    char test[50];
    char y[] = "こんにちは、私の名前はジョンスミスです。１０サイズ以上の文字列を作成します";
    char o[10] = "xyz";
    char element[] = "abc";
    (void)snprintf(x, sizeof(x), "%.*s/%.*s",10000, o, 50 , element);
    
    printf("ans=%s\n",x);
}
void test_B()
{
    char x[10];
    char test[50];
    char y[] = "こんにちは、私の名前はジョンスミスです。１０サイズ以上の文字列を作成します";
    char o[10] = "xyz";
    char element[] = "abcefghijkmln";
    (void)snprintf(x, sizeof(x), "%.*s/%.*s",1000, o, 50 , element);
    
    printf("ans=%s\n",x);
}
int main()
{
    // test_A();
    test_B();

    // // (void)snprintf(x, sizeof(x), "%.*s", (int)sizeof(x), y);
    // (void)snprintf(x, sizeof(x), "%.*s", (int)sizeof(x),
    //      "こんにちは、私の名前はジョンスミスです。１０サイズ以上の文字列を作成します");
    
    
    /*
    //出力結果:Korega=こんに%
    (void)snprintf(x,sizeof(x),y);
    printf("korega=%s",x);
    */
}