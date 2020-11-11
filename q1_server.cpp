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
	struct sockaddr_in server_address; 
	memset(&server_address, '0', sizeof(server_address)); 
	server_address.sin_family = AF_INET; 
	server_address.sin_port = htons(8090);  
	server_address.sin_addr.s_addr=INADDR_ANY; 
	
	bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address));
	listen(server_socket, 3);
	
	int addrlen = sizeof(server_address);
	int new_socket;
	new_socket = accept(server_socket, (struct sockaddr*)&server_address, (socklen_t*)&addrlen);
	if (new_socket < 0)
	{ 
		printf("error2\n");
		exit(EXIT_FAILURE); 
	} 
	int valread;
	char verify[50];
	valread = read(new_socket,verify, sizeof(verify));
	printf("\nPassword entered by the user:%s\n", verify); 
	char pass[]="tifanny";
	int len=strlen(verify);
	int passlen=strlen(pass);
	cout<<len<<endl;
	bool flag=1;
	if(passlen!=len)
	{
		flag=0;
	}
	else
	{
		for(int i=0;i<len;i++)
		{
			if(verify[i]!=pass[i])
			{
				flag=0;
				break;
			}
		}
	}
	send(new_socket, &flag, sizeof(flag), 0);
	if(flag)
	{
		char str[20];
		valread=read(new_socket,str,sizeof(str));
		printf("Client: %s\n",str);
		char hi[]="Hello Client";
		send(new_socket,hi,sizeof(hi),0);
	}
	
}
