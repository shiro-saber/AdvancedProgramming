/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : server.c
* Creation Date : 22-02-2016
* Last Modified : Tue 15 Mar 2016 07:14:47 PM CST
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
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

#define TCP_PORT 8000

int main(int argc, const char * argv[])
{   
  struct sockaddr_in direccion;
  int cont;
  int *guardala;
  int servidor, cliente;
  int sum = 0; int sB = 0;
  int max = 0;
  int leidos, escritos;
  int i, j, k;

  if (argc != 2) {
    printf("Error. Use: %s A.B.C.D \n", argv[0]);
    exit(-1);
  }

  //Crear el socket
  servidor = socket(PF_INET, SOCK_STREAM, 0); 
  // Enlace con el socket
  direccion.sin_port = htons(TCP_PORT);
  direccion.sin_family = AF_INET;
  inet_aton(argv[1], &direccion.sin_addr);
  bind(servidor, (struct sockaddr *) &direccion, sizeof(direccion));
  // Escuchar a los clientes
  listen(servidor, 10);
  // Comunicación
  socklen_t tamano = sizeof(direccion);  
  cliente = accept(servidor, (struct sockaddr *) &direccion, &tamano);

  if (cliente >= 0) {
    printf("Aceptando conexiones en %s:%d \n",inet_ntoa(direccion.sin_addr), ntohs(direccion.sin_port));

  // Leer de socket y escribir en pantalla
    while (1) {
      leidos = read(cliente, &cont, sizeof(int));
      //write(fileno(stdout), &buffer, leidos);
      read(cliente, guardala, cont*sizeof(int));
      guardala = (int*)malloc(sizeof(int)*cont);
      for(k = 0; k < cont; ++k)
        if(*(guardala+k)==0)
          break;
    }
  }
  // Cerrar el socket
  for(i = 0; i < cont; ++i)
    sum += *(guardala+i);

  printf("El promedio es: %d\n", sum/cont);
    
  int min = *(guardala+0);

  for(j = 0; j < cont; ++j)
  {
    max = (max < *(guardala+j))? *(guardala+j) : max;
    min = (min > *(guardala+j))? *(guardala+j) : min;
  }
    
  printf("El máximo es: %d\nEl mínimo es: %d\n", max, min);

  close(servidor);
  close(cliente);
  free(guardala);
    
  return 0;
}
