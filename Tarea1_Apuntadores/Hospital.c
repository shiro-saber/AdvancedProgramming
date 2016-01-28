/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : Hospital.c
* Creation Date : 21-01-2016
* Last Modified : Wed 27 Jan 2016 07:58:15 PM CST
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
#define N 7

/* Make a program that store pacients in a hospital, as many as they
 * need, if you need more bed's you need to add it, but the bed's can
 * only increase from 5 to 5. */

int i = 0;

/* TYPEDEFS */
typedef struct
{
  char *nameP;//name of the pacient
  char *lastP;
  int age;
  char *telephone;
}Pacient;

typedef struct
{
  Pacient *pacient;
  int status; 
  char *status2;
}Hospital;

typedef void(*tutzke) (Hospital*, Pacient*, int, int);//void pointers for the menus

/* FIN TYPEDEFS */

/* FUNCTIONS */
int count_available_beds(Hospital *h, int kuz)
{
  int ikpu = 0;
  for(i = 0; i < kuz; ++i)
    if((h+i)->status == 0)
      ikpu++;
  
  return ikpu;
}

int count_ocupped_beds(Hospital *h, int kuz)
{
  int ikpu = 0;
  for(i = 0; i < kuz; ++i)
    if((h+i)->status==1)
      ikpu++;

  return ikpu;
}

void print_bed_oc(Hospital *h, int kuz)//occuped
{
  printf("Displaying occuped beds info: \n");
  for(i = 0; i < kuz; ++i)
  {
    if((h+i)->status == 1)
    {
      printf("Bed #%d Status:%s\n", i+1, (h+i)->status2);
      printf("Pacient:%s %s\tAge%d\tTelephone:%s\n", (h+i)->pacient->nameP, (h+i)->pacient->lastP, (h+i)->pacient->age, (h+i)->pacient->telephone);
    }
  }
}

void print_bed(Hospital *h, Pacient *p, int kuz, int kitzune)//availables
{
  int ikpu = 0;

  printf("Displaying available beds info\n");
  for(i = 0; i < kuz; ++i)
    if((h+i)->status == 0)
      printf("ID:%d Status:%s\n", i+1, (h+i)->status2);
}

void print_beds(Hospital *h, Pacient *p, int kuz, int kitzune)
{
  int ikpu = 0;

  printf("Displaying beds info\n");
  for(i = 0; i < kuz; ++i)
  {
    printf("ID:%d Status:%s\n", i+1, (h+i)->status2);
    if((h+i)->status == 1)
     printf("Pacient:%s %s\tAge:%d\tTelephone:%s\tBed:%d\n", (h+i)->pacient->nameP, (h+i)->pacient->lastP, (h+i)->pacient->age, (h+i)->pacient->telephone, i+1);
  }
}

void print_pacients(Hospital *h, Pacient *p, int kuz, int kitzune)
{
  printf ("Displaying Pacients:\n");
  for(i = 0; i < kuz; ++i)
    if((h+i)->status == 1)
      printf("Pacient:%s %s\tAge:%d\tTelephone:%s\tBed:%d\n", (h+i)->pacient->nameP, (h+i)->pacient->lastP, (h+i)->pacient->age, (h+i)->pacient->telephone, i+1);
}

