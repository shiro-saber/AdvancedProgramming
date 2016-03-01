/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : exercise2.c
* Creation Date : 29-02-2016
* Last Modified : Mon 29 Feb 2016 09:45:02 PM CST
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
#include <dirent.h>
#include <ftw.h>
#define temp 10
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

int directory(char *d)
{
  DIR *dirptr;
  if (access ( d, F_OK ) != -1 ) 
  {
    // file exists
    if ((dirptr = opendir (d)) != NULL) 
      closedir (dirptr);
    else 
      return -2; /* d exists, but not dir */
  }
  else 
    return -1; /* d does not exist */

  return 1;
}

int main(int argc, char *argv[])
{
  if(directory("./Data") == -1)
    mkdir("./Data", S_IRWXU|S_IRWXG|S_IRWXO);
  else
  {
    
  }

  return 0;
}

