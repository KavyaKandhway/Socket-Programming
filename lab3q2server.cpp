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
	int valread;
	int i;
	char str[50];
char res[50];
char adj[50][50];
int arr[50];
int sz;
    for(i = 0 ; i<6 ; i++)
    {
        char ch = i + 'A';
        adj[i][0] = ch;
        arr[i] = 50;
    }
	{
        int lf;
		recv(new_socket,&str,sizeof(str),0);
        recv(new_socket,&lf,sizeof(lf),0);
        int ind = -1;
		for(i=0 ; i<sz ; i++)
        {
            if(strcmp(adj[i],str)==0)
            {
                ind = i;
                break;
            }
        }
        if(ind==-1)
        {
            ind = sz;
            strcpy(adj[sz],str);
            arr[sz++] = 50; 
        }
        bool flag=0;
        if(arr[ind]>=lf)
        {
            arr[ind]-=lf;
            flag=1;
        }
        send(new_socket,&flag,sizeof(flag),0);
	}
} 
