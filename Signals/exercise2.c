/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise1.c
* Creation Date : 25-02-2016
* Last Modified : Thu 25 Feb 2016 11:25:31 AM CST
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
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

// Change the first exercise and make CTRL+Z
// print that can't stop the process.

void handler(int sign)
{
  printf("Cannot stop the process\n");
}

int main(int argc, const char * argv[]) 
{
  pid_t pid;

  pid = fork();

  if (pid == 0)
  {
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, handler);
    printf("Going to sleep\n");
    sleep(2);
    printf("My pid is %d, and my dad's pid it's %d\n", getpid(), getppid());
    // A partir de aquí Ctrl+C no termina el programa
    int k = 10;
    
    while (k-- > 0) {
      printf(" +++ %d and counting\n", k);
      sleep(1);
    }
  }
  else
  {
    printf("I'm daddy with pid: %d\n", getpid());
    printf("You will kill me if you enter CTRL+C\n");
    signal(SIGTSTP, handler);
    
  }

  return 0;
}
