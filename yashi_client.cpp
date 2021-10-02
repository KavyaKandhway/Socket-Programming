#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<string>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
using namespace std;
int main()
{
	int network_socket=socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_address; 
	memset(&server_address, '0', sizeof(server_address)); 
	server_address.sin_family = AF_INET; 
	server_address.sin_port = htons(10000);                                                                                                                            
 	inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
 	
 	//Connecting
	connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));
	printf("this is the client site");
	while(1)
	{
	        printf("enter the ip address to be shortened:");
		char s[100];
		scanf("%s",s);
		send(network_socket,s,sizeof(s),0);
		char q[100];
		recv(network_socket,q,sizeof(q),0);
		printf("the shortened address is :");
		printf("%s",q);
		s[22]='\0';
		q[22]='\0';
	}
	close(network_socket);
	return 0;
}
