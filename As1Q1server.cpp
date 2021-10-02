
#include <netinet/in.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 

#define PORT 8090 


int main() 
{ 
	int server_fd, new_socket, valread; 
	struct sockaddr_in address; 
	char str[100]; 
	int addrlen = sizeof(address); 
	char buffer[1024] = { 0 }; 
	char* hello = "Hello from server"; 

	printf("Batcomputer Uplink.\n");
	if ((server_fd = socket(AF_INET, 
						SOCK_STREAM, 0)) == 0) { 
		perror("socket failed"); 
		exit(EXIT_FAILURE); 
	} 

	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(PORT); 

	if (bind(server_fd, (struct sockaddr*)&address, 
						sizeof(address)) < 0) { 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 


	if (listen(server_fd, 3) < 0) { 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
	if ((new_socket = accept(server_fd, 
				(struct sockaddr*)&address, 
				(socklen_t*)&addrlen)) < 0) { 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	} 


	valread = read(new_socket, str, 
				sizeof(str)); 
	int i, j, temp, flag=1; 
	int l = strlen(str); 

	printf("\nRecieved response:%s\n", str); 
    char *pass="Martha";
	for (i = 0; i<6 ; i++) { 
		if(pass[i]!=str[i] || l!=6){
            flag=0;
            break;
        }
	} 
    
    send(new_socket, &flag, sizeof(flag), 0);
    if(flag){
        valread = read(new_socket, str, 
				sizeof(str));
        printf("%s ", str);
        printf(" protocol initiated.\n");
        char *reply="Goodbye, Mr. Wayne.\n";
        send(new_socket, reply, sizeof(reply), 0);
    }

	return 0; 
} 
