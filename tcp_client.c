 #include <stdio.h>
 #include <stdlib.h>

 #include <sys/types.h>
 #include <sys/socket.h>

 #include<netinet/in.h>

 int main (){
     FILE *fptr;
    char name[20];
    int age;
    int salary;
    

     // creating the socket
     int network_socket;
     network_socket = socket(AF_INET,SOCK_STREAM,0);

     // the address
     struct sockaddr_in server_address;
     server_address.sin_family = AF_INET;
     server_address.sin_port = htons(9002);
     server_address.sin_addr.s_addr = INADDR_ANY;

     int connection_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));
     if (connection_status == -1){
         printf("There was an error making a connection to the remote socket \n\n");
     }
    // receive data from the server
     char server_response[256];
     recv(network_socket, &server_response, sizeof(server_response),0);

     //server response
    printf("The server sent the data %s\n", server_response);

    fptr = fopen("glad.txt","w");

        
    printf("Enter the name: ");
    scanf("%s", name);
    fprintf(fptr, "Name  = %s\n", name);
    
    printf("Enter the age: ");
    scanf("%d",&age);
    fprintf(fptr,"Age = %d\n", age);

    printf("Enter the salary: ");
    scanf("%d",&salary);
    fprintf(fptr,"Salary = %d\n", salary);

    printf("would you like to continue 1/2: ");
    //scanf("%d", &vamos);
    

    fclose(fptr);


     // close socket
     close(network_socket);
     return 0; 
 }