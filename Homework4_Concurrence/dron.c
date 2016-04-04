/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : dron.c
* Creation Date : 03-04-2016
* Last Modified : Sun 03 Apr 2016 06:21:49 PM CDT
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
#include <sys/types.h>
#include <pthread.h>
#include <time.h>

#define Floors 5
#define Dron 5

pthread_mutex_t *lvls;
pthread_cond_t *cond_lvls;

int dronWeight[Dron];
int floorWeight[Floors];
int totalWeight[Floors];

void *dron(void *arg)
{
  printf("Going shopping, dron #%d\n", (int)arg);
  int cont = 0;
  
  while(cont < Floors)
  {
    pthread_mutex_lock(lvls+cont);
    if(dronWeight[(int)arg]+totalWeight[cont] > floorWeight[cont])
    {
      printf("Dron #%d need to wait until weight low down\n", (int)arg);
      pthread_cond_wait(cond_lvls+cont, lvls+cont);
      pthread_mutex_unlock(lvls+cont);
    }
    else
    {
      totalWeight[cont] += dronWeight[(int)arg];
      pthread_mutex_unlock(lvls+cont);
      printf("Dron #%d shopping on section %d wight %d of %d\n", (int)arg, cont, totalWeight[cont], floorWeight[cont]);
      int buy = rand()%3;
      sleep(buy);
      printf("Dron #%d finish shopping on section %d\n", (int)arg, cont);
      pthread_mutex_lock(lvls+cont);
      totalWeight[cont] -= dronWeight[(int)arg];
      pthread_cond_broadcast(cond_lvls+cont);
      pthread_mutex_unlock(lvls+cont);
      cont++;
    }
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t *drons = (pthread_t*)malloc(sizeof(pthread_t)*Dron*2);
  lvls = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)*Floors);
  cond_lvls = (pthread_cond_t*)malloc(sizeof(pthread_cond_t)*Floors);

  srand(time(NULL));
  int i = 0;
  
  for(i; i < Floors; ++i)
  {
    floorWeight[i] = rand()% 10+5;
    totalWeight[i] = 0;
    printf("The section %d, had a weight of %d\n", i, floorWeight[i
    ]);
  }

  for(i = 0; i < Floors; ++i)
  {
    pthread_mutex_init(lvls+i, NULL);
    pthread_cond_init(cond_lvls+i, NULL);
  }

  for(i = 0; i < Dron; ++i)
  {
    dronWeight[i] = rand() % 4+1;
    printf("The dron #%d had a weight of %d\n", i, dronWeight[i]);
    pthread_create(drons+i, NULL, dron, (i));
  }

  for(i = 0; i < Dron; ++i)
    pthread_join(*(drons), NULL);

  free(lvls);
  free(cond_lvls);
  free(drons);

  return 0;
}

