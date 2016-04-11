/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ex3.c
* Creation Date : 11-04-2016
* Last Modified : Mon 11 Apr 2016 11:00:10 AM CDT
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
  int i, n = 100, chunk = 3;
  float a[n], b[n], c[n], d[i];

  for(i = 0; i < n; ++i)
    a[i] = b[i] = i*22.0;

  #pragma omp parallel shared(a, b, c, chunk) private(i)
  {
    #pragma omp sections nowait
    {
      #pragma omp section
      {
        for(i = 0; i < n; ++i)
          c[i] = a[i] + b[i];
      }
      
      #pragma omp section
      {
        for(i = 0; i < n; ++i)
          d[i] = a[i] * b[i];
      }
    }
  }

  return 0;
}

