# include <stdio.h>
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

    return 0;
}