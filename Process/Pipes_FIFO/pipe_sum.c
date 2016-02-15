/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : pipe_sum.c
* Creation Date : 14-02-2016
* Last Modified : Sun 14 Feb 2016 08:40:37 PM CST
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

void reaad(int *fd)
{
  int num = -1;
  int sum = 0;

  while(num != 0)
  {
    close(fd[1]);
    read(fd[0], &num, sizeof(int));
    printf("-->Reading f(%d)\n", num);
    sum += num;
  }

  printf("The addition it's: %d\n", sum);
}

void wrrite(int *fd)
{
  int num = -1;

  while(num != 0)
  {
    printf("Give me a number: ");
    scanf("%d", &num);
    close(fd[0]);
    printf("-->Sending %d\n", num);
    write(fd[1], &num, sizeof(int));
  }
}

int main(int argc, char *argv[])
{
  pid_t pid;
  int pip[2];

  pipe(pip);

  pid = fork();

  if(pid == 0)
  {
    printf("-->Reading Pipe, Son here\n");
    reaad(pip);
  }
  else if(pid < 0)
  {
    printf("Error creating child\n");
    exit(-1);
  }
  else
  {
    printf("-->Writing in the pipe, Dad here\n");
    wrrite(pip);
  }

  return 0;
}

