/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : dwarfs.c
* Creation Date : 31-03-2016
* Last Modified : Thu 31 Mar 2016 10:55:48 AM CST
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

#define sits 4
#define dwarfs 7

int taken = 0;
int dishes = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t kuz = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t consume_t = PTHREAD_COND_INITIALIZER;
pthread_cond_t sit = PTHREAD_COND_INITIALIZER;
pthread_cond_t produce_t = PTHREAD_COND_INITIALIZER;

void *snow(void *arg)
{
  while(1)
  {
    pthread_cond_wait(&produce_t, &mutex);
    pthread_mutex_lock(&mutex);
    dishes++;
    printf("A dwarf want's to eat\n");
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&consume_t);
  }

  pthread_exit(NULL);
}

void *dwarf(void *arg)
{
  while(1)
  {
    //sleep(1);
    usleep(rand()%500);
    pthread_mutex_lock(&kuz);
    if(taken < sits)
    {
      taken++;
      pthread_cond_signal(&produce_t);
      printf("I sit on a place, and ask for food\n");
    }
    else
    {
      printf("Waiting for one damn sit!\n");
      pthread_cond_wait(&sit, &kuz);
      pthread_cond_signal(&produce_t);
      printf("I got a chair after wait, and finally i will eat\n");
      taken++;
    }
    
    pthread_mutex_unlock(&kuz);
    pthread_cond_wait(&consume_t, &mutex);        
    pthread_mutex_lock(&mutex);
    dishes--;
    taken--;
    printf("I ate, going to fap\n");
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&sit);
  }
}
int main(int argc, char *argv[])
{
  pthread_t *table = (pthread_t*)malloc(sizeof(pthread_t)*dwarfs+1);
  pthread_t *aux;
  int index = 0;

  for(aux=table; aux < (table+dwarfs); ++aux)
  {
    printf("Creating dwarf #%d\n", ++index);
    pthread_create(aux, NULL, dwarf, (void*)index);
  }

  printf("Creating Snowhite\n");
  ++index;
  pthread_create(aux, NULL, snow, (void*)index);

  for(aux=table; aux < (table+dwarfs+1); ++aux)
    pthread_join(*aux, NULL);

  free(table);
  return 0;
}

