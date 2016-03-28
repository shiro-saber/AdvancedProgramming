/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : philosopher.c
* Creation Date : 17-03-2016
* Last Modified : Thu 17 Mar 2016 10:06:12 AM CST
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

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <semaphore.h>

const int ITERATIONS = 5;

sem_t chopstick[5];

int philosopher(int n)
{
  int i, j, first, second;

  printf("Philosopher %d was born!\n", n);

  first = (n < 4)? n : 0; /* left for phil 0 .. 3, right for phil 4 */
  second = (n < 4)? n + 1 : 4; /* right for phil 0 .. 3, left for phil 4 */

  for(i = 0; i < ITERATIONS; i++) 
  {
    printf("Philosopher %d is thinking ...\n", n);
    sem_wait(&chopstick[first]);  /* get first chopstick */
    sem_wait(&chopstick[second]); /* get second chopstick */

    printf("Philosopher %d is eating ...\n", n);
    sem_post(&chopstick[first]);  /* release first chopstick */
    sem_post(&chopstick[second]); /* release second chopstick */
  }

  pthread_exit((void *)n);
}

int main()
{
  int i, status;
  pthread_t phil[5];

  printf("The Dining-Philosophers Problem\n");

  for(i = 0; i < 5; i++)
    sem_init(&chopstick[i], 0, 1);

  for(i = 0; i < 5; i++)
    if(pthread_create(&phil[i], 0, (void*(*)(void*))philosopher,(void *)i))
      return -1;

  for(i = 0; i < 5; i++) 
  {
    pthread_join(phil[i], (void **)&status);
    if(status == i)
      printf("Philosopher %d went to heaven!\n", i);
    else
      printf("Philosopher %d went to hell!\n", i);
  }

  for(i = 0; i < 5; i++)
    sem_destroy(&chopstick[i]);

  return 0;
}
