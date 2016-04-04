/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : bathroom.c
* Creation Date : 03-04-2016
* Last Modified : Sun 03 Apr 2016 06:48:50 PM CDT
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
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int aux = 0, next = -1, direction = -1, women = 0, men = 0, ocupped = 0;
pthread_mutex_t lock;

void *add(void *arg)
{
  while(1)
  {
    pthread_mutex_lock(&lock2);
    pthread_mutex_lock(&lock);
    
    int temp;
    temp = rand()%100;
    
    if(temp%2 == 0)
    {
      women++;
      printf("Woman arrive, %d in wait\n",women);
      if(aux == 0)
      {
        direction = 0;
        aux = 1;
      }
    }
    else if(temp%3 == 0)
    {
      men++;
      printf("Man arrive, %d in wait\n",men);
      if(aux == 0)
      {
        direction = 1;
        aux = 1;
      }
    }
    pthread_cond_broadcast(&cond);
    pthread_mutex_unlock(&lock);
    next = 1;
  }
}

void *pass(void *arg)
{
  while(1)
  {
    int sum = 0;
    pthread_mutex_lock(&lock);
    
    while(next == -1)
      pthread_cond_wait(&cond, &lock);
    
    if(ocupped == 2)
      printf("Men's bathroom ocupped\n");
    else if(ocupped == 1)
      printf("Women's bathroom ocupped\n");
    else if(ocupped == 0)
      printf("Empty bathroom\n");
    
    switch ((int)arg) 
    {
      case 0:
        if(direction == 0 && women > 0)
        {
          ocupped = 1;
          women--;
          printf("Girl out, status: %d women's in line\n", women);
        }
        break;
      case 1: 
        if(direction == 0 && men > 0)
        {
          ocupped = 2;
          men--;
          printf("Guy out, status: %d men's in line\n", men);
        }
        break;
    }

    if(men == 0 && women == 0)
      ocupped = 0;
    else if(women == 0)
    {
      ocupped = 2;
      direction = 1;
    }
    else if(men == 0)
    {
      ocupped = 1;
      direction = 0;
    }
    
    pthread_mutex_unlock(&lock);
    pthread_mutex_unlock(&lock2);
    sleep(1);
  }
}

int main(int argc, char *argv[])
{
  pthread_t *tid = (pthread_t*)malloc(sizeof(pthread_t)*3);

  pthread_create(tid, NULL, &add, 2);
  pthread_create(tid+1, NULL, &pass, 0);
  pthread_create(tid+2, NULL, &pass, 1);

  pthread_join(*(tid), NULL);
  pthread_join(*(tid+1), NULL);
  pthread_join(*(tid+2), NULL);

  pthread_mutex_destroy(&lock);
  pthread_mutex_destroy(&lock2);
  pthread_cond_destroy(&cond);
  free(tid);

  return 0;
}

