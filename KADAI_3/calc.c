#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 32
#define MAXNUM  100

void calc(long numArray[], int size);

void calc(long numArray[], int size) {
    if (size == 0) {
        printf("有効な数値が入力されませんでした。\n");
        return;
    }

    long max = numArray[0];
    long min = numArray[0];
    
    for (int i = 1; i < size; i++) {
        if (max < numArray[i]) {
            max = numArray[i];
        }
        if (min > numArray[i]) {
            min = numArray[i];
        }
    }
    printf("最大値は=( %ld ), 最小値は=( %ld )です\n", max, min);
}

int main() {
    int jug = 1;
    int size = 0; // 配列の添字
    char str[MAXLINE];
    // intを受け付ける配列
    long numArray[MAXNUM];

    printf("0~100までの値を入力してください\n");
    printf("-1を入力すると終了します\n");
    while (jug) {
        char *endchar = NULL ;
        
        //NULLならtrueになり実行される
        if (!fgets(str, sizeof(str), stdin)) {
            printf("入力エラーが発生しました\n");
            continue;
        }
        /*
        - MEMO -
        str     ... long型に変換する文字列のポインタ
        endchar ... 変換が完了した位置を示すポインタ
        10      ... 変換する数の基数(何進数に変換するか)
        */
       //long int strtol(const char *nptr, char **endp, int base);
        long num = strtol( str, &endchar, 10 );
        if (str == endchar) {
            printf("入力が完全な数値ではありません。\n");
            continue;
        }
        while (*endchar == ' ' || *endchar == '\t') {
            endchar++;
        }
        if (*endchar != '\0' && *endchar != '\n') {
            printf("変換に失敗しました。入力が完全な数値ではありません。\n");
            continue;
        }
        //ここまでです
        if (num < -1 || 100 < num) {
            printf("入力値は0~100の間でお願いします\n");
            continue;
        }
        if (num == -1) {
            // loop終わり
            jug = 0;
        } else {
            numArray[size++] = num;    
        }
    } 
    calc(numArray, size);
    return 0;
}

/* MEMO
   @fgetsの戻り値は入力された文字列の先頭を示すポインタ(char*型)
   @文字列をlong型に変換するstrtol()
*/
