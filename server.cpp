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
char binaryNumber[100],hexdecnum[100];;
void DecimalToBinary(int n) {
   
   int num=n;
   int i = 0;
   while (n > 0) {
      binaryNumber[i] = n % 2 +'0';
      n = n / 2;
      i++;
   }
   
}

int DecimalToOctal(int decimalNum) {
   int octalNum = 0, placeValue = 1;
   int dNo = decimalNum;
   while (decimalNum != 0) {
      octalNum += (decimalNum % 8) * placeValue;
      decimalNum /= 8;
      placeValue *= 10;
   }
   return octalNum;
}
void DecimalToHexa(int decnum)
{
	int i=1, j, temp;
	int quot=decnum;
	while(quot!=0)
	{
		temp=quot%16;
		if(temp<10)
		{
			temp=temp+48;
		}
		else
		{
			temp=temp+55;
		}
		hexdecnum[i++]=temp;
		quot=quot/16;
	}
	
}
int BinaryToDecimal(int binnum)
{
	long int decnum=0, i=1, rem;
	while(binnum!=0)
	{
		rem=binnum%10;
		decnum=decnum+rem*i;
		i=i*2;
		binnum=binnum/10;
	}
	return decnum;
}
int octalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}
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
	int str;
	int type;
	valread = read(new_socket, &type, sizeof(type));
	cout<<"type="<<type<<endl;
	valread= read(new_socket, &str, sizeof(str));
	printf("word received\n");
	printf("\nWord entered by the user:%d\n", str); 
	if(type==1)
	{
		DecimalToBinary(str);
		send(new_socket, binaryNumber, sizeof(binaryNumber), 0); 
		int octal=DecimalToOctal(str);
		send(new_socket,&octal,sizeof(octal),0);
		//DecimalToHexa(str);
	//	send(new_socket, hexdecnum, sizeof(hexdecnum), 0); 
	}
	if(type==2)
	{
		int decimal=BinaryToDecimal(str);
		send(new_socket, &decimal, sizeof(decimal), 0); 
		int octal=DecimalToOctal(decimal);
		send(new_socket,&octal,sizeof(octal),0);
	}
	if(type==3)
	{
		int decimal=octalToDecimal(str);
		send(new_socket, &decimal, sizeof(decimal), 0); 
		DecimalToBinary(decimal);
		
		send(new_socket, binaryNumber, sizeof(binaryNumber), 0); 
	}
}
