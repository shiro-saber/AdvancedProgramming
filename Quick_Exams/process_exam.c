/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : process_exam.c
* Creation Date : 07-02-2016
* Last Modified : Mon 15 Feb 2016 02:04:34 AM CST
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
#include <sys/types.h>

// Make a program that recives the number of process to create
// each process will get the average between him and his father
// and finally make the father wait all the child process to
// end.
// NOTES: The number of process to create will pass as a parameter
// from terminal.

int main(int argc, char *argv[])
{
  pid_t *pid;
  pid_t sum;
  int status, k;

  if(argc != 2)
  {
    printf("Syntax: ./process <number_of_process>\n"); 
      
    return -1;
  }

  pid = (pid_t*)malloc(sizeof(pid_t)*atoi(argv[1]));

  for(int i = 0; i < atoi(argv[1]); ++i)
  {
    *(pid+i) = fork();
    k++;

    if(*(pid+i) == -1)
    {
      printf("Error creating child\n");
      exit(1);
    }
    else if(*(pid+i) == 0)
    {
      printf("Son with pid %d with father %d\n", getpid(), getppid());
      sum = (getpid()+getppid());
      printf("The average id: %d\n", sum/2);
      exit(0);
    } 
  }

  pid_t kuz;
  
  while ((kuz = wait(NULL)) > 0)
    printf("Termino el proceso: %d\n", kuz);

  printf("\n\n The total number of process are: %d\n", k);
  return 0;
}

