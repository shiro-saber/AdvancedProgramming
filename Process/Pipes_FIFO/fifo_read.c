/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : fifo_read.c
* Creation Date : 08-02-2016
* Last Modified : Mon 15 Feb 2016 01:47:19 AM CST
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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  int fd;
  int leidos = 1;
    
  fd = open("/home/shiro-saber/Documents/ProgramacionAvanzada/Process/Pipes_FIFO/fifo", O_RDONLY);
    
  int i = -1; 

  while (leidos = read(fd, &i, sizeof(int))) 
  {
    if(i >= 0)
    {
      int j = 2;
      int f = 1;
  
      for(j; j <= i; ++j)
        f *= j;

      printf("%d! it's: %d\n", i, f);    
    }
  }

  close(fd); 

  return 0;
}

