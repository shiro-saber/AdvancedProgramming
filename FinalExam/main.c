/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.c
* Creation Date : 12-05-2016
* Last Modified : Thu 12 May 2016 09:22:07 AM CDT
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
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

#define nprocesadores 8
#define HILOS 4

typedef struct {
	int x;
	int y;
} Move;

typedef struct RobotT {
	int x;
	int y;
	struct RobotT *r;
	int steps;
} Robot;

void printBoard(char *); //es obvio
void divideBoard(int *); //divide el tablero
void gestor(int sig); //gestor de la señal
void boom(char ***); //liberador de memoria
int tamano; //tamaño del tablero
int aux; //cuadrantes

int main(int argc, char *argv[])
{
  printf("Ingresa el tamaño del tablero\n");
  scanf("%d", &tamano);

  int *b = (int*)malloc(tamano*tamano*sizeof(int));
	int i, myid;

  if (myid == 0)
    if (signal(SIGUSR1,gestor) == SIG_ERR)
	    printf("No se pudo establecer el manejador de la senal....\n");

	for (i=0;i<tamano*tamano;++i)
	  *(b+i) = 0;

	Robot *r = (Robot*)malloc(sizeof(Robot));
	r->x = 0;
	r->y = 0;
	r->steps = 0;
	r->r = NULL;

	if (myid == 0)
  {
	  printf("I am the boss, I divide the board\n");
	  divideBoard(b);
	}

  return 0;
}

void gestor(int sig)
{
  printf("Recibi SIGUSR1\n");
  sleep(2);
}

void boom(char ***allahuakbar)
{
  int i = 0, j = 0;

  for(i; i < tamano; ++i)
  {
    for(j; j < tamano; ++j)
      free(*(*allahuakbar+i)+j);
    
    free(*(allahuakbar+i));
  }
  free(allahuakbar);
}

void printBoard(char *b)
{
 int i,j;
	for (i=0;i<tamano;++i)
  {
    for (j=0;j<tamano;++j)
    {
	    if (*(b+tamano*i+j)==0)
	      printf("0 ");
	    else 
	      printf("1 ");
	  }
	  printf("\n");
	} 
}

void divideBoard(int *b)
{
  int size = sqrt((tamano*tamano)/nprocesadores);
	int blocks = size/2;
	printf ("Size of each board %d and %d blocks per row\n",size,blocks);

	int i;
	int *x = (int*)sizeof(int);
	int *y = (int*)sizeof(int);
	int j = 0;
	*x = 0;

	#pragma omp for private(x,y)
	for (i=0;i<nprocesadores;++i)
  {
	  *y = *x + j*size;
    /* Aqui van los threads */ 
	  j++;
	  if (j == blocks)
    {
	    j = 0;
	    x = x + size;
	  }		
	}

	free(x);
	free(y);
}
