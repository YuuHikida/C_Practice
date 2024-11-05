#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 16進の文字列 ("F0" など) をバイト値に変換する関数
unsigned char hex_to_byte(const char *hex)
{
    unsigned char byte = 0;
    for (int i = 0; i < 2; i++)
    {
        byte <<= 4;  // 4ビット左シフト
        if (hex[i] >= '0' && hex[i] <= '9')
            byte |= (hex[i] - '0');
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            byte |= (hex[i] - 'A' + 10);
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            byte |= (hex[i] - 'a' + 10);
    }
    return byte;
}

int main(void)
{
    FILE *fp = NULL;
    FILE *outputFile = NULL;
    char line[256];

    fp = fopen("../tmp/test.txt", "r");
    if (fp == NULL)
    {
        printf("cant open input file\n");
        return 1;
    }

    outputFile = fopen("output.bin", "wb");
    if (outputFile == NULL)
    {
        printf("cant open output file\n");
        fclose(fp);
        return 1;
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // 改行を削除
        line[strcspn(line, "\n")] = '\0';

        // 条件に従って行をスキップ
        if (strstr(line, "[") != NULL || strstr(line, "]") != NULL || strstr(line, ":") == NULL)
        {
            printf("ittinashi\n");
            continue;  // 条件に一致する場合、この行をスキップして次の行へ
        }

        // ':' の位置を取得して右側を抽出
        char *colon_pos = strstr(line, ":");
        if (colon_pos != NULL)
        {
            char *right_side = colon_pos + 1;

            // 空白を取り除く処理
            char cleaned[256];
            int j = 0;
            for (int i = 0; right_side[i] != '\0'; i++)
            {
                if (!isspace((unsigned char)right_side[i]))
                {
                    cleaned[j++] = right_side[i];
                }
            }
            cleaned[j] = '\0';  // 終端文字を追加

            // 2文字ごとに16進表現をバイトに変換して出力
            for (int i = 0; i < strlen(cleaned); i += 2)
            {
                unsigned char byte = hex_to_byte(&cleaned[i]);
                fwrite(&byte, sizeof(byte), 1, outputFile);
            }
        }
    }

    fclose(fp);
    fclose(outputFile);

    printf("バイナリファイルにEBCDIC形式で出力が完了しました。\n");

    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    char outputMoji[1024];
    memset(outputMoji,'\0',sizeof(outputMoji));
    FILE *fp = NULL;
    char line[256];

    fp = fopen("../tmp/test.txt","r");
    if(fp == NULL )
    {
        printf("cant open\n");
        return 1;
    }

    while(fgets(line,sizeof(line),fp) != NULL)
    {
        // 条件に従って行をスキップ
        if (strstr(line, "[") != NULL || strstr(line, "]") != NULL || strstr(line, ":") == NULL)
        {
            printf("ittinashi\n");
            continue;  // 条件に一致する場合、この行をスキップして次の行へ
        }

        char *colon_pos = strstr(line, ":");
        if(colon_pos != NULL)
        {
            char *right_side = colon_pos + 1;

            char cleaned[256];
            int j=0;
            for (int i = 0; right_side[i] != '\0'; i++)
            {
                if (!isspace((unsigned char)right_side[i]))
                {
                    cleaned[j++] = right_side[i];
                }
            }
            cleaned[j]='\0';
        
            printf("text=(%s)\n", cleaned);  // 空白を取り除いた結果を表示
            // `outputMoji` に `cleaned` を連結、バッファサイズを確認
            if (strlen(outputMoji) + strlen(cleaned) < sizeof(outputMoji) - 1)
            {
                strcat(outputMoji, cleaned);  // cleaned を outputMoji に連結
            }
            else
            {
                printf("outputMoji のバッファが不足しています。\n");
                break;
            }
        }
        
       // line[strcspn(line, "\n")] = '\0';
        //printf("text=(%s)\n",line);
    }
    outputMoji[1023]='\0';
    printf("last=(%s)\n",outputMoji);
    fclose(fp);

    // バイナリファイルとして出力
    FILE *outputFile = fopen("output.bin", "wb");
    if (outputFile == NULL)
    {
        printf("バイナリファイルを開けませんでした。\n");
        return 1;
    }

    size_t written = fwrite(outputMoji, sizeof(char), strlen(outputMoji), outputFile);
    if (written < strlen(outputMoji))
    {
        printf("bad\n");
    }
    else
    {
        printf("OK\n");
    }

    fclose(outputFile);
    return 0;
}

*/