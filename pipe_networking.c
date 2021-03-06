//#include "pipe_networking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int server_handshake(int* to_client)
{
  mkfifo("WKP",0644); //step 1
  printf("waiting for connection\n");
  int WKP = open("WKP",O_RDONLY); //step 4

  char p[1024];
  read(WKP,p,sizeof(p));//step 5 and 6
  printf("connected with %s\n",p);
  //close(WKP);
  remove("WKP");

  int private = open("private",O_WRONLY);//step 7
  write(private,"hailing client!",16);
  
  
  read(WKP,p,sizeof(p));
  printf("%s\n",p);

  *to_client = WKP;
  return private;
}


int client_handshake(int* to_server)
{
  mkfifo("private",0644); //step 3
  printf("connecting to server\n");
  
  int WKP = open("WKP",O_WRONLY); //step 4
  write(WKP,"private",7);//step 4
  int private = open("private",O_RDONLY); 

  char p[1024];
  read(private,p,sizeof(p));
  printf("%s\n",p);
  //close(private);
  remove("private");

  write(WKP,"connection made",16);
  *to_server = WKP;
  return private;
}
/*
int main()
{
  return 0;
}
*/
