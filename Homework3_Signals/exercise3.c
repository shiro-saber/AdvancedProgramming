/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise3.c
* Creation Date : 29-02-2016
* Last Modified : Tue 01 Mar 2016 12:02:04 AM CST
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
// Ignore the kill -2 (SIGINT) signal
// Save N number of numbers
//  The number of numbers are send through coomand line
//  The min number it's 5 the max number its 9
//  Otherwise print an error message
// Define an alarm of 3 seconds
//  If the alarm end's and the user don't gave a number already
//  Hurry up him

const int t = 3;
int i = 0;
int *nums;

void control_alarm(int signal)
{
  printf("Hurry up, Data X(%d): \n", i);
  //scanf("%d", (nums+i)); 
  int res = alarm(t);
}

int main(int argc, char *argv[])
{
  struct sigaction gest;
  int err;

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

  for(i = 0 ; i < atoi(argv[1]); ++i)
  {
    printf("Data X(%d)\n", i);
    scanf("%d", (nums+i)); 
  }
  
  for(i = 0; i < atoi(argv[1]); ++i)
    printf("Number in %d: %d\n", i, *(nums+i));

  free(nums);
  return 0;
}

