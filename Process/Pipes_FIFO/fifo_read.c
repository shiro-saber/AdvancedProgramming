/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : fifo_read.c
* Creation Date : 08-02-2016
* Last Modified : Mon 08 Feb 2016 11:26:34 AM CST
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
    
  fd = open("/home/shiro-saber/Documents/ProgramacionAvanzada/Procesos/Pipes_FIFO/", O_RDONLY);
    
  int i = -1;
    
  while (leidos = read(fd, &i, sizeof(int))) 
        printf("%d\n", i);
      
  close(fd); 

  return 0;
}

