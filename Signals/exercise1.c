/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise1.c
* Creation Date : 25-02-2016
* Last Modified : Thu 25 Feb 2016 10:56:37 AM CST
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

// Create a child process, this will ignore the signal
// CTRL+C and then:
// The process will sleep by 2 seconds, and sen the mesage
// indicating it's PID and the PPID, and will count from 10
// to 1, in 1 second intervals
// Before it end's, will send a similar mesage 
// The father will print his PID and warn that
// if you press CTRL+C only the father will die. 
// Then will sleep 10 seconds and finally
// will wait the child to finish, if hasn't finish yet.
// The father and the son will ignore the signal CTRL+Z

int main(int argc, const char * argv[]) 
{
  pid_t pid;

  pid = fork();

  if (pid == 0)
  {
    signal(SIGINT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
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
    signal(SIGTSTP, SIG_IGN);
    
  }

  return 0;
}
