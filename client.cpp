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
	connect(sock, (struct sockaddr*)&server_address, sizeof(server_address));
	cout<<"WELCOME\n";
	cout<<"Enter the choice \n";
	cout<<"Enter 1 Decimal\nEnter 2 for Binary\nEnter 3 for Octal\nEnter 4 for Hexadecimal\n";
	int type=0;
	cin>>type;
	send(sock, &type, sizeof(type), 0);
	
	printf("\nEnter the number: ");
	int str;
	cin>>str;
	send(sock, &str, sizeof(str), 0); 
	char binary[100],hexa[100];
	if(type==1)
	{
		int valread = read(sock, binary, sizeof(binary));
		printf("\nBinary:%s\n", binary); 
		int octal;
		valread=read(sock, &octal, sizeof(octal));
		cout<<"octal="<<octal<<endl;
	}
	else if(type==2)
	{
		int decimal;
		int valread = read(sock, &decimal, sizeof(decimal));
		cout<<"Decimal="<<decimal<<endl;
		int octal;
		valread=read(sock, &octal, sizeof(octal));
		cout<<"octal="<<octal<<endl;
	}
	if(type==3)
	{
		int decimal;
		int valread = read(sock, &decimal, sizeof(decimal));
		cout<<"Decimal="<<decimal<<endl;
		valread = read(sock, binary, sizeof(binary));
		printf("\nBinary:%s\n", binary); 
	}
	
//	valread=read(sock, hexa, sizeof(hexa));
	//printf("\nHexadecimal:%s\n", hexa); 
}
