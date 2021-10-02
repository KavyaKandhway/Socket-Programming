/* Name-Kavya Kandhway
   ADM NO 18JE0408
   DD CSE*/
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
	char key[100][100]={"let me down slowly","whatever it takes","water fountain","high enough","issues","dusk till dawn","ignite","7 rings"};
	char ans[100][100]={"Alec Benjamin","Imagine Dragons","Alec Benjamin","K Flay","Julia Michaels","ZAYN","Alan Walker","Ariana Grande"};
	
	int size=8;
	int valread; 
	char str[100];
	while(1)
	{
		valread= read(new_socket, str, sizeof(str));
		printf("word received\n");
		printf("\nWord entered by the user:%s\n", str); 
		int i;
		bool flag=0;
		int l=strlen(str);
		cout<<"Length of str="<<l<<endl;
		for(i=0;i<100;i++)
		{
			bool flag2=1;
			for(int j=0;j<l;j++)
			{
				if(key[i][j]!=str[j])
				{
					flag2=0;
					break;
				}
			}
			if(flag2)
			{
				flag=1;
				break;
			}
		}
		send(new_socket, &flag, sizeof(flag), 0);
		if(flag)
		{
			send(new_socket,ans[i], sizeof(ans[i]), 0);
		}
		else
		{
			//key[size]=str;
			for(i=0;i<l;i++)
			{
				key[size][i]=str[i];
			}
			valread = read(new_socket, str, sizeof(str));
			l=strlen(str);
			for(i=0;i<l;i++)
			{
				ans[size][i]=str[i];
			}
			size++;
		}
	}
	
	//cout<<key[0]<<endl;

} 
