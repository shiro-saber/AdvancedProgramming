/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise4.c
* Creation Date : 04-02-2016
*     Last Modified : Thu 04 Feb 2016 12:53:33 AM CST
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

int main(int argc, char *argv[])
{
  int pid, state;

  if(argc != 3)
  {
    printf("Syntax: ./pstree <number of father process> <number of child process for each father>\n");
    
    return -1;
  }

  printf("Father Process\t\tChild Process\t\tGrandChild Process\n");
  printf("    %d  \t\t\n", getpid());

  for(int i = 0; i < atoi(argv[1]); i++)
  {
    pid = fork();
    if(pid < 0)
    {
      printf("Error creating child\n");
      exit(1);
    }
    else if(pid == 0)
    {
      for(int j = 0; j < atoi(argv[2]); j++)
      {
        pid = fork();

        if (pid < 0)
        {
          printf("Error creating child\n");
          exit(1);
        }
        else if(pid == 0)
        {
           printf("          \t\t%d\t\t  %d\n", getppid() ,getpid());
          exit(0);
        }
        else
          wait(&state);
      }
      printf("    %d    \t\t%d\t\t  \n", getppid() ,getpid());
    }
    else
      wait(&state);
  }

  return 0;
}

