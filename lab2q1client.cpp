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
	cout<<"______________THIS IS A SONG DICTIONARY________________\n";
	cout<<"______________Enter the name of the song________________\n";
	cout<<"And the program will tell you the composer of the song\n\n\n";
	cout<<"____________________________________________________________\n";
	cout<<"____________________________________________________________\n";
	cout<<"Examples of the song already in the dictionary: let me down slowly, high enough, whatever it takes, water fountain\n";
	//cout<<"Enter q to exit\n";
	char str[100]; 
	while(1)
	{
		printf("\nEnter the name of the song\n");
		printf(" OR enter q to exit\n"); 
		scanf("%[^\n]%*c", str); 
		int leng=strlen(str);
		if(str[0]=='q'&&leng==1)
		{
			//cout<<"done"<<endl;
			cout<<"closing the application\n";
			break;
		}
		int l = strlen(str);
		send(sock, str, sizeof(str), 0); 
		
		int valread;
		bool flag;
		valread = read(sock, &flag, sizeof(flag));
		if(flag)
		{
			cout<<"The song is composed by:";
			valread = read(sock, str, sizeof(str));
			cout<<str<<endl;
		}
		else
		{
			cout<<"Song not found\n";
			cout<<"Enter the name of the composer to add it to the dictionary\n";
			scanf("%[^\n]%*c", str);
			send(sock, str, sizeof(str), 0); 
		}
		
	}
	
	return 0; 
} 
