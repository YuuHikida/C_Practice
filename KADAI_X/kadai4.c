#include <stdio.h>
//-------------------------------
//構造体構造
//-------------------------------
typedef struct 
{
    int id;
    char name[32];
}Student;

//------------------------------
///関数プロトタイプ
//-------------------------------

//------------------------------
///関数
//-------------------------------
int
main( void )
{
    int i ;

    Student studentArray[] = 
    {
        { 1,"HIKIDA" },
        { 2,"TAKANO" },
        { 3,"NEMOTO" }
    };

    int num = sizeof(studentArray)/sizeof(studentArray[0]);
    //表示
    for( i = 0; i < num; i++)
    {
        printf( "IDは=(%d),名前は=(%s)\n", studentArray[i].id, studentArray[i].name );
    }
}
