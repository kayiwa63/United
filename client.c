#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include<netinet/in.h>

#define MACC 1000

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

//structure to receive data
 struct collect{
                char command[30];
                char fname[30];
                char lname[30];
                int dd,mm,yyyy;
                //char date[10];
                char gender[2];
                char recommender[30];
                };
        struct collect mem;

//Variables
    char * hold={0};
    char * hold1={0};
    FILE * fptr;
    FILE * fptr1;
    char * ptr;
    char buff[255];
    char newstr[MACC];



    int digit[15];
    char star[15];
    int k = 0;
    int l = 0;
    int counter =0;
    char filename[]=".txt";
    char criteria[15];


    char Aname[30];
    char Dname[30];


//variables


//target string
char str[256];
int x=0;
int com=0;
char buffer[256];
char *space;

    // The agent name and stuff
    printf("Enter Agent name: ");
    scanf("%s",Aname);
   // hold1 = strcat(Aname,".txt");
    printf("Enter District name: ");
    scanf("%s", Dname);
    hold = strcat(Dname,".txt");


    // the instructions

    printf("Welcome, %s.\n",Aname);

    printf("-------------------------------------------------------------------------------------------\n");
    printf("Welcome to the UFT Command pallete.\n");
    printf("The commands available to you are Addmember, Check_status, get_statement, Search and help.\n");
    printf("The date is entered in the format yyyy-mm-dd.\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("Enter command action\n");

while(com!=6){
	//empty the structure
	//printf("\n UFT>: %s ",response);
	printf("\n UFT>: ");
	//get screen input to target string
	fgets(str,sizeof(str),stdin);
	 sscanf(str,"%s %s %s %d-%d-%d %s %s",mem.command,mem.fname,mem.lname,&mem.yyyy,&mem.mm,&mem.dd,mem.gender,mem.recommender);

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
		}else if(strcmp("Signature",mem.command)==0){
                        com=7;
		}
	else{
			com=0;
		}
	//empty mem.command
	memset(mem.command,0,sizeof(mem.command));
	//perform commands for each case
	switch(com){
		case 1:

          //else


            ptr = strstr(mem.fname,filename);

            if (ptr != NULL)

                {
                fptr1=fopen(mem.fname,"r");
                fgets(newstr,MACC,fptr1);
                puts(newstr);
                fclose(fptr1);

                fptr=fopen(hold,"a");
                fprintf(fptr,"%s",newstr);
                fclose(fptr);
                printf("The file has been added.");
                }
            else {


        fptr=fopen(hold,"a");

        //printing to the file

        fprintf(fptr,"%s ",mem.fname);
        fprintf(fptr,"%s ",mem.lname);
        fprintf(fptr,"%04d-%02d-%02d ",mem.yyyy,mem.mm,mem.dd);
        fprintf(fptr,"%s ",mem.gender);
        fprintf(fptr,"%s ",mem.recommender);
        fprintf(fptr,"\n");

        fclose(fptr);
        printf("\n member added");     }


		break;
		case 2:
            fptr=fopen("payment.txt","r");
            fgets(buff,255,fptr);
          //  puts(buff);

            fclose(fptr);

		break;
		case 3:

            


            fptr=fopen(hold,"r");

             while (fscanf(fptr,"%s",newstr) != EOF)

                {

		 if (strcmp(newstr,mem.fname) == 0)
			{
			   printf("Found\n");
				} else { printf("Not found\n");}
			
			}

                fclose(fptr);



		break;
		case 4:

		 fptr=fopen(hold,"r");


		 if ((fptr)== NULL){
            printf("Error! File for district doesn't exist.\n");
            exit(1);

		 } else if (fgets(buff,255,fptr)!=NULL) {
            //printf("The file is waiting for validation.\n");
            puts(buff);
            } else{
                printf("The file is empty.\n");
                }
            //puts(buff);


        fclose(fptr);

		break;
		case 5:
		printf(" Addmember,Check_status,get_statement,help,quit");
		break;
		case 6:

		break;
		case 7:
			for(int k = 0; k < 15; k++){
			printf("Enter 0 or 1:", k+1);
			scanf(" %d", &digit[k]);
			}

			for(int k = 0; k < 15; k++){

				if(digit[k] == 0){
					star[k] = ' ';
				}
				else if(digit[k] == 1){
					star[k] = '*';
				}
				else{
					printf("\nNumber enter not 0 or 1.");
					getchar();
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
		default:
		//printf("unknown command");
		//printf("%s",command);
		break;
		};

bzero((struct collect*)&mem,sizeof(mem)); //clear the structure (optional)
}

close(network_socket); //close socket
return 0;
}

