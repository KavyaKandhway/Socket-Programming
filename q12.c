// Client 
#include <stdio.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 

int main() 
{ 
	int sock = 0, val; 
	struct sockaddr_in serv_addr; 
	char *hello = "Hello"; 
        char otp[6]; 
	char buffer[1024] = {0}; 

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 
       printf("\nClient running....\nEnter the 5 char Otp to send to server: ");
       scanf("%s", otp);
       printf("Entered otp is: %s: ", otp);
   
        send(sock , otp , strlen(otp) , 0 ); 
	send(sock , hello , strlen(hello) , 0 ); 

	printf("\nMessage sent to server.... "); 
	val = read( sock , buffer, 1024); 
   
      if(val<=0){
        printf("\nInvalid otp ...Hence Authenticatation is failed....\n");
       }
     else{
        printf("\nAuthentication is successful.... ");
        printf("Hence Message  from server: %s \n ",buffer);
      }
    return 0; 
}
