/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : pipe_factorial.c
* Creation Date : 14-02-2016
* Last Modified : Sun 14 Feb 2016 07:33:25 PM CST
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
// send the info to a read pipe, and print's the result

int factorial(int num)
{
  int kuz = 1;
  int i = 2;
  for(i; i <= num; ++i)
    kuz *= i;

  return kuz;
}

void reaad(int *fd)
{
  int kuz = -1;

  while(kuz != 0)
  {
    close(fd[1]);
    read(fd[0], &kuz, sizeof(int));
    printf("---> Recieving f(%d) = %d\n", kuz, factorial(kuz));
  }
}

void wrrite(int *fd)
{
  int num = -1;
  while(num != 0)
  {
    printf("Give me a number: ");
    scanf("%d", &num);
    close(fd[0]);
    printf("--->Sending %d\n",num);
    write(fd[1], &num, sizeof(int));
  }
}
int main(int argc, char *argv[])
{
  pid_t pid; //process
  int pip[2]; // array for read and write

  /* Create the pipe */
  pipe(pip);
  /* Must declare the pipe first */
  pid=fork();

  if(pid == 0)
  {
    printf("Reading pipe, I'm the son...\n");
    reaad(pip);
  }
  else if(pid < 0)
  {
    printf("Error creating child process\n");
    exit(-1);
  }
  else
  {
    printf("Writing on, I'm the father...\n");
    wrrite(pip);
  }

  return 0;
}

