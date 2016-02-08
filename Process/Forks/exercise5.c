/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise5.c
* Creation Date : 05-02-2016
* Last Modified : Mon 08 Feb 2016 05:26:35 AM CST
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

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <getopt.h>
#include <wait.h>

int main (int argc, char *argv[])
{
  pid_t pid;
  char *cvalue;
  char *aflag;
  int index, status;
  int c;

  opterr = 0;
  while ((c = getopt (argc, argv, ":n:p:")) != -1)
    switch (c)
      {
      case 'n':
        aflag = optarg;
        break;
      case 'p':
        cvalue = optarg;
        break;
      case '?':
        if (optopt == 'p')
          fprintf (stderr, "Option -%p requires an argument.\n", optopt);
        else if (optopt == 'n')
          fprintf(stderr, "Option -%n requires an argument,\n",optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
        return 1;
      
      default:
        abort ();
      }
  printf ("aflag = %s, cvalue = %s\n", aflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
 
  for(int i = 0; i < atoi(aflag); i++)
  {
    pid = fork();
    if(pid == -1)
      printf("Error creating child");
    else if(pid == 0)
    {
      printf("Child with pid: %d", getpid());
      execvp(cvalue,NULL);
      wait(NULL);
    }
    else
    {
     if((waitpid(pid, &status, 0) != -1))
        if(WIFEXITED(status))
          printf("Child finish with pid: %d\n", pid); 
    }
  }

  return 0;
}

