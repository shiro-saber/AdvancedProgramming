/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise4.c
* Creation Date : 04-02-2016
* Last Modified : Fri 05 Feb 2016 08:12:38 PM CST
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

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    printf("Syntax: ./pstree <number of levels> <number of process in each level>\n");
    
    return -1;
  }
  
  for(int i = 0; i < atoi(argv[1]); i++)
  {
    //int left_child = fork();
    
    //if(left_child != 0)        //we are the parent
    //{
      for(int j = 0; j < atoi(argv[2]); j++)
      {
        int right_child = fork();
        
        if(right_child == 0)
        {
          for(int k = 0; k < i; k++)
            printf("   ");

          printf("--->%d\n", getpid());
          exit(0);
        }
      }
    //}
    //else
    //{
      //printf("--->%d\n", getpid());
    //} 
  }

  return 0;
}

