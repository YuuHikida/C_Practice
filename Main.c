#include <stdio.h>
#include <string.h>
/*--------------------------
  構造体宣言
-----------------------------*/
typedef struct {
  char name[32] ;
  short int gender; //0=男 1=女
  short int age;
  char homeTown[80];
} people_data;

void putData( people_data *p );

int main()
{          
     people_data st_people;
     people_data * p_st_people;
     p_st_people = &st_people;
     //サブルーチンへ値を入力
     putData( p_st_people );

     //出力
     printf( "名前は:%c¥n性別は:%s¥n年齢は:%d¥n出身地は%s¥n",
     p_st_people->name,
     (( p_st_people->gender == 0 ) ? "男" : "女"),
     p_st_people->age,
     p_st_people->homeTown );

     return 0;
}

void putData( people_data *p )
{
  strcpy( p->name,"HIKIDA YUU ");
  p->gender   = 0;
  p->age      = 26;
  strcpy( p->homeTown,"sizuoka" );
}
