/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise4.c
* Creation Date : 04-02-2016
* Last Modified : Mon 08 Feb 2016 11:18:58 AM CST
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
  pid_t child;
  int i, j, k;
  int lvl = atoi(argv[1]);
  int proc = atoi(argv[2]);

  if(argc != 3)
  {
    printf("Syntax: ./pstree <number of levels> <number of process in each level>\n");
    
    return -1;
  }

  printf("%s %d %d\n", argv[0], lvl, proc);

  for (k = 0; k < lvl; k++)
  {
    for(j = 0; j < proc; j++)
    {
      child = fork();

      if(child < 0)
      {
        printf("Error creating child\n");
        exit(1);
      }
      else if(child == 0)
      {
        for(i = 0; i < k; ++i)
          printf("    ");

        printf("--->%d\n", getpid());
        //break;
      }
      else
        wait(NULL);
    }
  }

  return 0;
}

