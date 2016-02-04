/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise2.c
* Creation Date : 04-02-2016
* Last Modified : Thu 04 Feb 2016 11:17:12 AM CST
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
#include <unistd.h>
#include <time.h>
#include <wait.h>

#define N 10

int main(int argc, char *argv[])
{
  int *numeros;
  int sum, pid, status, p;
  numeros = (int*)malloc(sizeof(int)*N);
  int i = 0;
  int j = 0;
  int sum_proc = 0;
  int sum_proc2 = 0;
  srand((int)time(NULL));

  for(i = 0; i < N; ++i)
  {
    *(numeros + i) = rand() % 50;
    printf("Numero: %d\n", *(numeros + i));
  }

  pid = fork();

  if(pid == -1)
    printf("Error creating child\n");
  else if(pid == 0)
  {
    for(j = 0; j < N/2; ++j)
    {
      sum_proc += *(numeros + j);
      printf("Arreglo[%d] = %d\n", j, *(numeros+j));
      printf("SUMA= %d\n", sum_proc);
    }
    free(numeros);
    exit(sum_proc);
  }
  else
  {
    p = fork();
    if(p == -1)
      printf("Error creating child\n");
    else if(p == 0)
    {
      for(j = (N/2)+1; j > N; j++)
      {
        sum_proc2 += *(numeros + j);
        printf("Arreglo[%d] = %d\n", j, *(numeros+j));
        printf("SUMA= %d\n", sum_proc2);
      }

      free(numeros);
      exit(sum_proc);
    }
    else
    {
      if((waitpid(pid, &status, 0) != -1))
        if(WIFEXITED(status))
          sum += WEXITSTATUS(status); 

      if((waitpid(p, &status, 0)) != -1)
        if(WIFEXITED(status))
          sum += WEXITSTATUS(status);
    }
  }
 

  printf("La suma de la integral es: %d\n", sum);
 
  free(numeros);
  return 0;
}

