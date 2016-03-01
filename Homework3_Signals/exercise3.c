/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise3.c
* Creation Date : 29-02-2016
* Last Modified : Mon 29 Feb 2016 11:17:06 PM CST
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
#include <wait.h>
#include <unistd.h>

// Make a C program that:
// 

const int t = 3;
int i = 0;

void control_alarm(int signal)
{
  printf("Hurry up, Data X: \n");
  int res = alarm(t);
}

int main(int argc, char *argv[])
{
  struct sigaction gest;
  int err;
  int *nums;

  if (argc != 2) 
  {
    fprintf(stderr, "The right use it's %s <number higher than 4 less than 10>\n", argv[0]);
    exit(-1);
  }

  if(atoi(argv[1]) <= 4 || atoi(argv[1]) >=10)
  {
    fprintf(stderr, "The right use it's %s <number higher than 4 less than 10>\n", argv[0]);
    exit(-1);
  }

  nums = (int*)malloc(sizeof(int)*atoi(argv[1]));
  
  gest.sa_handler = control_alarm;
  gest.sa_flags = SA_RESTART;
  err = sigaction (SIGALRM, &gest, 0);
  signal(SIGINT, SIG_IGN);
  alarm(t);
  
  for(i ; i < atoi(argv[1]); ++i)
  {
    printf("Data X: \n");
    scanf("%d", *(nums+i)); 
  }

  return 0;
}

