/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : excercise3.c
* Creation Date : 03-02-2016
* Last Modified : Mon 08 Feb 2016 02:29:32 PM CST
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
  pid_t *pid = (int*)malloc(sizeof(int)*n);

  srand((int)time(NULL));
  
  printf("How many childs?\n");
  scanf("%d", &n);

  printf("Father Process\t\tPid Hijo\n");
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
       //printf("Estamos en el proceso hijo con PID = %d y su padre es PPID = %d \n", getpid(), getppid());
      sleep(rand()%10);
      printf("    %d      \t\t%d\n", getppid(), getpid());
      exit(0);
    }
    else
    {
      for(i = 0; i < n; i++)
        if((waitpid(*(pid+i), &state, 0) != -1))
          printf("Ya terminó el hijo con PID %d \n", *(pid+i));

      wait(NULL);
    }
  }
  return 0;
}

