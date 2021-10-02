



/*********************************************
***********************************************
     SERVER file
     Name- Kavya Kandhway
     Adm no. 18JE0408
     DD CSE   
************************************************
************************************************
*/


#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 

int main() 
{ 
	int server_socket;
	
	
	struct sockaddr_in address; 
	char str[100]; 
	
	char buffer[1024] = { 0 }; 


	printf("Successfully Initialised\n");
	server_socket = socket(AF_INET,SOCK_STREAM,0);
	if (server_socket==0) { 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	//Initializing
	int addrlen = sizeof(address); 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(8090); 
	
	//Binding
	bind(server_socket,(struct sockaddr*)&address,sizeof(address));
	
	
	//Listening
	listen(server_socket, 3);
	
	int new_socket;
	new_socket = accept(server_socket, (struct sockaddr*)&address, (socklen_t*)&addrlen);
	
	if (new_socket < 0)
	{ 
		printf("error2\n");
		exit(EXIT_FAILURE); 
	} 

	int valread; 
	valread = read(new_socket, str, sizeof(str)); 
	int i, j, temp, flag=1; 
	int l = strlen(str); 

	printf("\nPassword entered by the user:%s\n", str); 
    char *password="Kavya";
    if(l!=5)
    {
    	flag=0;
    	
	}
	if(flag==1)
	{
			for (i=0;i<5;i++) 
			{ 
				if(password[i]!=str[i])
				{
		            flag=0;
		            break;
		        }
			} 
	}

    
    send(new_socket, &flag, sizeof(flag), 0);
    
    if(flag==1)
	{
        valread = read(new_socket, str, sizeof(str));
        printf("%s ", str);
        printf(" Message Received\n");
        char *reply="Successfully completed\n";
        send(new_socket, reply, sizeof(reply), 0);
    }
	
	return 0; 
} 
