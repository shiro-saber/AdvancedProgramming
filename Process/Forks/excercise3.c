/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : excercise3.c
* Creation Date : 03-02-2016
* Last Modified : Mon 15 Feb 2016 02:31:37 AM CST
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
#include <wait.h>
#include <time.h>
#include <sys/types.h>

// Make a C program that create N number of child process, each child
// wait for a random time, the father will print the PID of each child
// when this finish

int main(int argc, char *argv[])
{
  int n, i, r, state; 
   
  printf("How many childs?\n");
  scanf("%d", &n);

  pid_t *pid = (pid_t*)malloc(sizeof(pid_t)*n);

  printf("Father Process\t\tPid Hijo\t\tTime\n");
  printf("    %d  \t\t\n", getpid());

  for(i = 0; i < n; i++)
  {
    *(pid+i) = fork();
    
    if(*(pid+i) < 0) 
    {
      printf("Error creating child");
      exit(1);
    } 
    else if (*(pid+i) == 0) 
    {
      srand((int)time(NULL)^(getpid()<<1));
      r = rand() % 10;  
      printf("    %d      \t\t  %d     \t\t   %d\n", getppid(), getpid(), r);
      sleep(r);
      return 0;
    }
  }

  pid_t kuz;
  
  while ((kuz = wait(NULL)) > 0)
    printf("Termino el proceso: %d\n", kuz);
  
  printf("Todos los hijos han terminado\n");
  free(pid);
  return 0;
}

