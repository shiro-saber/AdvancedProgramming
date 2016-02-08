/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : process_exam.c
* Creation Date : 07-02-2016
* Last Modified : Mon 08 Feb 2016 10:15:06 AM CST
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

int main(int argc, char *argv[])
{
  pid_t pid;
  pid_t sum;
  int status;

  if(argc != 2)
  {
    printf("Syntax: ./process <number_of_process>\n"); 
      
    return -1;
  }

  for(int i = 0; i < atoi(argv[1]); ++i)
  {
    pid = fork();

    if(pid == -1)
    {
      printf("Error creating child\n");
      exit(1);
    }
    else if(pid == 0)
    {
      printf("Son with pid %d with father %d\n", getpid(), getppid());
      sum = (getpid()+getppid());
      printf("The average id: %d\n", sum/2);
      exit(0);
    }
    else
    {
      if((waitpid(pid, &status, 0) != -1))
      {
        if(WIFEXITED(status))
          printf("Son with pid: %d DONE!\n", pid);
      }
    }
      
  }
  return 0;
}

