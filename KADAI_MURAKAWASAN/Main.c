#include <stdio.h>
 
int
main( int ac, char *av[] )
{
  int i;
 //input引数  a.exe "HELLO"
 //NULL文字に到達するまでfor文を回す

/*  
av[0] = a.exe
av[1] = "HELLO"
「*」は間接演算子で保持する内容を参照可能
*/
  for( i = 0; *( *( av + 1 ) + i ) != 0;i++ )
    {
      printf( "%c\n", *( *( av + 1 ) + i ) );
    }
  // printf("this is =[%s]\n",  *( av + 1 ) = HELLO;
 
  return 0;
}
/*まとめ
*av[] = HELP
av + 1              = 配列の+1番目要素
*( av + 1 )         = av[1]へのポインタ
*( av + 1 ) +i      = av[1][i] =av[1]のi文字目のポインタ
*( *( av + 1 ) +i ) = av[1]のi番目の文字そのものを指す
*/