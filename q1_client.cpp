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
	int client_socket;
	client_socket=socket(AF_INET,SOCK_STREAM,0);
	if(client_socket<0)
	{
		printf("Error1\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("checkpoint1s\n");
	}
	struct sockaddr_in client_address; 
	memset(&client_address, '0', sizeof(client_address)); 
	client_address.sin_family = AF_INET; 
	client_address.sin_port = htons(8090);  
	inet_pton(AF_INET, "127.0.0.1", &client_address.sin_addr);
	connect(client_socket, (struct sockaddr*)&client_address, sizeof(client_address));
	cout<<"--------------------------------Welcome to my world!---------------------------------\n";
	cout<<"Enter the password to login\n";
	char password[50];
	scanf("%[^\n]%*c", password); 
	send(client_socket, password, sizeof(password), 0);
	int valread;
	bool flag;
	valread = read(client_socket,&flag, sizeof(flag));
	if(flag)
	{
		cout<<"Successfully logged in :)\n";
		cout<<"\nSay Hi to the Server\n";
		char hi[20];
		scanf("%[^\n]%*c", hi); 
		send(client_socket,hi,sizeof(hi),0);
		//char hello[20];
		valread=read(client_socket,hi,sizeof(hi));
		printf("%s\n",hi);
	}
	else
	{
		cout<<"Access Denied :(\n";
	}
	
}
