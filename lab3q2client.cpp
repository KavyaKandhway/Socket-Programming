/* Name-Kavya Kandhway
   ADM NO 18JE0408
   DD CSE*/
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
	int sock=socket(AF_INET, SOCK_STREAM, 0);
	 if ( sock< 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
 }

	char buffer[1024] = { 0 };  
	
	//Initializing
	struct sockaddr_in server_address; 
	memset(&server_address, '0', sizeof(server_address)); 
	server_address.sin_family = AF_INET; 
	server_address.sin_port = htons(8090);                                                                                                                            
 	inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
 	
 	//Connecting
 	char str[100];
	connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));
	while(1)
	{
		char id[50];
		printf("Enter ID of the employee(Q to Quit)\n");
		scanf("%s",id);
		if(strlen(id) == 1 && id[0] == 'Q')
			break;
		send(sock,&id,sizeof(id),0);
		int n;
		printf("Enter leaves required by the  employee\n");
		scanf("%d",&n);
		send(sock,&n,sizeof(n),0);
		//receiving data from server
		//char str[50];
		bool flag;
		recv(sock,&flag,sizeof(flag),0);
		if(flag)cout<<"Accepted"<<endl;
		else
		{
			cout<<"Denied"<<endl;
		}
	}
} 
