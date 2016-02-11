/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : fifo_write.c
* Creation Date : 08-02-2016
* Last Modified : Mon 08 Feb 2016 11:57:49 AM CST
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
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
   int error = mkfifo("/home/shiro-saber/Documents/ProgramacionAvanzada/Procesos/Pipes_FIFO/", 0777);
    
    if (error) {
        printf("Error al crear el FIFO\n");
        exit(-1);
    }
    
    int fd = open("/home/shiro-saber/Documents/ProgramacionAvanzada/Procesos/Pipes_FIFO/", O_WRONLY);
    
    int i = 0;
    
    while (true) 
    {
        write(fd, &i, sizeof(int));
    }
    
    close(fd);
    unlink("/home/shiro-saber/Documents/ProgramacionAvanzada/Procesos/Pipes_FIFO/");


  return 0;
}

