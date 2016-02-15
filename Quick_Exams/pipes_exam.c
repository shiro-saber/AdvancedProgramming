/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : pipes_exam.c
* Creation Date : 14-02-2016
* Last Modified : Sun 14 Feb 2016 08:14:32 PM CST
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

void reaad()
{

}

void wrrite()
{
  
}

int main(int argc, char *argv[])
{ 
  pid_t pid;
  int pip[2];
  
  pipe(pip);

  pid=fork();

  if(pid == 0)
  {

  }
  else if(pid < 0)
  {
    printf("Error creating child\n");
    exit(-1);
  }
  else
  {

  }

  return 0;
}

