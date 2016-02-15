/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : factorial_multipipes.c
* Creation Date : 14-02-2016
* Last Modified : Sun 14 Feb 2016 09:11:18 PM CST
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
#include <sys/types.h>

// Write a program that read number's from terminal, with a pipe
// send the info to a read pipe, calculate factorial and write on 
// other pipe that the father read and print the result
// bidirectional pipes

int factorial(int num)
{
  int kuz = 1;
  int i = 2;
  for(i; i <= num; ++i)
    kuz *= i;

  return kuz;
}

int main(int argc, char *argv[])
{
  pid_t pid; //process
  int pip[2]; // array for read and write
  int pip2[2];

  /* Create the pipe */
  pipe(pip);
  pipe(pip2);
  /* Must declare the pipe first */
  pid=fork();

  if(pid == 0)
  {
    close(pip[1]);
    int num;
    read(pip[0], &num, sizeof(int));
    close(pip2[0]);
    int res = factorial(num);
    write(pip2[1], &res, sizeof(int));
  }
  else if(pid < 0)
  {
    printf("Error creating child process\n");
    exit(-1);
  }
  else
  {
    close(pip[0]);
    int num, res;
    printf("Give me a number: ");
    scanf("%d", &num);

    write(pip[1], &num, sizeof(int));
    close(pip2[1]);
    read(pip2[0], &res, sizeof(int));

    printf("The result it's: %d\n", res);
  }

  return 0;
}
