#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>



int main(){
int s_socket = socket(AF_INET,SOCK_STREAM,0);
//socket creation
if(s_socket<0){
	perror("error creating socket");
	exit(1);
}
//server variables
struct sockaddr_in server_address;
server_address.sin_family = AF_INET;
server_address.sin_addr.s_addr = INADDR_ANY;
server_address.sin_port	= htons(9002);

//binding
while(1){
if(bind(s_socket,(struct sockaddr *) &server_address,sizeof(server_address))<0){
	perror("error binding socket and port");
	exit(1);
}
//listening
if(listen(s_socket,10)<0){
	perror("error listening");
	exit(1);
}


//accepting

	struct sockaddr_in client_address;
	int clen = sizeof(client_address);
	int client_socket=accept(s_socket,&client_address,&clen);
	if (client_socket<=0){
		perror("accept() failed");
		exit(1);
	}else {
		char msg[256] = "you have successfully reached the UNITED server\n";
		write(client_socket,msg,sizeof(msg));
		
}
close(client_socket);
return 0;
}


























}

