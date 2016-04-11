/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : smoking.c
* Creation Date : 15-03-2016
* Last Modified : Thu 07 Apr 2016 10:45:36 AM CDT
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
#include <time.h>

#define PAPER 0
#define TOBACCO 1
#define MATCHES 2

int material;
int mm1;
int mm2;
int put;

pthread_mutex_t zain = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t tutzke = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t yaharadin = PTHREAD_MUTEX_INITIALIZER;

void agent (void* arg)
{
  int r1=0;
  int r2=0;
  
  while(1)
  {
    pthread_mutex_trylock(&zain);
    pthread_mutex_trylock(&tutzke);
    pthread_mutex_trylock(&yaharadin);
    sleep(15);
    
    if(put)
    {
      put=0;
      srand(time(NULL));
      mm1=rand()%3;
      do
      {
        mm2=rand()%3; 
      }while(mm1==mm2);
    }
    
    pthread_mutex_unlock(&yaharadin);
    pthread_mutex_unlock(&tutzke);
    pthread_mutex_unlock(&zain);
  }
}

void fumar1(void * arg1)
{
  int mine1;
  mine1= ((int*)(arg1));
  
  while(1)
  {
    pthread_mutex_trylock(&zain);
    pthread_mutex_trylock(&tutzke);
    pthread_mutex_trylock(&yaharadin); 
    
    if(mine1 ==mm1 || mine1==mm2)
    {
      pthread_mutex_unlock(&yaharadin);
      pthread_mutex_unlock(&tutzke);
      pthread_mutex_unlock(&zain);
      printf("I'm the smoker %d and I got cancer!\n", mine1);
      sleep(10); 
    }
    else
    {
      mm1=-1;
      mm2=-1;
      
      put=1;
      
      pthread_mutex_unlock(&yaharadin);
      pthread_mutex_unlock(&tutzke);
      pthread_mutex_unlock(&zain);
      
      printf("Giving\n"); 
      sleep(20);
    }
  }
  pthread_exit(NULL);
}

void fumar2(void * arg2)
{  
  int mine2;
  mine2= ((int*)(arg2));
  
  while(1)
  {
    pthread_mutex_trylock(&zain);
    pthread_mutex_trylock(&tutzke);
    pthread_mutex_trylock(&yaharadin);
    //sleep(10);
    
    if(mine2 ==mm1 || mine2==mm2)
    {
      pthread_mutex_unlock(&yaharadin);
      pthread_mutex_unlock(&tutzke);
      pthread_mutex_unlock(&zain);
      printf("I'm the smoker %d, and I got cancer!\n", mine2);
      sleep(10);
    }
    else
    {
      mm1=-1;
      mm2=-1;
      put=1;
      
      pthread_mutex_unlock(&yaharadin);
      pthread_mutex_unlock(&tutzke);
      pthread_mutex_unlock(&zain);
      
      printf("Giving\n");
      sleep(20);
    }
  }
  pthread_exit(NULL);
}

void fumar3(void * arg3)
{
  int mine3;
  mine3= ((int*)(arg3));
  
  while(1)
  {
    pthread_mutex_trylock(&zain);
    pthread_mutex_trylock(&tutzke);
    pthread_mutex_trylock(&yaharadin);
    //sleep(10);
    
    if(mine3 ==mm1 || mine3==mm2)
    {
      pthread_mutex_unlock(&yaharadin);
      pthread_mutex_unlock(&tutzke);
      pthread_mutex_unlock(&zain);
      printf("I'm the smoker %d, and I got cancer!\n", mine3);
      sleep(10);
    }
    else
    {
      mm1=-1;
      mm2=-1;
      put=1;
      
      pthread_mutex_unlock(&yaharadin);
      pthread_mutex_unlock(&tutzke);
      pthread_mutex_unlock(&zain);
      
      printf("Giving\n"); 
      sleep(20);
    }
  }
  pthread_exit(NULL);
}

int main()
{
  mm1 = PAPER;
  mm2 = MATCHES;
  put=0;
  
  pthread_t* tids= (pthread_t*)malloc(4*sizeof(pthread_t));
  pthread_create((tids),NULL,agent,1);
  pthread_create((tids+1),NULL,fumar1,PAPER);
  pthread_create((tids+2),NULL,fumar2,TOBACCO);
  pthread_create((tids+3),NULL,fumar3,MATCHES);

  pthread_join(*(tids),NULL);
  pthread_join(*(tids+1),NULL);
  pthread_join(*(tids+2),NULL);
  pthread_join(*(tids+3),NULL);

  free(tids);
  printf("AllahUakbar!\n");

  return 0;
}
