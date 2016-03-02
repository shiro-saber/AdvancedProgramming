/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise2.c
* Creation Date : 29-02-2016
*     Last Modified : Tue 01 Mar 2016 11:15:57 PM CST
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
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h> //for DIR
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#define temp 3
#define PATH "Data"
#define ndir 5

// Make a C program, a function will look if in the directory
// had a subdirectory called Data, if not create it, otherwise
// delete all the existing subdirectorys subdirectorys.
// The main program it's in charge of install a control for 
// the signal SIGALRM.
// Then make 5 iterations doing this: 
//   Generate different name for a different subdirectory(a0, a1, etc...)
//   Create a subdirectory of Data with that name.
//   Declare a 3 second tempo
//   Finally write into this subdirectory the character 'x' while a variable write change value to 1
// When the tempo finish declare a variable write to 0
// At the end print name and size of all the created directory's. 
// Cannot use the system function.
// The total number of directory's and the tempo, will be defines.

char *buffer[20];
FILE *file = NULL;
int record = 0;

void control_alarm(int signal)
{
  printf("Signal alarm catched\n");
  record = 0;
}

void erase()
{
  struct dirent *d;
  DIR *dir;
  char buf[256];
  dir = opendir(PATH);
  
  while(d = readdir(dir))
  {
    if(d->d_type == DT_REG)
    {
      printf("Deleting %s\n", d->d_name);
      sprintf(buf, "%s/%s", PATH, d->d_name);
      unlink(buf);
      remove(buf);
    }
  }
}
void exists()
{
  int status;
  DIR *dir = opendir(PATH);
  if (dir) 
  {
    printf("Directory exists\n");
    erase();
    closedir(dir);
  }
  else if(ENOENT == errno)
  {
    printf("Directory doesn't exist\nCreating it...\n");
    mkdir(PATH, 0777);
  }
  else
    printf("opnedir() failed for some othe reason\n");
}

void print()
{
  DIR *dir; 
  dir = opendir(PATH);
  struct dirent *d;
  struct stat s;
  char *path;

  if (dir)
  {
    while (d = readdir(dir))
    {
      if(d->d_type == DT_REG)
      {
        path = (char*)malloc((strlen(path)+strlen(d->d_name)+1)*sizeof(char));
        strcpy(path, "Data/");
        strcat(path, d->d_name);
        stat(path, &s);
        printf("Data/%s Size: %lld Mbyte's\n", d->d_name, (long long)(((s.st_size)/1024)/1024));
      }
    }
    
    closedir(dir);
  }
}

int main(int argc, char *argv[])
{
  int i = 0;

  signal(SIGALRM, SIG_DFL);
  alarm(2);
  signal(SIGALRM, control_alarm);
  exists();

  while(i < ndir)
  {
    printf("Creating file\n");
    int signal;
    record = 1;
    sprintf(buffer, "./Data/a%d", i);
    i++;
    file = fopen(buffer, "w+");
    alarm(temp);
    while(record)
      fputc('x', file);
    fclose(file);
  }
  
  printf("Printing info ...\n\n");
  print();
  printf("\n");
  system("sl -la -F");

  return 0;
}

