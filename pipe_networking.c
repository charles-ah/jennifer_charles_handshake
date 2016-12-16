#include "pipe_networking.h"


int server_handshake(int* to_client);
{
  mkfifo("WKP",0644);
  printf("waiting for connection\n");
  open("WKP",O_RDONLY);

  return 0;
}


int client_handshake(int* to_server)
{
  mkfifo("private",0644);
  printf("connecting to sevrer\n");
  open("WKP",O_WRONGLY);
}
