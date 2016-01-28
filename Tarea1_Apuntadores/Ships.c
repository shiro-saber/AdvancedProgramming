/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : Ships.c
* Creation Date : 21-01-2016
* Last Modified : Wed 27 Jan 2016 10:25:08 PM CST
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
#define N 5

/* Make a program that store tripulants and ships
 * and assign a tripulant to a ship. */

int i = 0;

/* TYPEDEFS */
typedef struct
{
  int edad;
  char *nombreT;
  char *apellidoT;
  char *rol;
  int status;

} Tripulant;

typedef struct
{
  char *nombreS;
  float eslora;
  float manga;
  int max;
  int occuped;
  int occuped2;
  Tripulant *propietario;
  Tripulant *tripulacion;

}Ship;

typedef void(*menu)(Ship*, int);
typedef void(*menu2)(Tripulant*, int);
typedef void(*menu3)(Ship*, Tripulant*, int, int);
/* FIN TYPEDEFS */

/* FUNCIONES */
void add_tripulant(Tripulant *t, int kuz)
{
  (t+kuz)->nombreT = malloc(sizeof(char)*10);//assign space for the name array
  printf("Tell me the tripulant name\n");
  scanf("%s", (t+kuz)->nombreT);
  (t+kuz)->apellidoT = malloc(sizeof(char)*10);//assign space for the last name array
  printf("Tell me the tripulant's last name\n");
  scanf("%s", (t+kuz)->apellidoT);
  printf("Tell me the tripulant's age\n");
  scanf("%d", &(t+kuz)->edad);
  (t+kuz)->rol = malloc(sizeof(char)*10);//assign space for the rol array
  printf("Tell me the tripulant's rol\n");
  scanf("%s", (t+kuz)->rol);
}

void add_ship(Ship *s, int kuzemac)
{
  int azzakari;

  (s+kuzemac)->nombreS = malloc(sizeof(char)*10);//assign space for the name array
  printf("Tell me the ship name\n");
  scanf("%s", (s+kuzemac)->nombreS);
  printf("Tell me the length\n");
  scanf("%f", &(s+kuzemac)->eslora);
  printf("Tell me the sleeve\n");
  scanf("%f", &(s+kuzemac)->manga);
  printf("Tell me the max size\n");
  (s+kuzemac)->propietario = malloc(sizeof(Ship)*1);
  (s+kuzemac)->propietario->nombreT = malloc(sizeof(char)*10);
  scanf("%d", &(s+kuzemac)->max);
  azzakari = (s+kuzemac)->max;
  (s+kuzemac)->tripulacion = malloc(sizeof(Ship)*(azzakari));
}

void print_ship(Ship *s, int sharmutta)
{
  int quin;
  printf("Displaying Ships's information:\n");
  for(i = 0; i < sharmutta; ++i)
    printf("ID: %d Ship: %s\tHeight: %.2f\tSleeve: %.2f\tPlaces Remining: %d\n", i+1, (s+i)->nombreS, (s+i)->eslora, (s+i)->manga, ((s+i)->max - (s+i)->occuped2));
}

void rel_ship_tripulant(Ship *s, Tripulant *t, int kitzune, int modishness)
{
  int filahiana = 0; // ship id
  int mucha = 0; // tripulant id
  int option = 0;

  if(kitzune > 0)
  {
    printf("You want to add:\n1. Owner\n2. Tripulant\n");
    scanf("%d", &option);
    if(option == 1)
    {
      printf("Add the owner to what ship?\n");
      print_ship(s, kitzune);
      printf("Tell me the ship ID\n");
      scanf("%d", &filahiana);
      filahiana--;
      for(i = 0; i < modishness; ++i)
        if((t+i)->status == 0 && strcmp((t+i)->rol, ("owner")) == 0)
          printf("ID:%d\tOwner:%s %s\tAge:%d years\n", (i+1), (t+i)->nombreT, (t+i)->apellidoT, (t+i)->edad);

      if(modishness > 0)
      {
        printf("Tell me the owner id\n");
        scanf("%d", &mucha);
        mucha--;
        (t+mucha)->status = 1;
        *((s+filahiana)->propietario+(s+filahiana)->occuped2) = *(t+mucha);
        (s+filahiana)->occuped++;
      }
      else
        printf("There is no owners\n");
    }// end if option 1
    else if(option == 2)
    {
      printf("Add the tripulant to what ship?\n");
      print_ship(s, kitzune);
      printf("Tell me the ships id");
      scanf("%d", &filahiana);
      filahiana--;
      if((s+filahiana)->occuped < (s+filahiana)->max)
      {
        printf("Tripulants: \n");
        for(i = 0; i < modishness; ++i)
          if((t+i)->status == 0 && strcmp((t+i)->rol,("owner")) != 0)
            printf("ID:%d\tName:%s %s\tAge:%d years\n", (i+1), (t+i)->nombreT, (t+i)->apellidoT, (t+i)->edad);

        if(modishness > 0)
        {
          printf("Give me tripulant's id:\n");
          scanf("%d", &mucha);
          mucha--;
          (t+mucha)->status = 1;
          *((s+filahiana)->tripulacion + (s+filahiana)->occuped) = *(t+mucha);
          (s+filahiana)->occuped2++;
        }
        else
          printf("There are no tripulants yet\n");
      }
      else
        printf("There's no more space in this ship\n");
      }
    }
    else
      printf("There are no ships yet\n");
}

