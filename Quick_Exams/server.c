/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : server.c
* Creation Date : 22-02-2016
* Last Modified : Mon 22 Feb 2016 10:10:37 AM CST
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
    char buffer[1000];
    int *guardala;
    
    guardala = (int*)malloc(sizeof(int)*1);

    int servidor, cliente;
    int sum = 0; int sB = 0;
    int max = 0;int min = 0;
    
    int leidos, escritos;
    
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
    
    int fact;
    
    if (cliente >= 0) {
        printf("Aceptando conexiones en %s:%d \n",
               inet_ntoa(direccion.sin_addr),
               ntohs(direccion.sin_port));
        
        // Leer de socket y escribir en pantalla
        while (leidos = read(cliente, &buffer, sizeof(buffer))) {
            write(fileno(stdout), &buffer, leidos);
            //guardala = (int*)realloc(guardala, sizeof(int)*(sB+1));
            //printf("leido #%d\n",atoi(buffer));
            guardala = (int*)realloc(guardala, sizeof(int)*sB+1);
            *(guardala+sB) = atoi(buffer);
            //printf("guarde %d\n", *(guardala+sB));
            sB++;                               
           //leidos = write(fileno(stdin), &buffer, sizeof(buffer));
           //write(cliente, &buffer, sizeof(int));
        }
    }

    for(int i = 0; i < sB; ++i)
      sum += *(guardala+i);
    printf("El promedio es: %d\n", sum/sB);
    
    for(int j = 0; j < sB; ++j)
    {
      max = (max < *(guardala+j))? *(guardala+j) : max;
      min = (min > *(guardala+j))? *(guardala+j) : min;
    }

    printf("El máximo es: %d\nEl mínimo es: %d\n", max, min);
    // Cerrar el socket
    
    close(servidor);
    close(cliente);
    free(guardala);
    
    return 0;
}
