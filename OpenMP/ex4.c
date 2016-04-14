/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ex4.c
* Creation Date : 11-04-2016
* Last Modified : Thu 14 Apr 2016 10:47:39 AM CDT
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
#include <time.h>
#include <math.h>

#define N 10000

/* Make a matrix of size 10,000 x 10,000 with numbers between 100 and 10,000, Create a matrix that indicate if the numbers are prime circular
 * Execute times */

unsigned short rotate(unsigned short t, int n)
{
  unsigned short r = 0;
  unsigned short tmp;

  if(t == 10000)
    r = 1;
  else
  {
    tmp = t/pow(10,n);
    r = tmp;
    tmp *= pow(10,n);
    r = r+((t-tmp)*10);
  }

  return r;
}

char prime(unsigned short t)
{
  int i = 4;

  if(t <= 1)
    return 0;
  else if(t <=3)
    return 1;
  else
  {
    for(i; i < sqrt((double)t); ++i)
      if(t%i == 0)
        return 0;
    
    return 1;
  }
}

char circular(unsigned short t)
{
  unsigned short tmp = t;
  char b = 1;
  int n, i = 0;

  if(t == 10000)
    n = 4;
  else if(t >= 1000)
    n = 3;
  else if(t >= 100)
    n = 2;
  else
    printf("ERROR %hu\n", t);

  for(i; i < n+1; ++i)
  {
    b = b&prime(t);
    t = rotate(t, n);
  }

  return b;
}

int main(int argc, char *argv[])
{
  clock_t start;
  unsigned short **matrix;
  char **result;
  int i, j;
  
  srand((unsigned)time(NULL));
  matrix = (unsigned short**)malloc(N*sizeof(unsigned short*));
  result = (char**)malloc(N*sizeof(char*));

  for(i = 0; i < N; ++i)
  {
    matrix[i] = (unsigned short*)malloc(N*sizeof(unsigned short));
    result[i] = (char*)malloc(N);
    for(j = 0; j < N; ++j)
    {
      matrix[i][j] = (unsigned short)(rand()%9901)+100;
      result[i][j] = 0;
    }
  }

  start = clock();

  #pragma omp parallel shared(matrix, result) private(i,j)
  {
    #pragma omp for schedule(auto) nowait
      for(i = 0; i < N; ++i)
        for(j = 0; j < N; ++j)
          result[i][j] = circular(matrix[i][j]);
       
  }
 
  printf("The time of the parallel program it's: %f\n", (start)/CLOCKS_PER_SEC);

  for(i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      result[i][j] = 0;

  start = clock();

  for(i = 0; i < N; ++i)
    for(j = 0; j < N; ++j)
      result[i][j] = circular(matrix[i][j]);

  printf("The time of the secuential program it's: %f\n", (start)/CLOCKS_PER_SEC);
  
  return 0;
}