void print_tripulation(Ship *s, Tripulant *t, int allah, int uakbar)
{
  int j = 0;
  printf("Displaying Tripulation and Ships Info:\n");

  for(i = 0; i < allah; ++i)
  {
    printf("ID:%d Ship:%s\tHeight: %f\tSleeve: %f\tPlaces Remining: %d\n", i+1, (s+i)->nombreS, (s+i)->eslora, (s+i)->manga, (((s+i)->max)-((s+i)->occuped2)));

    for(j = 0; j < (s+i)->occuped2; ++j)
      if((s+i)->propietario->status == 1)
        printf("Owner:%s %s\tAge: %d years", ((s+i)->propietario)->nombreT, ((s+i)->propietario)->apellidoT, ((s+i)->propietario)->edad);

    for(j = 0; j < (s+i)->occuped; ++j)
      if((s+i)->tripulacion->status == 1)
        printf("Tripulant:%s %s\tAge:%d years\tRole:%s\n", ((s+i)->tripulacion+j)->nombreT, ((s+i)->tripulacion+j)->apellidoT, ((s+i)->tripulacion+j)->edad, ((s+i)->tripulacion+j)->rol);
  }
}
void boom(Ship *s, Tripulant *t, int crepitus, int eksplozja)
{
  Ship *tenetene; //ship counter, free one by one
  Tripulant *faraj; //tripulant counter, free one by one
  Ship *fivaviana = s+crepitus; //final ship
  Tripulant *ikpu = t+eksplozja; //final tripulant
  int p = 0; int l = 0;
  i = 0;

  for(tenetene = s; tenetene < fivaviana; ++tenetene)
  {
    i++;
    free(tenetene->propietario);
    tenetene->propietario = NULL;
    free(tenetene->nombreS);
    tenetene->nombreS = NULL;
    free(tenetene->tripulacion);
    tenetene->tripulacion = NULL;
  } //end of ship delete for

  printf("%d # of ships deleted\n", i);
  i = 0;

  for(faraj = t; faraj < ikpu; ++faraj)
  {
    i++;
    free(faraj->nombreT);
    faraj->nombreT = NULL;
    free(faraj->apellidoT);
    faraj->apellidoT = NULL;
    free(faraj->rol);
    faraj->rol = NULL;
  } //end of tripulation delete for

  printf("%d # of Tripulants deleted\n", i);

  free(s);
  free(t);
}
/* FIN FUNCTIONS*/

int main()
{
  /* definicion de menus */
  menu *uno = ((menu*)malloc(N*sizeof(menu)));
  menu2 *dos = ((menu2*)malloc(N*sizeof(menu2)));
  menu3 *tres = ((menu3*)malloc(N*sizeof(menu3)));

  *(uno) = add_ship;
  *(dos+1) = add_tripulant;
  *(tres+2) = rel_ship_tripulant;
  *(tres+3) = print_tripulation;
  *(tres+4) = boom;
  /* final de definicion de menus*/

  int varpa = 0; //ship size
  int zakar = 0; //tripulation size
  int option = -1;

  Ship *s;
  Tripulant *t;

  s = (Ship*)malloc(1*sizeof(Ship));
  t = (Tripulant*)malloc(1*sizeof(Tripulant));

  while (option != 5)
  {
    printf("Opciones: \n1. Add a ship\n2. Add a tripulant\n3. Add tripulant to ship\n4. Print tripulation\n5. Exit\nChoose an option\n");
    scanf("%d", &option);
    if(option == 1)
    {
      s = (Ship*)realloc(s, (varpa+1)*sizeof(Ship));//assign more memory for the ships
      (*(uno+option-1))(s, varpa);//call's the function
      varpa++; //+1 the size of the ships
    }
    else if(option == 2)
    {
      t = (Tripulant*)realloc(t, (zakar+1)*sizeof(Tripulant));//assign more memory for tripulants
      (*(dos+option-1))(t, zakar);//call's the function
      zakar++;//+1 size of tripulant
    }
    else if(option > 5)
      printf("No es opcion ¬¬\n");
    else
      (*(tres+option-1))(s, t, varpa, zakar);//call the function that the user select
  }

  free(uno);
  free(dos);
  free(tres);
  return 0;
}
