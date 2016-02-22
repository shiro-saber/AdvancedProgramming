/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : client.c
* Creation Date : 22-02-2016
* Last Modified : Mon 22 Feb 2016 10:49:40 AM CST
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
  int *guardala;
  int si = 1;
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
  
  // Leer de teclado y escribir en socket
    while (si) {
      guardala = (int*)realloc(guardala, sizeof(int)*cont+1);
      for(int i = 0; i < cont; ++i)
      {
        *(guardala+i) = rand()%20;
        cont++;
      }
      write(cliente, &cont, sizeof(int));
      write(cliente, &guardala, sizeof(int)*cont);
    }
  }
    
  // Cerrar el socket
  close(cliente);
  free(guardala);
    
  return 0;
}
