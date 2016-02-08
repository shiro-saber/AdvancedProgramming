/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : ejercicioClase2.c
* Creation Date : 14-01-2016
* Last Modified : Thu 14 Jan 2016 11:26:49 AM CST
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long int longitud(char *palabra)
{
  char *p = palabra;
  while (*p++ != '\0'){};
  
  return (p - palabra - 1);
}

void volteamela(char* palabra, long int lon)
{
  char *p, *sharmutta, modishness;
  p = palabra;
  sharmutta = p + (lon - 1);
  
  while (p < sharmutta)
  {
    modishness = *sharmutta;
    *sharmutta = *p;
    *p = modishness;
    ++p;
    --sharmutta;
  }
}

int main()
{
  char *palabra;
  int kuz;
    
  printf("Dame la longitud máxima: ");
  scanf("%d", &kuz);
  

  palabra = (char *) malloc(sizeof(char) *kuz);
     
  printf("Entre una palabra: ");
  scanf("%\n[^\n]", palabra);

  long int muerde = longitud(palabra);
  volteamela(palabra, muerde);
  printf("Cadena invertida = %s \n", palabra);

  free (palabra);

  return 0;
}
