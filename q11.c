// Server 

#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h>
#include <unistd.h>  
#include <string.h> 
#define PORT 8080 
int main() 
{ 
	int server_fd, new_socket, val; 
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	char buffer[1024] = {0}; 
        char otpShould[6] = "abcde";
        char otpIs[6] = {0};
	char *hello = "Hello"; 
	
        printf("\nServer is running:");
	// Creating socket file descriptor 
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	} 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( PORT ); 
	
	if (bind(server_fd, (struct sockaddr *)&address,sizeof(address))<0) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	if (listen(server_fd, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
					(socklen_t*)&addrlen))<0) 
	{ 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	} 
       val = read( new_socket , otpIs, 1024); 
         
       printf("\nReceived Otp is:%s", otpIs);
       val = read( new_socket , buffer, 1024); 
       printf("\nMessage received from client : %s",buffer );
       if(strcmp(otpShould,otpIs) == 0){
          send(new_socket , hello , strlen(hello) , 0 );
          printf("\nAuthentication successful...hence message sent to client \n");   
       }
      else
     {
         printf("\nInvalid otp...hence message not sent\n");
     }
	return 0; 
}
