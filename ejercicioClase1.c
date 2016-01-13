/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.c
* Creation Date : 11-01-2016
* Last Modified : Tue 12 Jan 2016 09:17:08 PM CST
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

#define kuz 5

int i=0;

typedef struct
{
    char *nombre;
    char *apellido;
    int edad;
}Persona;

void agregarPersona(Persona *p, int a) //para agregar personas al arreglo
{
  (p+a)->nombre = malloc(sizeof(char)*10);
  printf("Dame el nombre: \n");
  scanf("%s",(p+a)->nombre);

  (p+a)->apellido = malloc(sizeof(char)*10);
  printf("Dame el apellido: \n");
  scanf("%s",(p+a)->apellido);

  printf("Dame la edad: \n");
  scanf("%d",&(p+a)->edad);
}


void limpiar(Persona*p, int c) //para no tener memory leaks
{
  Persona *aux;
  Persona *final=p+c;
  i=0;

  for (aux = p; aux < final; ++aux) //vamos limpiando uno por uno el arreglos
  {
    i++;
    free(aux->nombre);
    aux->nombre=NULL;
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
  int sharmutta = -1; //la opcion de cases

  //sección del arreglo dinámico
  p = (Persona*)malloc(1*sizeof(Persona));

  while(sharmutta != 5)
  {
    printf("Menu\n   1. Agregar Persona\n   2. Promedio\n   3. Entre edades\n   4. El mas viejo\n   5. Salir\n");
    scanf("%d", &sharmutta);
    
    if(sharmutta == 1)
    {
      p = (Persona*)realloc(p, (tamP+1) * sizeof(Persona));
      agregarPersona(p, tamP);
      tamP++;
      printf("%s %s %d agregado correctamente\n", p->nombre, p->apellido, p->edad);
    }

    /*sección de promedio de edad, entre edades y el más viejo */
    else if(sharmutta == 2)
    {
      //promedio de edad
      int promedio;

      for(i = 0; i < tamP; ++i)
        //printf("%s %s %d leido correctamente\n", (p+i)->nombre, (p+i)->apellido, (p+i)->edad);
        promedio += (p+i)->edad;

      promedio = promedio/i;
      printf("El promedio de edad es %d\n", promedio);
    }
    else if(sharmutta == 3)
    {
      //entre edades
    }
    else if(sharmutta == 4)
    {
      //el más viejo
      Persona *res;

      for (i = 0; i < tamP; ++i)
      {
        if(i+1 != tamP && (p+i)->edad < (p+i+1)->edad && tamP != 1)
          res = (p+i);
      }
      printf("La persona mas vieja es %s %s %d\n", res->nombre, res->apellido, res->edad);
      free(res);
    }
    else if(sharmutta == 5)
    {
      printf("BYE!\n");
    }
    else
      printf("No es opcion ¬¬\n");
  }

  limpiar(p,tamP);//no memory leaks
  return 0;
}
