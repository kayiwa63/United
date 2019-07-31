#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include<netinet/in.h>

 int main (){
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
      	perror("connection error");
	exit(1);
     }
    // receive data from the server
char response[256];
int check=1;
int try=0;
  if(recv(network_socket,response,sizeof(response),0)<0){
	 perror("error receiving from server");
         exit(1);

        }
 printf("UFT>: %S",response);
//structure to receive data
 struct collect{
                char command[30];
                char fname[30];
		char lname[30];
               // char date[10];
                char gender[1];
                char recommender[30];
                };
        struct collect mem;
//target string
int digit[15];
char star[15];
int k = 0;
int l = 0;
int counter = 0;
char str[256];
int x=0;
int com=0;
while(1){
	//empty the structure
	memset(&mem,0,sizeof(mem));
	printf("\n UFT>:");
	//get screen input to target string
	gets(str);
	//check for number of empty spaces
	for(int i=0;str[i];i++){
		if(str[i]==' '){
			x++;
			}
	}
	//assign values to the structure
	if(x>1){
		strcpy(mem.command,strtok(str," "));
		strcpy(mem.fname,strtok(str,NULL));
		//strcpy(mem.lname,strtok(str,NULL));
		//strcpy(mem.gender,strtok(str,NULL));

		printf("%s",mem.fname);
	}
		else{
			strcpy(mem.command,str);
			}
	//compare commands
	if(strcmp("Addmember",mem.command)==0){
		com=1;
			}
	else if(strcmp("get_statement",mem.command)==0){
		com=2;
			}
	else if(strcmp("Search",mem.command)==0){
                        com=3;
		}
	else if(strcmp("Check_status",mem.command)==0){
                        com=4;
		}
	else if(strcmp("help",mem.command)==0){
                        com=5;
			}
	else if(strcmp("quit",mem.command)==0){
                        com=6;
		}
	else if(strcmp("Signature", mem.command)==0){
		com=7;
	}
	else{
		com=0;
	}
	//perform commands for each case
	switch(com){
		case 1:
		printf("%s",mem.fname);
		printf("%s",mem.lname);
		printf("%s",mem.gender);
		//printf("%s",mem.fname);

		printf("\n member added");
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
		break;
		case 5:
		printf(" Addmember,get_status,get_statement,help,quit");
		break;
		case 6:
		break;
		case 7:{
			for(k = 0; k < 15; k++){
			printf("Enter 0 or 1:", k+1);
			scanf(" %d", &digit[k]);
			}
			
			for(k = 0; k < 15; k++){
				
				if(digit[k] == 0){
					star[k] = ' ';
				}
				else if(digit[k] == 1){
					star[k] = '*';
				}
				else{
					printf("\nNumber enter not 0 or 1.");
					getch();
				}
			}
			
			k=0;
			printf("\n");
			printf("\n");
			
			for(l = 0; l < 5; l++){
				counter = 0;
				for(k; counter < 3; k++){
					printf("%c ",star[k]);
					counter = counter + 1;
				}
				printf("\n");
			}
			break;
		}
			
		default:
		printf("unknown command");
		break;
		};
bzero((struct collect*)&mem,sizeof(mem)); //clear the structure (optional)	
}

close(network_socket); //close socket
return 0;
}
