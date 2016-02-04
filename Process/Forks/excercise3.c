/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : excercise3.c
* Creation Date : 03-02-2016
* Last Modified : Thu 04 Feb 2016 12:20:57 AM CST
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

// Make a C program that create N number of child process, each child
// wait for a random time, the father will print the PID of each child
// when this finish

int main(int argc, char *argv[])
{
  int pid, n, i, r, state;

  srand((int)time(NULL));
  
  printf("How many childs?\n");
  scanf("%d", &n);

  printf("Father Process\t\tPid Hijo\tTiempo\n");
  printf("    %d  \t\t\n", getpid());

  for(i = 0; i < n; i++)
  {
    pid = fork();
    r = rand() % 10;

    if(pid < 0) 
    {
      printf("Error creating child");
      exit(1);
    } 
    else if (pid == 0) 
    {
       //printf("Estamos en el proceso hijo con PID = %d y su padre es PPID = %d \n", getpid(), getppid());
      printf("    %d    \t\t%d\t\t  %d\n", getppid() ,getpid(), r);
      //sleep(r);
      exit(0);
    } 
    else
    {
      //sleep(r);
      wait(&state);
    }
    //sleep(r);
  }

  sleep(r);

  return 0;
}

