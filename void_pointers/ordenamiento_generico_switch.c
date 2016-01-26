/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ordenamiento_generico_switch.c
* Creation Date : 21-01-2016
* Last Modified : Thu 21 Jan 2016 03:29:05 PM CST
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

/*Hacer un programa que ordeneme ints, floats, con quicksort, mergesort,  selection e insertion, dando la opción al usuario de elegir si quiere ordenar ints o floats, ascendente o descendente y con que algoritmo los quiere ordenar con void pointers... */

typedef int (*t_compare)(void *, void *);
typedef void (*t_swap)(void * , void * );
typedef void (*t_sort)(void *, size_t, size_t, t_compare, t_swap );

/* Implementación de funciones genéricas */
void sort(t_sort algorithm, void * vector, size_t count, size_t size, t_compare compare, t_swap swap )
{
    (*algorithm)(vector, count, size, compare, swap);
}

void insertionSort(void * vector, size_t count, size_t size, t_compare compare, t_swap swap )
{
    void * j;
    void * start = vector;
    void * aux = start;
    void * last = start + (count * size);
    
    for (; aux < last ; aux+=size)
    {
        j = aux - size;
        while (j >= start && (*compare)(j, j+size))
        {
            (*swap)(j+size, j);
            j-=size;
        }
    }
}

void selectionSort(void * vector, size_t count, size_t size, t_compare compare, t_swap swap )
{
    void * minimo;   
    void * j;
    void * start = vector;
    void * aux = start;
    void * last = start + (count * size);
    void * prelast = last - size;
    
    for(; aux < prelast; aux+=size)
    {
        minimo = aux;
        for(j = aux + size; j < last; j+=size)
            if ( (*compare)(minimo, j) )
                minimo = j;

        (*swap)(minimo, aux);
    }
}

/* Implementación de funciones callback para enteros */
int ascInt(void * pa, void * pb)
{
    int * a = (int *)pa;
    int * b = (int *)pb;
    return (*a > *b);
}

int descInt(void * pa, void * pb)
{
    int * a = (int *)pa;
    int * b = (int *)pb;
    return (*a < *b);
}

void swapInt(void * pa , void * pb )
{
    int temp;
    int * a = (int *)pa;
    int * b = (int *)pb;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Implementación de funciones callback para flotantes */
int ascFloat(void * pa, void * pb)
{
    float * a = (float *)pa;
    float * b = (float *)pb;
    return (*a > *b);
}

int descFloat(void * pa, void * pb)
{
    float * a = (float *)pa;
    float * b = (float *)pb;
    return (*a < *b);
}

void swapFloat(void * pa , void * pb )
{
    float temp;
    float * a = (float *)pa;
    float * b = (float *)pb;
    
    temp = *a;
    *a = *b;
    *b = temp;
    
}

/* Implementación de funciones de impresión */
void imprimeInt(int * vector, int count)
{
    int * aux = vector;
    int * last = vector + count;
    
    for (; aux < last; ++aux) 
        printf(" %4d ", *aux);
    
    printf("\n");
}

void imprimeFloat(float * vector, int count)
{
    float * aux = vector;
    float * last = vector + count;
    
    for (; aux < last; ++aux) 
        printf(" %7.2f ", *aux);
    
    printf("\n");
}

int main(int argc, const char * argv[])
{   
       
    return 0;
}

