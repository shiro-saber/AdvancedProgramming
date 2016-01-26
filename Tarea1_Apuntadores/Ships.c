/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : Ships.c
* Creation Date : 21-01-2016
* Last Modified : Mon 25 Jan 2016 09:12:02 PM CST
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
    printf("ID: %d Ship: %s\t%.2f\t%.2f\tPlaces Remining: %d\n", i+1, (s+i)->nombreS, (s+i)->eslora, (s+i)->manga, ((s+i)->max - (s+i)->occuped));
}

void rel_ship_tripulant(Ship *s, Tripulant *t, int kitzune, int modishness)
{
  int filahiana = 0; // ship id
  int mucha; // tripulant id
  int option = 0;

  if(kitzune > 0)
  {
    printf("You want to add an:\n1. Owner\n2. Tripulant\n");
    scanf("%d", &option);

    if(option == 1)
    {
      printf("To what ship you want an owner\n");
      print_ship(s, kitzune);
      printf("Tell me the ship id\n");
      scanf("%d", &filahiana);
      filahiana--;

      for(i = 0; i < modishness; ++i)
        if((t+i)->status == 0 && strcmp((t+i)->rol,("propietario")) == 0)
          printf("ID - %d\t%s\t%s\t%d\t%s\t%d\n",(i+1),(t+i)->nombreT,(t+i)->apellidoT,(t+i)->edad,(t+i)->rol,(t+i)->status);

      if(modishness > 0)
      {
        printf("Give me the tripulant id\n");
        scanf("%d", &mucha);
        mucha--;
        (t+mucha)->status = 1;
        *((s+filahiana)->propietario+(s+filahiana)->occuped2) = (*(t+mucha));
        (s+filahiana)->occuped2++;
       // printf("There are %d tripulants\n", (s+filahiana)->occuped2);
      } //end of modishness if
      else
        printf("There are no tripulants yet.\n");
    }//end of option 1 if
    else
    {
      printf("To what ship you want to add a tripulant?\n");
      print_ship(s, kitzune);
      printf("Tell me the ship's id \n");
      scanf("%d", &filahiana);
      filahiana--;
      
      if((s+filahiana)->occuped < (s+filahiana)->max)
      {
        printf("Tripulantes\n");
        for(i = 0; i < modishness; ++i)
          if((t+i)->status == 0 && strcmp((t+i)->rol, ("propietario"))!= 0)
            printf("ID - %d\t%s\t%s\t%d\t%s\t%d\n", (i+1), (t+i)->nombreT, (t+i)->apellidoT, (t+i)->edad, (t+i)->rol, (t+i)->status);
        
        if(modishness > 0)
        {
        printf("Give me the tripulant id\n");
        scanf("%d", &mucha);
        mucha--;
        (t+mucha)->status = 1;
        *((s+filahiana)->propietario+(s+filahiana)->occuped2) = (*(t+mucha));
        (s+filahiana)->occuped2++;
        printf("There are %d tripulants\n", (s+filahiana)->occuped2);
        } //end of modishness if
      else
        printf("There are no tripulants yet.\n");
      }//cierre if max
      else
        printf("There's no remaining space on the ship\n");
    }//cierre del else
  }// end of kitzune's if
  else
    printf("There's no ship in the port yet\n");
}

void print_tripulation(Ship *s, Tripulant *t, int allah, int uakbar)
{
  int k = 0;
  printf("Displaying Ship Tripulation Info:\n");
  
  for(i = 0; i < allah; ++i)
  {
    printf("ID: %d Ship: %s\tLenght: %.2f\tSleeve: %.2f\tPlaces Remining: %d\n", i+1, (s+i)->nombreS, (s+i)->eslora, (s+i)->manga, ((s+i)->max - (s+i)->occuped));

    for(k = 0; k < (s+i)->occuped2; ++k)
      if((s+i)->propietario->status == 1)
        printf("Tripulant:\n%s\t%s\tEdad: %daños\tRol: %s\t%d\n", ((s+i)->tripulacion+k)->nombreT, ((s+i)->tripulacion+k)->apellidoT, ((s+i)->tripulacion+k)->edad, ((s+i)->tripulacion+k)->rol, ((s+i)->tripulacion+k)->status);

    for(k = 0; (s+i)->occuped; ++k)
      if((s+i)->tripulacion->status == 1)
        printf("Tripulant:\n%s\t%s\tEdad: %daños\tRol: %s\t%d\n", ((s+i)->tripulacion+k)->nombreT, ((s+i)->tripulacion+k)->apellidoT, ((s+i)->tripulacion+k)->edad, ((s+i)->tripulacion+k)->rol, ((s+i)->tripulacion+k)->status);
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

  printf("#%d of ships deleted\n");
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

  printf("#%d of Tripulants deleted\n");

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

