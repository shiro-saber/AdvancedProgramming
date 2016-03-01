/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise1.c
* Creation Date : 25-02-2016
* Last Modified : Mon 29 Feb 2016 07:37:37 PM CST
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

int t = 3; // time
int loop = 1;
int numc = 0; //ctrl+c times
int numz = 0; //ctrl+z times
int child; //the process child

void control_sigusr(int signal)
{
  loop = 0;
  printf("Has intentado cortar %d veces.\nHas intentado detener %d veces\n", numc, numz);
  kill(child, SIGKILL);
  printf("The son has been killed\n");
  raise(SIGKILL);
}

void control_alarm(int signal)
{
  printf("Aparezco cada %d segundos.\n", t);
  int res = alarm(t);
}

void control_ctrlc(int signal)
{
  t++;
  int res = alarm(t);
  printf("Pulso CTRL + C, te quedaban %d seg\n", res);
  ++numc;  
}

void control_ctrlz(int signal)
{
  t--;
  int res = alarm(t);
  printf("Pulso CTRL + Z, te quedaban %d seg\n", res);
  ++numz; 
}

int main(int argc, const char * argv[])
{
  struct sigaction gest;
  int err, status;
  pid_t pid;
  
  if(pid == 0)
  {
    /* sleep 10 seconds */
    printf("I'm the child with pid %d and my father pid is %d\n", getpid(), getppid());
    child = getpid();
    sleep(10);
    /* send the signal */
    kill(getppid(), SIGUSR1);
    exit(0);
  }
  else if (pid > 0)
  {
    /* catching CTRL+C */
    gest.sa_handler = control_ctrlc;
    gest.sa_flags = SA_RESTART;
    
    err = sigaction (SIGINT, &gest, 0);
    
    /* catching CTRL+Z */
    gest.sa_handler = control_ctrlz;
    gest.sa_flags = SA_RESTART;
    
    err = sigaction (SIGTSTP, &gest, 0);
    
    /* catching alarm */
    gest.sa_handler = control_alarm;
    gest.sa_flags = SA_RESTART;
    
    err = sigaction (SIGALRM, &gest, 0);
   
    /* start alarm*/
    alarm(t);
    
    /* catching sigusr*/
    gest.sa_handler = control_sigusr;
    gest.sa_flags = SA_ONESHOT;
    
    err = sigaction (SIGUSR1, &gest, 0);
    //while(loop);
    waitpid(pid, &status, 0);
    //wait(NULL);
  }
 
  return 0;
}
