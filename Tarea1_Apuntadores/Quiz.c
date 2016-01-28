/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : Quiz.c
* Creation Date : 21-01-2016
* Last Modified : Thu 28 Jan 2016 12:24:23 AM CST
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
#include <time.h>
#define N 3
#define M 10
#define R 7

/**/

/* TYPEDEFS*/
typedef struct 
{
  char *name;
  int age;
  int *answers;
}Participant;
/* END TYPEDEFS */

/* FUNCTIONS */
void add_participant(Participant *p, int kuz)
{
  (p+kuz)->name = (char*)malloc(25);
  printf("Give me a name: \n");
  scanf("%s", (p+kuz)->name);
  
  int kitzune;
  while(kitzune > 120 || kitzune < 17)
  {
    printf("Give me your age:\n");
    scanf("%d", &kitzune);
    if(kitzune < 17)
      printf("ERROR! younglink\n");
    else if(kitzune > 120)
      printf("ERROR! a mommy cannot participate\n");
    else
      (p+kuz)->age = kitzune;
  }
  (p+kuz)->answers = (int*)malloc(M*sizeof(int));
}

void add_questions(char ***q, int kuz)
{
  int kuzemac;

  *(q+kuz) = (char**)malloc(R*sizeof(char*));
  *(*(q+kuz)) = (char*)malloc(25);
  printf("Header:\n");
  scanf("%s", *(*(q+kuz)));

  for(kuzemac = 1; kuzemac < R; ++kuzemac)
  {
    printf("Option %d\n", kuzemac);
    *(*(q+kuz)+kuzemac) = (char*)malloc(25);
    scanf("%s", (*(*(q+kuz)+kuzemac)));
  }
}

void enviroment(Participant *p, char ***o)
{
  int beeg;

  printf("Enviroment for quizz\n");
  printf("Creating participants\n");
  
  for(beeg = 0; beeg < N; ++beeg)
    add_participant(p, beeg);
  
  printf("Creating questions\n");

  for(beeg = 0; beeg < M; ++beeg)
    add_questions(o, beeg);

  printf("All done!\n");
}

void answer_question(Participant *p, int kuz, char ***o, int lol)
{
  int sharmutta;

  printf("Question #%d", lol);
  printf("%s\n Possible answers: (0 if you want to skip)\n", *(*(o+lol)));

  for(sharmutta = 1; sharmutta < R; ++sharmutta)
    printf("%d. %s\n", sharmutta, *(*(o+lol)+sharmutta));

  printf("---->");
  scanf("%d", ((p+kuz)->answers+lol));
}

void make_quizz(Participant *p, int zaz,char ***o)
{
  int non;//si se me acabo la imaginacion

  for(non = 0; non < N; ++non)
    answer_question(p, zaz, o, non);
}

void full_quiz(Participant *p, char ***o)
{
  int hate;

  for(hate = 0; hate < N; ++hate)
    make_quizz(p, hate, o);
}

void full_quiz_random(Participant *p, char ***o)
{
  time_t t;
  int no, se;

  for(no = 0; no < N; ++no)
    for(se = 0; se < M; ++se)
      *((p+no)->answers+se) = rand()%6;
}

void answers_history(Participant *p, char ***o)
{
  int no, lo, se;
  int esta = 0;
  int *estas = (int*)malloc(R*sizeof(int));

  for(no = 0; no < R; ++no)
    *(estas+no) = 0;

  printf("RESULTS\nAnswers\n\nQuestion Frecuency\n");

  for(no = 0; no < M; ++no)
  {
    for(lo = 0; lo < N; ++lo)
      esta = ((*(p+lo)->answers+M) == 0) ? esta : esta++;

    printf("  %d  ", no);

    for(lo = 0; lo < esta; ++esta)
      printf("*");
    printf("\n");
    esta = 0;
  }

  printf("\nAnswer Frequency\n");
  for(no = 0; no < M; ++no)
  {
    for(lo = 0; lo < N; ++lo)
      (*(estas+((*(p+lo)->answers+M))))++;

    printf("Question #%d\n", no);
    printf("Frequency answer\n");

    for(lo = 1; lo < R; ++lo)
    {
      printf(" %d  %d  ", lo, *(estas+lo));
      for(se = 0; se < *(estas+lo); ++se)
        printf("*");

      printf("\n");
    }

    for(lo = 0; lo < R; ++lo)
      *(estas+lo) = 0;

    printf("\n");
  }
  free(estas);
}

void ages_history(Participant *p, char ***o)
{
  int *estas = (int*)malloc(5*sizeof(int));
  int no, lo ,se;

  printf("History by ages\n");

  for(no = 0; no < M; ++no)
  {
    printf("Question #%d\n", no);
    printf("No [18-25] [26-35] [36-45] [46-65] [66-120]\n");

    for(lo = 1; lo < R; ++lo)
    {
      for(se = 0; se < N; ++se)
      {
        if(*((p+se)->answers+no) == lo)
        {
          if((p+se)->age < 26)
            *estas = *estas+1;
          else if((p+se)->age < 36)
            *(estas+1) = *(estas+1)+1;
          else if((p+se)->age < 46)
            *(estas+2) = *(estas+2)+1;
          else if((p+se)->age < 66)
            *(estas+3) = *(estas+3)+1;
          else if((p+se)->age < 120)
            *(estas+4) = *(estas+4)+1;
        }
      }
      printf("     %d        %d            %d             %d             %d\n", *estas, *(estas+1), *(estas+2), *(estas+3), *(estas+4));

      for(se = 0; se < 5; ++se)
        *(estas+se) = 0;
    }
  }
  free(estas);
}

void boom(Participant *allah, char ***uakbar)
{
  int no, se;

  for(no = 0; no < N; ++no)
  {
    free((allah+no)->name);
    free((allah+no)->answers);
  }

  free(allah);

  for(no = 0; no < M; ++no)
  {
    for(se = 0; se < R; ++se)
      free(*(*(uakbar+no)+se));
    
    free(*(uakbar+no));
  }

  free(uakbar);
}
/* END FUNTIONS*/

int main()
{
  Participant *p = (Participant *)malloc(N*sizeof(Participant));
  char ***q = (char ***)malloc(M*sizeof(char**));
  srand((int)time(NULL));

  enviroment(p, q);

  int option;

  printf("Fill the quizzes manually?\n1. YES\n2. ARE YOU CRAZY?!\n");
  scanf("%d", &option);

  if(option)
    full_quiz(p, q);
  else
    full_quiz_random(p, q);

  answers_history(p,q);
  ages_history(p, q);
  
  printf("Estuvo bueno el concierto de violín!\n");
  return 0;
}

