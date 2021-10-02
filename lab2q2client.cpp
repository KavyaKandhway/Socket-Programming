/* Name-Kavya Kandhway
   ADM NO 18JE0408
   DD CSE*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sock=socket(AF_INET, SOCK_STREAM, 0);
	 if ( sock< 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	}
	
	unsigned int len;
	struct sockaddr_in client;
	client.sin_family=AF_INET;
	client.sin_port=htons(8090);
	client.sin_addr.s_addr=INADDR_ANY;
	bzero(&client.sin_zero,0);
	len=sizeof(struct sockaddr_in);
	connect(sock, (struct sockaddr*)&client, sizeof(client));
	bool flag;
	int valread;
	
		char str[15];
		char r[15];
		cout<<"_____________________________________________________________________________________________________________\n";
		cout<<"Format for entering the state name:\nExample: 'Kerala' without quotes and the first letter should be capital :)\n";
		cout<<"_____________________________________________________________________________________________________________\n";
		printf("Enter the state name:\n");
		
		scanf("%[^\n]%*c", str); 
		send(sock,&str,sizeof(str),0);
		valread = read(sock, &flag, sizeof(flag));
		if(flag)
		{
			recv(sock,&r,sizeof(r),0);
			cout<<"Capital is-"<<r<<endl;
		}
		else
		{
			cout<<"Not found\n";
			char t[15];
			printf("enter the capital name:\n");
			scanf("%[^\n]%*c", t); 
			send(sock,&t,sizeof(t),0);
		}
	return 0;
}
