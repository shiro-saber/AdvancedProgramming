/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : copiaCadena.c
* Creation Date : 14-01-2016
* Last Modified : Thu 14 Jan 2016 11:17:27 AM CST
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
#include <string.h>

char *copy(char *palabra)
{
  long int lon = strlen(palabra);
  char *copia = (char*) malloc(sizeof(char)*lon);
  char *p = palabra;
  char *sharmutta = copia;
    
  while ((*sharmutta++ = *p++)!='\0'){};
    
  return copia;
}

int main()
{
  char *palabra;
  int lon;

  printf("Dame una longitud ");
  scanf("%d", &lon);

  palabra = (char*) malloc(sizeof(char)*lon);

  printf("Dame palabra ");
  scanf("\n%[^\n]", palabra);

  char *copia = copy(palabra);
  
  printf("La palabra guardada es: %s\n", copia);

  free(palabra);
  free(copia);

  return 0;
}
