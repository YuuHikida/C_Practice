#include<stdio.h>
#include<string.h>

char x[5];
char v[5];
char y[12] = "abcdeefgeijk";

int main()
{
    strncpy(x,y,sizeof(x));
    printf("{%s}",x);
    (void)snprintf(x,sizeof(x),"this is(%s)",y);
    // printf("{%s}",x);
}

