 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>

 #include <sys/types.h>
 #include <sys/socket.h>

 #include <netinet/in.h>
 #include <netdb.h>
 #include <ctype.h>


 int main(){
     FILE *fptr;

     char server_message[256] = "You have reached the UFT server!";
      char buffer[255];


    // creating the socket
     int server_socket;
     server_socket = socket(AF_INET,SOCK_STREAM,0);

     //server address
     struct sockaddr_in server_address;
     server_address.sin_family = AF_INET;
     server_address.sin_port = htons(9002);
     server_address.sin_addr.s_addr = INADDR_ANY;

     //binding the socket to IP and PORT
     bind(server_socket,(struct sockaddr*) &server_address, sizeof(server_address));

     //listen
     listen(server_socket, 5); 

     int client_socket;
     client_socket = accept(server_socket,NULL,NULL);

     // meesa
     fptr = fopen("glad.txt","r");

        fclose(fptr);

     

    // send the message
     send(client_socket, server_message, sizeof(server_message), 0);

    //close the socket
    close(server_socket);
     return 0;
 }
