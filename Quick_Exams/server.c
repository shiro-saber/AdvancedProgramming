/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : pipes_exam.c
* Creation Date : 14-02-2016
* Last Modified : Mon 15 Feb 2016 11:00:16 AM CST
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
#define N 2

int main(int argc, char *argv[])
{ 
  char a = 'v';
  pid_t pid;
  int **pip;

  if(argc != 2)
  {
    fprintf(stderr, "Syntax: %s <number of <number of process>\n", argv[0]);
    return -1;
  }
  
  *(pip) = (int*)malloc(sizeof(int)*atoi(argv[1]));

  for(int j = 0; j < atoi(argv[1]); ++j)
    *(pip+j) = (int*)malloc(sizeof(int)*N);

  for(int i = 0; i < atoi(argv[1]); ++i)
  {
    pipe(*(pip+i));

    pid=fork();

    if(pid == 0)
    {
      close(*(pip[1]+i));  
      read(*(pip[0]+i), &a, sizeof(char));
      printf("Readind the test: %s, Im process with pid: %d\n", a,getpid());
      /* second pipe */
      close(*(pip[0]+i+1));
      write(*(pip[1]+i+1), &a, sizeof(char)); 
    }
    else if(pid < 0)
    {
      printf("Error creating child\n");
      exit(-1);
    }
    else
    {
      close(*(pip[0]+i));
      write(*(pip[1]+i), &a, sizeof(char));
      /* second pipe */
      close(*(pip[1]+i+1));
      printf("Readind the test: %s, Im process with pid: %d\n", a,getpid());
      read(*(pip[0]+i+1), &a, sizeof(char));
    }
  }
  return 0;
}

