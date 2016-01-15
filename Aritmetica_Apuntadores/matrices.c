/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : matrices.c
* Creation Date : 14-01-2016
*   Last Modified : Fri 15 Jan 2016 01:53:36 PM CST
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

int main()
{
  int m, n, i;
  printf ("Entra el tamaño N\n");
  scanf("%d", &n);
  printf ("Entra el tamaño M\n");
  scanf("%d", &m);

  int *matriz = (int*)malloc(sizeof(int) * (m*n));
  int *aux = matriz;

  /*llena la matriz*/
  for(i = 0; i < n*m; ++i)
  {
    int kuz, modishness;
    kuz = i/n;
    modishness = i % m;

    printf("Inserta el valor en [%d, %d]\n", kuz, modishness);
    scanf("%d", aux++);
  }

  i=0;
  /*Imprime la matriz*/
  printf("La matriz llena es: \n");
  for (aux= matriz; aux < (matriz+(n*m)); ++aux )
  {
    if((i%n) == 0)
    {
      printf("\n");
      i = 0; 
    }
   
    printf(" [%d] ", *aux); 
    i++;
  }
  
  printf("\n");
  free(matriz);
  return 0;
}
