

/*********************************************
***********************************************
     CLIENT file
     Name- Kavya Kandhway
     Adm no. 18JE0408
     DD CSE   
************************************************
************************************************
*/




#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 


int main() 
{ 
	struct sockaddr_in address; 
	int sock = 0, valread; 
	
	

	char buffer[1024] = { 0 };  
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if ( sock< 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 
	
	
	//Initializing
	struct sockaddr_in server_address; 
	memset(&server_address, '0', sizeof(server_address)); 
	server_address.sin_family = AF_INET; 
	server_address.sin_port = htons(8090);                                                                                                                            
 	inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
 	
 	//Connecting
	connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));

	
	char str[100]; 
	printf("\nEnter the password:"); 
	scanf("%[^\n]s", str); 
	int l = strlen(str); 
	
	send(sock, str, sizeof(str), 0); 
    int flag;
    valread = read(sock, &flag, sizeof(flag));
	if(flag==1)
	{
        printf("Successfully logged in\nType a message to send it\n");
        char message[100];
        scanf("%s", message);
        send(sock, message, sizeof(message), 0); 
        printf("Message sent succesfully\n");
        
    }
    else
	{
		 printf("Authentication denied.\n");
	 }
	return 0; 
} 
