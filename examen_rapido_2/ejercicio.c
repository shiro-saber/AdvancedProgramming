/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ejercicio.c
* Creation Date : 28-01-2016
* Last Modified : Thu 28 Jan 2016 10:44:36 AM CST
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
#include <string.h>

/*Make a forward iterator, a backward iterator and a bidirectional iterator*/

typedef struct
{
  char *titulo;
  int paginas;
  int status;
}Libro;

typedef struct
{
  int position;
  char *direction;
  char *actual_direction;//this is for the bi directional
}Iterator;

void define_iterator(Iterator *i, int kuz)
{
  int option;
  
  printf("Your iterator it's going to be:\n1. Forward\n2. Backward\n 3. Bidirectional\n");
  scanf("%d", &option);

  if(option == 1)
    i->direction = ("forward");
  else if(option == 2)
    i->direction = ("backward");
  else if(option == 3)
    i->direction = ("bidirectional");
  else
    printf("This option doesn't exists\n");
}

Libro *next(Libro *l, Iterator *i, int user_begin)
{
  if(i->direction == "forward")
    i->position = user_begin+1;
  else if(i->direction == "bidirectional")
    i->position = user_begin+1;


  return (l+i->position);
}

Libro *prev(Libro *l, Iterator *i, int user_begin)
{
  if(i->direction == "bidirectional")
    i->position = user_begin-1;
  else if(i->direction == "backward")
    i->position = user_begin-1;


  return (l+i->position);
}

Libro *begin(Libro *l, Iterator *i, int kuz)//donde kuz será el tamaño de los  libros
{
  if (i->direction == ("forward") || i->direction == ("bidirectional"))
    i->position = 0;
  else if(i->direction == ("backward"))
      if((l+kuz-1)->status == 1)
       (i->position) = kuz;
      else
        kuz--;
  
  return (l+i->position);
}

Libro *end(Libro *l, Iterator *i, int kuz)
{
  if (i->direction == ("forward") || i->direction == ("bidirectional"))
    i->position = 0;
  else if(i->direction == ("backward"))
      if((l+kuz-1)->status == 1)
       (i->position) = kuz;
      else
        kuz--;
  
  return (l+i->position);
}

int main()
{
  

  return 0;
}

