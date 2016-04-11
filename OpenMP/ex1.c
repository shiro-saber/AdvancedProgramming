/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ex1.c
* Creation Date : 11-04-2016
* Last Modified : Mon 11 Apr 2016 10:34:23 AM CDT
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
  int nthreads, tid;

  #pragma omp parallel private(tid)
  {
    tid = omp_get_thread_num();
    printf("TEST\n");
    if(tid == 0)
    {
      nthreads = omp_get_num_threads();
      printf("NT: %d", nthreads);
    }
  }

  printf("\n");
  return 0;
}

