/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ex1.c
* Creation Date : 14-03-2016
* Last Modified : Mon 14 Mar 2016 10:49:46 AM CST
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

int num = 20;
pthread_mutex_t mutex;

typedef struct 
{
  int n;
}param;

void *duplicate(void *p)
{
  pthread_mutex_lock(&mutex);
  int tmp = num;

  for(int i = 0; i < ((param*)p)->n; ++i)
  {
    tmp *= 2;
    printf("Multiplying %d\n", tmp);
    sleep(5);
  }

  num = tmp;
  pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}

void *divide(void *p)
{
  pthread_mutex_lock(&mutex);
  int tmp = num;

  for(int i = 0; i < ((param*)p)->n; ++i)
  {
    tmp /= 2;
    printf("Dividing %d\n", tmp);
    sleep(5);
  }

  num = tmp;
  pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t th;
  pthread_t th2;

  param p;
  p.n = 5;

  pthread_create(&th, NULL, duplicate, &p);
  pthread_create(&th2, NULL, divide, &p);

  pthread_join(th, NULL);
  pthread_join(th2, NULL);

  return 0;
}

