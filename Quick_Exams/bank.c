/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : bank.c
* Creation Date : 17-03-2016
* Last Modified : Thu 17 Mar 2016 12:12:10 PM CST
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
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <time.h>

#define client 5
#define enterprise 3

typedef struct
{
  sem_t sem;
  int id;
	int cont;
	int id_u;
} enterprises;

typedef struct
{
  sem_t sem;
  int id;
	int cont;
	int id_u;
}clients;

enterprises cash_e[enterprise];
clients cash_c[client];


void* attendE(int n, int p)
{
	printf("The client %d it's being attend on the casheer %d, of the enterpises casheers\n", n, p);
  cash_e[p].cont += 1;

  sleep((rand()%120)+180);

  if(cash_e[p].cont == 5)
  {
	  sleep(180);
    cash_e[p].cont = 0;
  }
	pthread_exit(NULL);
}

void* attendC(int n, int p)
{
	printf("The client %d it's being attend on the casheer %d, of the clients casheers\n", n, p);
  cash_c[p].cont += 1;

  sleep((rand()%120)+180);

  if(cash_c[p].cont == 5)
  {
	  sleep(180);
    cash_c[p].cont = 0;
  }

	pthread_exit(NULL);
}

void* op_C(int n)
{
  int status = -1;
	int i = 0;
	while(status == -1)
  {
	  for (i; i < client; ++i)
    {
	    status = sem_trywait(&cash_c[i].sem);
	    if (status == 0)
	      attendC(n, i);
    }
	}
}

void* op_E(int n)
{
  int status = -1;
	int i = 0;
	while(status == -1)
  {
	  for (i; i < enterprise; ++i)
    {
	    status = sem_trywait(&cash_e[i].sem);
	    if (status == 0)
        attendE(n, i);
    }
	}
}

int main(int argc, char *argv[])
{
  srand((unsigned)time(NULL));
  int i = 0; 

  for(i = 0; i < enterprise; ++i)
  {
    sem_init(&cash_e[i], 0, 1);
    cash_e[i].id = i;
    cash_e[i].cont = 0;
  }

  for(i = 0; i < client; ++i)
  {
    sem_init(&cash_c[i], 0, 1);
    cash_c[i].id = i;
    cash_c[i].cont = 0;
  }

  pthread_t clients_gen[100];
	pthread_t enterprises_gen[50];
  
  pthread_t *aux;
  int index = 0;

  for(aux = clients_gen; aux < (clients_gen+50); ++aux)
    pthread_create(aux, NULL, op_C, (void*)index++);

  for(aux = enterprises_gen; aux < (enterprises_gen+50); ++aux)
    pthread_create(aux, NULL, op_E, (void*)index++);

  for(aux = clients_gen; aux < (clients_gen+50); ++aux)
    pthread_join(*aux, NULL);

  for(aux = enterprises_gen; aux < (enterprises_gen+50); ++aux)
    pthread_join(*aux, NULL);

  for(i = 0; i < client; ++i)
    sem_destroy(&(cash_c[i].sem));

   for(i = 0; i < enterprise; ++i)
    sem_destroy(&(cash_e[i].sem));

  return 0;
}

