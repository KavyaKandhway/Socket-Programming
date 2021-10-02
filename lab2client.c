#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 


int main() 
{ 
	int sock=socket(AF_INET, SOCK_STREAM, 0);
	 if ( sock< 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	}
	else
	{
		printf("checkpoint1\n");
	 } 
	//int valread; 
	
	

	char buffer[1024] = { 0 };  
	
	//Initializing
	struct sockaddr_in server_address; 
	memset(&server_address, '0', sizeof(server_address)); 
	server_address.sin_family = AF_INET; 
	server_address.sin_port = htons(8090);                                                                                                                            
 	inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
 	
 	//Connecting
	connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));

	
	char str[100]; 
	printf("\nEnter the word:"); 
	scanf("%[^\n]%*c", str); 
	int l = strlen(str);
	send(sock, str, sizeof(str), 0); 
	printf("word sent\n");
	
	return 0; 
} 
