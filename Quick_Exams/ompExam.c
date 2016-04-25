/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ompExam.c
* Creation Date : 15-04-2016
* Last Modified : Mon 25 Apr 2016 12:52:26 AM CDT
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
#include <omp.h>

int main(int argc, char *argv[])
{
  int *array = (int*)malloc(6*sizeof(int));
  int i = 0, j = 0, k = 0;

  #pragma omp parallel shared(array, j, k) private(i) 
  {
    #pragma omp sections nowait
    {
      #pragma omp section
      {
        #pragma omp critical
        {
          #pragma omp num_thread(4) parallel
          {
            printf("operation %d\n", omp_get_thread_num());
            #pragma omp atomic
              ++j;
          }
        }
      }
      #pragma omp section
      {
        #pragma omp parallel for schedule(auto)
          for(i = 0; i < 6; ++i)
            array[i] = i;
        
        for(i = 0; i < 6; ++i)
          k += array[i];
      }
    }
  }

  printf("Res = %d\n", k);
  free(array);

  return 0;
}

