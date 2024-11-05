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
        line[strcspn(line, "\n")] = '\0';
        printf("text=(%s)\n",line);
    }
    fclose(fp);

    return 0;
}