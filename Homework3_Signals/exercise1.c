/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise1.c
* Creation Date : 25-02-2016
* Last Modified : Thu 25 Feb 2016 02:25:13 PM CST
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
#include <signal.h>
#include <sys/types.h>

// Make a program in C that allow create a child, the child
// will sleep 10 seconds, after wake up will send the SIGUSR1
// signal to the father. At recieving the signal the father will
// print the next message:
// "You send X CTRL-C signals and you send Y CTRL-Z signals. Finishing..."
// Then the father will send the end signal to all the process of 
// the group.
// While the child sleep, the father will show a message every x seconds
// Initially x = 3.
// The message it's like this:
// "I'm showing up every x seconds".
// To control the time intervals of x we need to set a temporizer
// that will generate a signal at the end of time
// If send CTRL-C the time will be x+1.
// If send CTRL+Z the time will be x-1

void control(int signal)
{
  if(signal == SIGUSR1)
  {
    printf("Signal of the user\n");
  }
  else if(signal == SIGINT)
  {
    printf("You press CTR-C\n");
    //ctimes++;
  }
  else if(signal == SIGTSTP)
  {
    printf("You press CTRL-Z\n");
    //ytimes++;
  }
}

int main(int argc, char *argv[])
{
  pid_t pid; 
  int x = 3; // time
  
  if(pid == 0)
  {
    //child part
    sleep(10); // Duerme 10 segundos
    kill(getpid(), SIGUSR1);// manda la señal
  }
  else
  {
    //daddy part
  }

  return 0;
}

