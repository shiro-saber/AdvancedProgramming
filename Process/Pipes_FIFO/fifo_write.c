/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : fifo_write.c
* Creation Date : 08-02-2016
* Last Modified : Sun 14 Feb 2016 09:39:20 PM CST
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
   int error = mkfifo("/home/shiro-saber/Documents/ProgramacionAvanzada/Process/Pipes_FIFO/fifo", 0777);
    
    if (error) {
        printf("Error al crear el FIFO\n");
        exit(-1);
    }
    
    int fd = open("/home/shiro-saber/Documents/ProgramacionAvanzada/Process/Pipes_FIFO/fifo", O_WRONLY);
    
    printf("If you want to exit please enter a number lower than 0\n");

    int num = 0;

    while(num >= 0) 
    {
      scanf("%d", &num);
      write(fd, &num, sizeof(int));
    }

    close(fd);
    unlink("/home/shiro-saber/Documents/ProgramacionAvanzada/Process/Pipes_FIFO/fifo");


  return 0;
}

