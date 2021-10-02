



/*********************************************
***********************************************
     SERVER file
     Name- Kavya Kandhway
     Adm no. 18JE0408
     DD CSE   
************************************************
************************************************
*/


#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
//#include <bits/stdc++.h>
//using namespace std;
int main() 
{ 
	int server_socket;
	server_socket=socket(AF_INET,SOCK_STREAM,0);
	if(server_socket<0)
	{
		printf("Error1\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("checkpoint1s\n");
	}
	
	struct sockaddr_in address; 
	int addrlen = sizeof(address); 
	address.sin_family=AF_INET; 
	address.sin_addr.s_addr=INADDR_ANY; 
	address.sin_port=htons(8090);
	
	bind(server_socket,(struct sockaddr*)&address,sizeof(address));
	
	listen(server_socket, 3);
	
	int new_socket;
	new_socket = accept(server_socket, (struct sockaddr*)&address, (socklen_t*)&addrlen);
	
	if (new_socket < 0)
	{ 
		printf("error2\n");
		exit(EXIT_FAILURE); 
	} 
	
	int valread; 
	char str[100];
	valread = read(new_socket, str, sizeof(str));
	printf("word received\n");
	printf("\nWord entered by the user:%s\n", str); 
	
} 
