#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pipe_networking.h"

void process( char * s );

int main() {

  int to_client, from_client;
  char buffer[MESSAGE_BUFFER_SIZE];
  //printf("size: %d\n",MESSAGE_BUFFER_SIZE);
  to_client = server_handshake( &from_client );

  //printf("from_client: %d\n",from_client);
  //printf("to_client: %d\n",to_client);
  
  while(1){
    read( from_client, buffer, sizeof(buffer) );
    printf("[CLIENT]: %s\n",buffer);
	   
    process( buffer );
    printf("[SERVER]: %s\n",buffer);
    write( to_client, buffer, sizeof(buffer));
  }
  return 0;
}




void process( char * s ) {

  while ( *s ) {
    *s = (*s - 'a' + 13) % 26 + 'a';
    s++;
  }
}
