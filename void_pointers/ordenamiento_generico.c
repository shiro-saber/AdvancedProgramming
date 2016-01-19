/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ordenamiento_generico.c
* Creation Date : 18-01-2016
* Last Modified : Tue 19 Jan 2016 11:46:22 AM CST
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
typedef int(*ordenamiento)(void*, void*);
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
int float_asc(void* a, void* b)
{
  float *na = (float *)a;
  float *nb = (float *)b;
  return (*na > *nb);
}

int float_desc(void* a, void* b)
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
int char_asc(void *a, void *b)
{
  char *na = (char *)a;
  char *nb = (char *)b;
  return (*na > *nb);
}

int char_desc(void *a, void *b)
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
void bubble(void *dato, size_t cont, size_t size, ordenamiento o, criterio c)
{

}

void insertion(void *dato, size_t cont, size_t size, ordenamiento o, criterio c)
{ 
  void *j;
  void *start = dato;
  void *aux = start;
  void *last = start + (cont * size);
    
  for (; aux < last ; aux+=size)
  {
    j = aux - size;
    while (j >= start && (*o)(j, j+size))
    {
      (*c)(j+size, j);
      j-=size;
    }
  }
}

void selection(void *dato, size_t cont, size_t size, ordenamiento o, criterio c)
{
  void *minimo;
  void *j;
  void *start = dato;
  void *aux = start;
  void *last = start + (cont * size);
  void *prelast = last - size;
    
  for(; aux < prelast; aux+=size)
  {
    minimo = aux;
    for(j = aux + size; j < last; j+=size)
    {
      if ((o)(minimo, j))
        minimo = j;
    }
    (c)(minimo, aux);
  }
}

int main()
{
   /*prueba integros*/ 
  int *datos, *aux, *ultimo;
  
  datos = (int*)malloc(N * sizeof(int));
  ultimo = datos + N;

  for (aux = datos; aux < ultimo; ++aux) 
    *aux = rand() % 50;

  printf("------Enteros------\n");
  
  for (aux = datos; aux < ultimo; ++aux)
    printf(" %4d ", *aux);
  
  printf("\n");

  selection(datos, N, sizeof(*datos), int_asc, ordenamela_int);
  free(datos);
  
  /*prueba floats*/
  float *datosf, *auxf, *ultimof;
  
  datosf = (float*)malloc(N * sizeof(float));
  ultimof = datosf + N;

  for (auxf = datosf; auxf < ultimof; ++auxf) 
    *auxf = rand() % 50;

  printf("------Floats------\n");
  
  for (auxf = datosf; auxf < ultimof; ++auxf)
    printf(" %4.2f ", *auxf);
  
  printf("\n");

  insertion(datosf, N, sizeof(*datosf), &float_desc, &ordenamela_float);
  free(datosf);


  /*prueba chars*/
  char *datosc, *auxc, *ultimoc;
  
  datosc = (char*)malloc(N * sizeof(char));
  ultimoc = datosc + N;

  for (auxc = datosc; auxc < ultimoc; ++auxc) 
    *auxc = (rand() % 26) + 97;

  printf("------Chars------\n");
  
  for (auxc = datosc; auxc < ultimoc; ++auxc)
    printf(" %s ", *auxc);
  
  printf("\n");

  insertion(datosc, N, sizeof(*datosc), char_asc, ordenamela_char);
  free(datosc);

  return 0;
}

