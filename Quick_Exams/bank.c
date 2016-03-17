/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : bank.c
* Creation Date : 17-03-2016
* Last Modified : Thu 17 Mar 2016 11:26:48 AM CST
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
} eterprises;

typedef struct
{
  int id;
	int cont;
	int id_u;
}clients;

void* attendE(void* p)
{
	enterprises* e = (enterprises*)p;
	if(e->cont == 5)
	  sleep(180);

	pthread_exit(NULL);
}

void* atenderEmpresarial(void* p)
{
	clients* e = (clients*)p;
	if(e->cont == 5)
	  sleep(180);

	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  srand((unsigned)time(NULL));
  int i = 0; 

  enterprises cash_e[enterprises];
  clients cash_c[clients];

  for(i = 0; i < enterprises; ++i)
  {
    sem_init(&e_sem[i], 0, 1);
    cash_e[i].id = i;
    cash_e[i].cont = 0;
  }

  for(i = 0; i < enterprises; ++i)
  {
    sem_init(&c_sem[i], 0, 1);
    cash_c[i].id = i;
    cash_c[i].cont = 0;
  }

  pthread_t clients_gen[100];
	pthread_t enterprises_gen[50];

  return 0;
}
