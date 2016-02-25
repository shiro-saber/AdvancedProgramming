/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise4.c
* Creation Date : 25-02-2016
*   Last Modified : Thu 25 Feb 2016 11:23:03 AM CST
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

void control(int sign)
{
  printf("I'm learning to handle signals\n");
}

void control2(int sign)
{
  printf("Change control\n");
}

int main(int argc, char *argv[])
{
  void (*handler)(int);
  int k = 0; 

  for(k; k < 10; ++k)
  {
    signal(SIGINT, control);
    printf("Sheep %d\n", k);
    sleep(1);
  }

  for(k = 0; k < 10; ++k)
  {
    handler = signal(SIGINT, control2);
    printf("sledge %d\n", k);
    sleep(1);
  }
  
  for(k = 0; k < 10; ++k)
  {
    signal(SIGINT, handler);
    printf("cow's %d\n", k);
    sleep(1);
  }


  return 0;
}

