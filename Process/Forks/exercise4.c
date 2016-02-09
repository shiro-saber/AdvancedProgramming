/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise4.c
* Creation Date : 04-02-2016
* Last Modified : Tue 09 Feb 2016 02:52:55 PM CST
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
#include <sys/wait.h>
#include <sys/types.h>

static void wait_for_kids(void)
{
    int corpse;
    int status;
    while ((corpse = wait(&status)) > 0)
        /* printf("Child %d exited with status 0x%.4X\n", corpse, status); */
        ;
}

int main(int argc, char *argv[])
{
    pid_t child;
    int j, k;

    if (argc != 3)
    {
        fprintf(stderr, "Syntax: %s <number of levels> <number of process in each level>\n", argv[0]);
        return -1;
    }
    int lvl = atoi(argv[1]);
    int proc = atoi(argv[2]);

    printf("%s %d %d\n", argv[0], lvl, proc);

    for (k = 0; k < lvl; k++)
    {
        child = fork();

        if (child < 0)
        {
            printf("Error creating child\n");
            exit(1);
        }
        else if (child == 0)
        {
            printf("--->%d\n", (int)getpid());
            for (j = 0; j < proc; j++)
            {
                child = fork();
                if (child < 0)
                {
                    printf("Error creating child\n");
                    exit(1);
                }
                else if (child == 0)
                {
                    printf("    --->%d\n", (int)getpid());
                    exit(0);
                }
                wait_for_kids();
            }
            exit(0);
        }
        wait_for_kids();
    }

    return 0;
}
