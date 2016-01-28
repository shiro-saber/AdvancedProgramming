/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ejercicio.c
* Creation Date : 28-01-2016
* Last Modified : Thu 28 Jan 2016 10:21:14 AM CST
* Created By : shiro-saber

KNOW LEARN        .==.
C LANGUAGE       ()''()-.
      .---.       ;--; /
    .'_:___". _..'.  __'.
    |__ --==|'-''' \'...;
   [  ]  :[|       |---\
    |__| I=[|     .'    '.
    / / ____|     :       '._
   |-/.____.'      | :       :
  /___\ /___\      '-'._----'
_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>

/*Make a forward iterator, a backward iterator and a bidirectional iterator*/

typedef struct
{
  char *titulo;
  int paginas;
}Libro;

typedef struct
{
  char *name;
  char direction;
  Libro *begin;
  Libro *next;
  Libro *previous;
  Libro *end;
}Iterator;

void define_iterator(Iterator *i, int kuz)
{

}

int main()
{


  return 0;
}

