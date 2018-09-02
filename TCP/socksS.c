#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(int argc, char **argv) {
  
  // create a string to send to all the clients
  
  char server_message[256] = "You reached the server ya goof!";
  
  // create our socket
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  
  // define the server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  // we now bind the socket to our specified IP and port
  int bind_checker = bind(server_socket, (struct sockaddr * ) &server_address, sizeof(server_address));
  if (bind_checker == -1){
    perror("bind");
    exit(-1);
  }
  
  // we can now listen
  int listen_checker = listen(server_socket, 5);
  
  if (listen_checker == -1){
    perror("listen");
    exit(-1);
  }
  
  // now we can accept (so we can now send and recieve data both ways)
  int client_socket = accept(server_socket, NULL, NULL);
  
  // we can now send data to the client
  send(client_socket, server_message, 256, 0);
  return 0;
}