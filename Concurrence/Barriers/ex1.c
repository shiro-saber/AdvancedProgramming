/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ex1.c
* Creation Date : 28-03-2016
*   Last Modified : Mon 28 Mar 2016 11:13:20 AM CST
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
#include <pthread.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define N 5

static pthread_barrier_t barrier;

void *actions(void *action)
{
  int i = 0;
  int *id = (int*)action;

  for(i; i < 10; ++i)
  {
    printf("thread %i executing action\n", *id);
    sleep(rand()%5);
  }

  pthread_barrier_wait(&barrier);
  printf("Splash!!\nTERMINE!\n");
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  int i = 0;
  int *ids = (int*)malloc(sizeof(int)*N);

  srand(time(NULL));
  pthread_t threads[N];
  pthread_barrier_init(&barrier, NULL, 5);

  for(i; i < N; ++i)
    *(ids+i) = i;

  for(i = 0; i < N; ++i)
    pthread_create(&threads[i], NULL, actions, (void*)(ids+i));

  for(i = 0; i < N; ++i)
    pthread_join(&threads[i], NULL);

  free(ids);
  
  return 0;
}
