#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(int argc, char **argv) {

  // let's make a socket
  int network_socket;
  // we're going to use a TCP socket
  if ((network_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
    perror("socket");
    exit(-1);
  };
  
  // specify an address for the socket
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  // specify a port to connect to, the port is in the parameter
  server_address.sin_port = htons(9002);
  // connecting to a server address (local machine)
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  int connection_check = connect(network_socket, (struct sockaddr *) & server_address, sizeof(server_address));
  
  // we can now connect
  if (connection_check == -1){
    perror("connect");
    exit(-1);
  }
  
  // receive data from the server
  char server_response[256];
  recv(network_socket, &server_response, 256, 0);
  
  // print the server's response
  printf("The server sent the data: %s\n", server_response);
  
  // we can now close the socket
  close(network_socket);
  return 0;
}