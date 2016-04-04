/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : dwarfs.c
* Creation Date : 31-03-2016
* Last Modified : Mon 04 Apr 2016 10:49:26 AM CDT
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
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

typedef struct 
{
  int id;
  pthread_mutex_t serve;
} dwarf;

int cont;
sem_t sits, occuped;
dwarf *table[4];

void *dwarfH(void *arg)
{
  dwarf *d = (dwarf*)arg;
  printf("Dwarf %d going to fap\n", d->id);
  sleep(rand()%15);
  printf("Dwarf %d arrived from fapping\n", d->id);
  int i;
  sem_wait(&sits);
  printf("Dwarf %d sit's on table\n", d->id);
  for(i = 0; i < 4; ++i)
  {
    if(table[i] == NULL)
    {
      table[i] = d;
      sem_post(&occuped);
      pthread_mutex_trylock(&(d->serve));
      break;
    }
  }
  pthread_mutex_lock(&(d->serve));
  sleep(2);
  printf("Dwarf %d finish eating, now it's going for a cigarrete\n", d->id);
  table[i] = NULL;
  sem_post(&sits);
  pthread_exit(NULL);
}

void *snowH(void *arg)
{
  int status, cont = 0;

  while(cont < 7)
  {
    int i, j;
    sem_getvalue(&occuped, &j);
    if(j > 0)
    {
      for(i = 0; i < 4; ++i)
      {
        if(table[i] != NULL)
        {
          pthread_mutex_unlock(&(table[i]->serve));
          printf("I give food and a handjob to dwarf #%d\n", table[i]->id);
          sem_trywait(&occuped);
          cont++;
        }
      }
    }
    else
    {
      printf("Snowhite it's going to finger herself\n");
      sleep(5);
    }
  }
  printf("All dwarf's are satisfy\n");
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  srand((unsigned)time(NULL));
  sem_init(&sits, 0, 4);
  sem_init(&occuped, 0, 0);
  dwarf *dwarfs = (dwarf*)malloc(sizeof(dwarf)*7);
  int i = 0;

  for(i; i < 7; ++i)
  {
    (dwarfs+i)->id = i+1;
    pthread_mutex_init(&(dwarfs+i)->serve, NULL);
  }

  pthread_t *dwarfp = (pthread_t*)malloc(sizeof(pthread_t)*7);
  pthread_t *snowp;
  pthread_create(&snowp, NULL, &snowH, NULL);

  for(i = 0; i < 7; ++i)
    pthread_create(dwarfp+i, NULL, &dwarfH, (void*)(dwarfs+i));

  pthread_join(snowp, NULL);
  printf("ALLAHUAKBAR!!!!!!\n");
  sem_destroy(&sits);
  sem_destroy(&occuped);
  free(dwarfp);
  free(dwarfs);

  return 0;
}

