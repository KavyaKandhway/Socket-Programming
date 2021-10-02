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
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  	FILE *fptr;
  	fptr=fopen("Information.txt","a");
	if(fptr==NULL)
	{
		cout<<"Cannot open the text file\n";
	}
    else
    {
    	cout<<"Text file Information opened successfully\n";
	}
    fputs("Andhra Pradesh-Hyderabad\n",fptr);
    fputs("Arunachal Pradesh-Itanagar\n",fptr);
    fputs("Assam-Dispur\n",fptr);
    fputs("Bihar-Patna\n",fptr);
	fputs("Chhattisgarh-Raipur\n",fptr);
	fputs("Goa-Panaji\n",fptr);
	fputs("Gujarat-Gandhinagar\n",fptr);
	fputs("Haryana-Chandigarh\n",fptr);
	fputs("Himachal Pradesh-Shimla\n",fptr);
	fputs("Jharkhand-Ranchi\n",fptr);
	fputs("Karnataka-Bangaluru\n",fptr);
	fputs("Kerala-Thiruvananthapuram\n",fptr);
	fclose(fptr);
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
	
	address.sin_family=AF_INET; 
	address.sin_addr.s_addr=INADDR_ANY; 
	address.sin_port=htons(8090);
	bzero(&address.sin_zero,0);
	int addrlen = sizeof(struct sockaddr_in); 
	bind(server_socket,(struct sockaddr*)&address,sizeof(address));
	
	listen(server_socket, 3);
	
	int new_socket;
	new_socket = accept(server_socket, (struct sockaddr*)&address, (socklen_t*)&addrlen);
	
	if (new_socket < 0)
	{ 
		printf("error2\n");
		exit(EXIT_FAILURE); 
	} 
	fptr=fopen("Information.txt","a+");
	int valread;
	char str[100];
	char sd[40];
	char ans[40];
	bool f1=0;
	valread = read(new_socket, str, sizeof(str));
	while((fgets(sd,40,fptr)!=NULL))
	{
		cout<<sd<<endl;
  		bool f=1;
  		int i;
		for(i=0;str[i]!='\0';i++)
		{
			
			if(str[i]!=sd[i])
			{
				f=0;
			    break;
			}
		}
			
			    
		if(f==1)
    	{
     		int k=0;
      		i++;
      		for(i;sd[i]!='\0';i++)
      		{
      			ans[k]=sd[i];
      			k++;
			}
       		ans[k]='\0';
       			
       		f1=1;
       		break;
       	}
       
  	}
  	send(new_socket, &f1, sizeof(f1), 0);
  	if(f1)
  	{
  		send(new_socket,&ans,sizeof(ans),0);
	}
  	
	else
	{
	   	char temp[15];
	   	recv(new_socket,&temp,sizeof(temp),0);
		fputs(str,fptr);
	  	fputs("-",fptr);
	  	fputs(temp,fptr);
	  	fputs("\n",fptr);
	}
	fclose(fptr);
}
