/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise4.c
* Creation Date : 04-02-2016
* Last Modified : Thu 11 Feb 2016 05:11:26 PM CST
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
#include <sys/wait.h>
#include <sys/types.h>

// Make a program that get -n and -p from command line
// Make p process and n level's and print it like the
// command pstree

void pstree(int n, int lvl, int proc)
{
  int i, j;
  pid_t pid;

  for(j = 0; j < n; ++j)
    printf("    ");

  printf("--->%d\n", getpid());

  for(i = 0; i < proc; ++i)
  {
    pid = fork();

    if(pid < 0)
    {
      printf("Error creating morro\n");
      exit(1);
    }
    else if(pid == 0)
    {
      if(n < lvl)
        pstree(n+1, lvl, proc);
      
      exit(0);
    }
    else
      for (j = 0; j < proc; ++j)
        wait(NULL);
  }
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "Syntax: %s <number of levels> <number of process in each level>\n", argv[0]);
    return -1;
  }
  int lvl = atoi(argv[1]);
  int proc = atoi(argv[2]);

  printf("%s %d %d\n", argv[0], lvl, proc);

  pstree(0, lvl, proc);
  return 0;
}
