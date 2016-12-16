#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "pipe_networking.c"

//takes address of server and approves handshake
int client_handshake( int* address );

//takes address of client and approves handshake
int server_handshake( int* address );
