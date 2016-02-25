/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : client.c
* Creation Date : 22-02-2016
* Last Modified : Mon 22 Feb 2016 11:24:30 AM CST
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
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define TCP_PORT 8000

int main(int argc, const char * argv[]) 
{
  struct sockaddr_in direccion;
  char buffer[1000];
  int bool = 1;
  int *guardala;
  int cliente; 
  int cont = 0;
  int leidos, escritos;

  guardala = (int*)malloc(sizeof(int)*1);
  
  if (argc != 2) {
    printf("Error. Use: %s A.B.C.D \n", argv[0]);
    exit(-1);
  }
    
  //Crear el socket
  cliente = socket(PF_INET, SOCK_STREAM, 0);
    
  // Establecer conexión
  direccion.sin_port = htons(TCP_PORT);
  direccion.sin_family = AF_INET;
  inet_aton(argv[1], &direccion.sin_addr);
    
  int estado = connect(cliente, (struct sockaddr *) &direccion, sizeof(direccion));
    
  // Comunicación
    
  if (estado == 0) {
    printf("Conectado a %s:%d \n",inet_ntoa(direccion.sin_addr), ntohs(direccion.sin_port));

    while (bool) 
    {
      bool = 0;
      guardala = (int*)realloc(guardala, sizeof(int)*cont+1);
      cont++;
      *(guardala+cont-1) = rand()%20;
      if(*(guardala+cont-1) != 0)
        bool=1;

      write(cliente, &cont, sizeof(int));
      write(cliente, guardala, sizeof(int)*cont); 
    }
    
  }
    
  // Cerrar el socket
  close(cliente);
  free(guardala);
  
  return 0;
}