void add_Pacient(Hospital *h, Pacient *p, int kuz, int kitzune)
{
  int azzakari;//bed id given from the user
  (p+kitzune)->nameP = malloc(sizeof(char)*10); //assign memory for the name
  printf("Give me the name\n");
  scanf("%s", (p+kitzune)->nameP);
  (p+kitzune)->lastP = malloc(sizeof(char)*10);//assign memory for the last name
  printf("Give me the last name\n");
  scanf("%s", (p+kitzune)->lastP);
  printf("Give me the age\n");
  scanf("%d", &(p+kitzune)->age);
  (p+kitzune)->telephone = malloc(sizeof(char)*10);//assign memory for the telephone
  printf("Give me the pacient telephone\n");
  scanf("%s", (p+kitzune)->telephone);

  int available = 1;
  while(available != 0)
  {
    print_bed(h, p, kuz, kitzune);
    printf("In what bed you want to put him\n");
    scanf("%d", &azzakari);
    printf("Your choose bed: %d\n", azzakari);
    azzakari--;//one less because the "array"
    if(azzakari <= kuz && (h+azzakari)->status == 0)
    {
      (h+azzakari)->pacient = malloc(sizeof(Pacient)*5);//assign memory in hospital for the pacient
      *(h+azzakari)->pacient = *(p+kitzune);
      (h+azzakari)->status = 1;
      if((h+azzakari)->status == 1)
      {
        (h+azzakari)->status2 = ("ocupped");
        available = 0;
      }
    }//end of if azzakari
    else
      printf("Option not available\n");
  }//end of while available
}

void discharge_pacient(Hospital *h, Pacient *p, int kuz, int kitzune)
{
  int available = 1;
  int azzakari = 0;
  
  if(count_ocupped_beds(h, kuz) > 0)
  {
    while(available != 0)
    {
      print_bed_oc(h, kuz);
      printf("Give me the bed you want to discharge\n");
      scanf("%d", &azzakari);
      printf("You pick the bed with number %d\n", azzakari);
      azzakari--;
      if(azzakari <= kuz && (h+azzakari)->status==1)
      {
        (h+azzakari)->status = 0;
        if((h+azzakari)->status == 0)
        {
          (h+azzakari)->status2 = ("Pacient with medical discharge (available)");
          available = 0;
        }//end of hospital status if
      }//end azzakari if
      else
        printf("This function it's not available\n");
    }//end while
  }
  else
    printf("No pacients for the medical discharge\n");
}
void boom(Hospital *h, Pacient *p, int allah, int uakbar)
{
  Hospital *sharmutta;
  Hospital *kuzemac = h+allah;
  Pacient *beeg;
  Pacient *lagrimasAlumnos = p+uakbar;

  i = 0;
  for(sharmutta = h; sharmutta < kuzemac; ++sharmutta)
  {
    i++;
    free(sharmutta->pacient);
  }
  printf("I delete %d beds in hospital\n", i);

  i = 0;
  for(beeg = p; beeg < lagrimasAlumnos; ++beeg)
  {
    i++;
    free(beeg->nameP);
    free(beeg->lastP);
    free(beeg->telephone);
  }
  printf("I delete %d, pacients\n", i);

  free(h);
  free(p);
}
/* FIN FUNCTIONS */

int main()
{
  tutzke *menu = ((tutzke*)malloc(N*sizeof(tutzke)));
  int pain = 0;//tamH
  int suffer = 0;//tamP

  *(menu) = add_Pacient;
  *(menu+1) = discharge_pacient;
  *(menu+2) = print_bed;
  *(menu+3) = print_beds;
  *(menu+4) = print_pacients;
  *(menu+5) = boom;

  int option = -1;
  int beds = 5;

  Pacient *p;
  Hospital *h;

  h = (Hospital *)malloc(5*sizeof(Hospital));
  p = (Pacient *)malloc(1*sizeof(Pacient));

  while(option != 6)
  {
    printf("Menu:\n1. Add Pacient\n2. Discharge pacient\n3. Print available beds\n4. Print all\n5. Print pacients\n6. Exit\nSelect your option\n");
    scanf("%d", &option);
    if(option == 1)
    {
      if(count_available_beds(h, beds)==0)
      {
        h = (Hospital*)realloc(h, (beds+5)*sizeof(Hospital));
        printf("More beds added\n");
        beds += 5;
      }

      p = (Pacient*)realloc(p, (suffer+1)*sizeof(Pacient));
      (*(menu+option-1))(h, p, beds, suffer);
      pain++;
      suffer++;
    }
    else
      (*(menu+option-1))(h, p, beds, suffer);
  }

  free(menu);
  printf("Gracias por la tortura cubells :)\n");
  return 0;
} //dolor!
