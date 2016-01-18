/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ordenamiento.c
* Creation Date : 18-01-2016
* Last Modified : Mon 18 Jan 2016 10:58:31 AM CST
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

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 10

int asc(int a, int b)
{
    return a < b;
}

int desc(int a, int b)
{
    return b < a;
}
void ordenamela(int *numeros, int criterio(int, int))
{
  int i, j ,temp;

  for(i = 0;  i < N; ++i)
  {
    for(j = N-1; j > i; --j)
    {
      if(criterio(numeros[j], numeros[j-1]))
      {
        temp = numeros[j-1];
        numeros[j-1] = numeros[j];
        numeros[j] = temp;
      }
    }
  }
}

int main()
{
  int *valores = (int*)malloc(N*sizeof(int));
  int * p = valores;
  
  srand((int) time(NULL));
    
  for (; p < (valores + N); ++p) 
  {
    *p = rand() % 100;
    printf("%4d", *p);
  }
    
  ordenamela(valores, desc);
       
  printf("\n--- Ordenados ---\n");
    
  for (p = valores; p < (valores + N); ++p) 
    printf("%4d", *p);

  printf("\n");
    
  free(valores);
  return 0;
}
