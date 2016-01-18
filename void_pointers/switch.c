/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : switch.c
* Creation Date : 18-01-2016
* Last Modified : Mon 18 Jan 2016 10:42:29 AM CST
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

#define N 3

/*Make a switch case with void pointers*/

void opcion1()
{
  printf("Seleccionaste opcion 1\n");
}

void opcion2()
{
 printf("Seleccionaste opcion 2\n");
}

void opcion3()
{
 printf("Seleccionaste opcion 3\n");
}

typedef void(*menu)(); //defines el tipo de dato,todos los void que no tengan parametros, pertenecen a este tipo de dato 

int main()
{
  int option = -1;
  
  menu *m =(menu*) malloc(N * sizeof(menu));//reservas memoria para el menú, para que sea dinámico
  
  *m = opcion1;
  *(m+1) = opcion2;
  *(m+2) = opcion3;

  while(option != 0)
  {
    printf("Menu:\n1. Opcion1\n2. Opcion2\n3. Opcion 3\n0. Salir\nSelecciona una opción\n");
    
    scanf("%d", &option);

    if (option <= N && option >= 0)
      m[option-1]();
    else
      printf("No es opcion\n");
  }
  
  free(m);
  return 0;
}
