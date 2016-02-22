/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
* File Name : main.c
* Creation Date : 15-02-2016
* Last Modified : Wed 17 Feb 2016 09:21:19 PM CST
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
  struct sockaddr_in direction;
  char buffer[1000];
  int client, server;
  int continuer = 1;

  socklen_t readed, writed;
  pid_t pid;

  if(argc != 2)
  {
    fprintf(stderr, "Syntax: %s <IP>\n", argv[0]);
    exit(-1);
  }
  
  // Create the socket
  server = socket(PF_INET, SOCK_STREAM, 0);

  //Link the socket
  inet_aton(argv[1], &direction.sin_addr);
  direction.sin_port = htons(TCP_PORT);
  direction.sin_family = AF_INET;

  bind(server, (struct sockaddr *)&direction, sizeof(direction));

  //Listen
  listen(server, 10);
  writed = sizeof(direction);

  //Accept conections
  while(continuer)
  {
    client = accept(server, (struct sockaddr *)&direction, &writed);

    printf("Accepting clients in %s: %d\n", inet_ntoa(direction.sin_addr), ntohs(direction.sin_port));

    pid = fork();

    if(pid == 0)
      continuer = 0;
  }

  if(pid == 0)
  {
    close(server);

    if(client >= 0)
    {
      while(readed = read(client, &buffer, sizeof(buffer)))
      {
        write(fileno(stdout), &buffer, readed);

        /* Read from keyboard and write on the socket */
        readed = read(client, &buffer, readed);
        write(client, &buffer, readed);
      }
    }
    close(client);
  }
  else
  {
    while(wait(NULL) != -1);
    close(server);
  }

  return 0;
}
