/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ex2.c
* Creation Date : 11-04-2016
* Last Modified : Mon 11 Apr 2016 10:48:25 AM CDT
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
  int i, n = 100, chunk = 8, tid;
  float a[n], b[n], c[n];

  for(i = 0; i < n; ++i)
    a[i] = b[i] = i*22.0;

  #pragma omp parallel shared(a, b, c, chunk) private(i, tid)
  {
    #pragma omp for schedule(static, chunk)
    for(i = 0; i < n; ++i)
    {
      tid = omp_get_thread_num();
      c[i] = a[i] + b[i];
      printf("tid %d \t i %d\n", tid, i);
    }
  }
  
  //printf("\n");
  return 0;
}

