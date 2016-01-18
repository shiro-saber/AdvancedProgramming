/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ordenamiento_generico.c
* Creation Date : 18-01-2016
* Last Modified : Mon 18 Jan 2016 05:37:21 PM CST
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
#include <time.h>
#define N 20

/*Hacer un programa que ordeneme ints, floats, chars, con bubble,  selection e insertion, con void pointers... */

/*data types*/
typedef void(*ordenamiento)(void*, void*);
typedef void(*criterio)(void*, void*);

/*Ints*/
int int_asc(void* a, void* b)
{
  int *na = (int *)a;
  int *nb = (int *)b;
  return (*na > *nb);
}

int int_desc(void* a, void* b)
{
  int *na = (int *)a;
  int *nb = (int *)b;
  return (*na < *nb);
}

void ordenamela_int(void *a, void *b)
{
  int temp;
  int *na = (int *)a;
  int *nb = (int *)b;
    
  temp = *na;
  *na = *nb;
  *nb = temp;
}

/*Floats*/
float float_asc(void* a, void* b)
{
  float *na = (float *)a;
  float *nb = (float *)b;
  return (*na > *nb);
}

float float_desc(void* a, void* b)
{
  float *na = (float *)a;
  float *nb = (float *)b;
  return (*na < *nb);
}

void ordenamela_float(void *a, void *b)
{
  float temp;
  float *na = (float *)a;
  float *nb = (float *)b;
    
  temp = *na;
  *na = *nb;
  *nb = temp;
}

/*Chars*/
char char_asc(void *a, void *b)
{
  char *na = (char *)a;
  char *nb = (char *)b;
  return (*na > *nb);
}

char char_desc(void *a, void *b)
{
  char *na = (char *)a;
  char *nb = (char *)b;
  return (*na < *nb);
}

void ordenamela_char(void *a, void *b)
{
  char temp;
  char *na = (char *)a;
  char *nb = (char *)b;

  temp = *na;
  *na = *nb;
  *nb = temp;
}

/*algoritmos*/
void bubble(void *dato, ordenamiento o, criterio c)
{

}

void insertion(void *dato, ordenamiento o, criterio c)
{ 

}

void selection(void *dato, ordenamiento o, criterio c)
{

}

int main()
{
    

  return 0;
}

