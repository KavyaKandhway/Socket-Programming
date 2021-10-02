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
	char str[100]; 
	char div[100];
	
	printf("\nEnter the binary string\n");
		
	scanf("%[^\n]%*c", str); 
	send(sock, str, sizeof(str), 0);
		
	printf("\nenter the crc code\n");	
	
	scanf("%[^\n]%*c", div);  
	send(sock, div, sizeof(div), 0);
	
	char temp[100];
	strcpy(temp,str);
	
	int i,j,k;
	int l=strlen(str);
	int n=strlen(div);
	int m=strlen(temp);
	
	for(i=0;i<n-1;i++)
	{
		str[l+i]='0';
	}
	str[l+i]='\0';			
	printf("\nstring after appending zeroes at the end %s\n", str); 
	
	l=strlen(str);
	
	for(i=0;i<=l-n;)
	{
		for(j=0;j<n;j++)
		{
			if(str[i+j]==div[j])
			{
				str[i+j]='0';
			}
			else
			{
				str[i+j]='1';
			}
		}
		for(;i<l&&str[i]!='1';i++);
		
	}
	
	printf("\nstring after division :%s\n", str); 
	cout<<"n="<<n<<endl;
	j=m;
	i=1;
	k=l-n+1;
	while(i<=n-1)
	{
		
		temp[j]=str[k];
		//cout<<str[j+1]<<" "<<str[k-1]<<endl;
		i++;
		j++;
		k++;
	}
	temp[j]='\0';
	printf("\nthe encoded string :%s\n", temp); 
	send(sock, temp, sizeof(temp), 0);
	
	int valread;
	bool flag;
	valread = read(sock, &flag, sizeof(flag));
	if(flag)cout<<"Good Data"<<endl;
	else
	{
		cout<<"Bad data"<<endl;
	}
	return 0;
} 
