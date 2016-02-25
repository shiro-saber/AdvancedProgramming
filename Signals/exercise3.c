/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise3.c
* Creation Date : 25-02-2016
* Last Modified : Thu 25 Feb 2016 11:12:37 AM CST
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

// Using a handler, catch CTRL+C and CTRL+Z
// the handler had to tell you the signal 
// entered, this in an interval of 10 seconds

void control(int sign)
{
  if(sign == SIGTSTP)
    printf("HA HA can't stop it\n");
  else if(sign == SIGINT)
    printf("HA HA can't kill it\n");
}

int main(int argc, char *argv[])
{ 
  int k = 10;
  
  while (k-- > 0) 
  {
    if(signal(SIGTSTP, control) == SIG_ERR) 
      printf("Not handler\n");

    if(signal(SIGINT, control) == SIG_ERR)
      printf("Not handler\n");

    printf(" +++ %d and counting\n", k);
    sleep(1);
  }

  return 0;
}

