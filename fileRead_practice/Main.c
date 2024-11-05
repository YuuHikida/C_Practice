# include <stdio.h>
#include <string.h>

int main(void)
{
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
        line[strcspn(line, "\n")] = '\0';
        printf("text=(%s)\n",line);
    }
    fclose(fp);

    return 0;
}