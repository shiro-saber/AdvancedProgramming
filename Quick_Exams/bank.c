/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : bank.c
* Creation Date : 17-03-2016
* Last Modified : Thu 17 Mar 2016 11:43:06 AM CST
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

sem_t c_sem[client];
sem_t e_sem[enterprise];

typedef struct
{
  int id;
	int cont;
	int id_u;
} enterprises;

typedef struct
{
  int id;
	int cont;
	int id_u;
}clients;

void* attendE(int n, int p)
{
	enterprises* e = (enterprises*)p;
	if(e->cont == 5)
	  sleep(180);

	pthread_exit(NULL);
}

void* attendC(int n, int p)
{
	clients* c = (clients*)p;
	if(c->cont == 5)
	  sleep(180);

	pthread_exit(NULL);
}

void* op_C(int n)
{
  int status = -1;
	int i = 0;
	while(status == -1){
	  for (i; i < client; ++i){
	    status = sem_trywait(cash_c[i].sem);
	    if (status == 0)
	      attendC(n, i);
    }
	}
}

void* op_E(int n)
{
  int status = -1;
	int i = 0;
	while(status == -1){
	  for (i; i < enterprise; ++i){
	    status = sem_trywait(cash_e[i].sem);
	    if (status == 0)
          attendE(n, i);
    }
	}
}


int main(int argc, char *argv[])
{
  srand((unsigned)time(NULL));
  int i = 0; 

  enterprises cash_e[enterprise];
  clients cash_c[client];

  for(i = 0; i < enterprise; ++i)
  {
    sem_init(&e_sem[i], 0, 1);
    cash_e[i].id = i;
    cash_e[i].cont = 0;
  }

  for(i = 0; i < client; ++i)
  {
    sem_init(&c_sem[i], 0, 1);
    cash_c[i].id = i;
    cash_c[i].cont = 0;
  }

  pthread_t clients_gen[100];
	pthread_t enterprises_gen[50];

  return 0;
}

