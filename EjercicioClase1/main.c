/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.c
* Creation Date : 11-01-2016
* Last Modified : Mon 11 Jan 2016 11:30:35 PM CST
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

int i=0;

typedef struct 
{
    char *nombre;
    char *apellido;
    int edad;
}Persona;

void agregarPersona(Persona *p, int a) //para agregar personas al arreglo
{
  (p+a)->nombreP = malloc(sizeof(char)*10);
  printf("Dame el nombre: ");
  scanf("%s",(p+a)->nombreP);

  (p+a)->apellido = malloc(sizeof(char)*10);
  printf("Dame el apellido: ");
  scanf("%s",(p+a)->apellido);	  
  
  printf("Dame la edad: ");
  scanf("%d",&(p+a)->edad);
}


void limpiar(Persona*p, int c) //para no tener memory leaks
{
  Persona *aux;
  Persona *final=p+c;
  i=0;

  for (aux = p; aux < final; ++aux) //vamos limpiando uno por uno los arreglos
  {
    i++;
    free(aux->nombreP);
    aux->nombreP=NULL;
    free(aux->apellido);
    aux->apellido=NULL;
  }
  
  printf("Borre %d Personas\n", i);

  free(p);
}

int main()
{
  Persona *p;
  int tamP = 0;//tamaño del arreglo dinámico

  //sección del arreglo dinámico
  p = (Persona*)malloc(1*sizeof(Persona));
  p = (Persona*)realloc(p, (tamP+1) * sizeof(Persona));
  
  agregarPersona(p, tamP);
  tamP++;
  
  /*sección de promedio de edad, entre edades y el más viejo
   
   */

  /*sección de imprimir

  */

  limpiar(p,tamP);//no memory leaks
  return 0;
}
