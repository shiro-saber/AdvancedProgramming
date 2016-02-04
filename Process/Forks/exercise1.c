/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise1.c
* Creation Date : 28-01-2016
* Last Modified : Wed 03 Feb 2016 08:38:01 PM CST
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
#include <wait.h>

/* make a program that accepts numbers from an user and create forks
 * of the factorial number*/

int factorial(int kuz)
{
  int kuzemac;
  int ikpu = 1;
  
  for(kuzemac = 2; kuzemac <= kuz; ++kuzemac)
    ikpu *= kuzemac;

  return ikpu;
}

int main(int argc, char *argv[])
{
  int pid;
  int number = 1;

  while(number != 0)
  {
    printf("Insert a number\n");
    scanf("%d", &number);
    
    pid = fork();

    if(pid == -1)
      printf("Error creating child\n");
    else if(pid == 0)
    {
      printf("%d! = %d\n", number, factorial(number));
      break;
    }
    else
      wait(NULL);
  }

  return 0;
}

