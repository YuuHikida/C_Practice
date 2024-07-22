#include<stdio.h>
#include<string.h>

int main()
{
    char a[3];
    char b[]="HELLO";
    int x = 2;

    memset(a,0x00,sizeof(a));
    memcpy(a,b,3);
    
    // '\0' を付加して文字列の終端を示す必要がある
    a[2] = '\0';
    
    printf("%s\n", a);
    return 0;
}
