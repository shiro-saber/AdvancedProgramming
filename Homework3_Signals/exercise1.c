/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise1.c
* Creation Date : 25-02-2016
*   Last Modified : Wed 02 Mar 2016 09:14:25 PM CST
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
#include <wait.h>
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

int t = 3, loop = 1;
int ctrlc, ctrlz, child;
pid_t pid;

void control_alarm(int signal)
{
  printf("I show up every %d seconds\n", t);
  int res = alarm(t);
}

void control_ctrlc(int signal)
{
  ++t;
  ++ctrlc;
  printf("In count %d ctrl+c\n", ctrlc);
  int res = alarm(t);
}

void control_ctrlz(int signal)
{
  if(t >= 1)
    --t;
  ++ctrlz;
  printf("In count %d ctrl+z\n", ctrlz);
  int res = alarm(t);
}

void control_sigusr(int signal)
{
  loop = 0;
  printf("I recived %d of Ctrl+C and %d of Ctrl+Z\n", ctrlc, ctrlz);
  printf("User Signal, my child will die!\n");
  kill(pid, SIGKILL);
  printf("\nAnd now what?!...\n\n\nALLAUHAKBAR!!\n");
  raise(SIGKILL);
}

int main(int argc, char *argv[])
{
  struct sigaction gest;
  int err;
  
  pid = fork();

  if(pid == 0)
  {
    /* This is the child! */
    child = getpid();
    printf("My pid is %d, and my dad's pid it's %d\n", child, getppid());
    printf("Now I'm going to sleep\n");
    sleep(10);
    printf("Woke up, sending User Signal to dad\n");
    kill(getppid(), SIGUSR1);
  }
  else
  {
    gest.sa_handler = control_alarm;
    gest.sa_flags = SA_RESTART;
    err = sigaction(SIGALRM, &gest, 0);
    alarm(t);
    
    gest.sa_handler = control_ctrlc;
    gest.sa_flags = SA_RESTART;
    err = sigaction(SIGINT, &gest, 0);
    
    gest.sa_handler = control_ctrlz;
    gest.sa_flags = SA_RESTART;
    err = sigaction(SIGTSTP, &gest, 0);
    
    gest.sa_handler = control_sigusr;
    gest.sa_flags = SA_ONESHOT;
    err = sigaction(SIGUSR1, &gest, 0);
    while(loop);
    wait(NULL);
  }

  return 0;
}
