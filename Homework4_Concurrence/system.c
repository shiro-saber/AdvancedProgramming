/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : system.c
* Creation Date : 03-04-2016
* Last Modified : Sun 03 Apr 2016 06:50:49 PM CDT
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
#include <unistd.h>
#include <signal.h>

#define UAD 5 //sections

FILE *data;
int meds[UAD];
int alarms[UAD];
int i = 0;

pthread_t central;
pthread_mutex_t mutexes[UAD*2] = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t file = PTHREAD_MUTEX_INITIALIZER;

void registr(int id)
{
  printf("Taking meds\n");
  for(i = 0; i < UAD; ++i)
  {
    pthread_mutex_lock(mutexes+i);
    pthread_mutex_lock(&file);
    
    data = fopen("data", "a+");
    fprintf(data, "UAD #%d total med => %d\n", i, meds[i]);
    fclose(data);
    pthread_mutex_unlock(&file);
    pthread_mutex_unlock(mutexes+i);
    alarm(rand()%5);
  }
  printf("Closing FILE\n");
}

void critical(int id)
{
  for(i = 0; i < UAD; ++i)
  {
    pthread_mutex_lock(mutexes+UAD+i);
    if(alarms[i])
    {
      pthread_mutex_lock(&file);
      data = fopen("data", "a+");
      fprintf(data, "UAD #%d - ALERT! CRITICAL-VALUE\n", i);
      fclose(data);
      pthread_mutex_unlock(&file);
      alarms[i]--;
    }
    pthread_mutex_unlock(mutexes+i+UAD);
  }
}

void *threadfunc(void *arg)
{
  int tmp;

  while(1)
  {
    sleep(rand()%3+1);
    pthread_mutex_lock(&(*(mutexes + (int)arg)));
    
    meds[(int)arg] = rand()%10;
    pthread_mutex_lock(&(*(mutexes+(int)arg)));
    
    if(!(tmp = rand()%10))
    {
      printf("UAD #%d - CRITICAL VALUE - alarm send\n", (int)arg);
      pthread_mutex_lock(mutexes+(int)arg+UAD);
      alarms[(int)arg]++;
      pthread_kill(central, SIGUSR1);
      pthread_mutex_unlock(mutexes+(int)arg+UAD);
    }
  }
  pthread_exit(NULL);
}

void *centralfunc(void *arg)
{
  signal(SIGALRM, registr);
  signal(SIGUSR1, critical);

  alarm(rand()%5);
  while(1);
  pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  srand(time(NULL));

  pthread_t *uads = (pthread_t*)malloc(sizeof(pthread_t)*UAD);
  pthread_create(&central, NULL, centralfunc, NULL);

  for(i = 0; i < UAD; ++i)
    pthread_create(uads+i, NULL, threadfunc, i);

  for(i = 0; i < UAD; ++i)
    pthread_join(*(uads+i), NULL);

  pthread_join(central, NULL);

  free(uads);

  return 0;
}

