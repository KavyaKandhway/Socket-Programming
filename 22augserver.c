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
int main()
{
  FILE *fptr;
  fptr=fopen("India.txt","a");
  
    if(fptr==NULL)
    printf("CN't open text file\n");
    
    else
    printf("TExt file is in access\n");
    
    fputs("Rajasthan-Jaipur",fptr);
      fputs("\n",fptr);
       fputs("MP-Bhopal",fptr);
       fputs("\n",fptr);
          fputs("UP-Luckhnow",fptr);
          fputs("\n",fptr);
             fputs("Bihar-Patna",fptr);
             fputs("\n",fptr);
                fputs("Jharkhand-Ranchi",fptr);
                fputs("\n",fptr);
    
fclose(fptr);

    
    
    
    
int ssock,csock;
// creating server and client socket discriptor
int a,b,c;
char r[15];
char s[40];
//char ans[15];
unsigned int len;
struct sockaddr_in server,client;
// creating server & client socket object
if((ssock=socket(AF_INET,SOCK_STREAM,0))==-1)
// creating socket
{
perror("socket: ");
exit(-1);
}
server.sin_family=AF_INET;
server.sin_port=htons(10000);
// initializing server socket parameters.
server.sin_addr.s_addr=INADDR_ANY;
bzero(&server.sin_zero,0);
// appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'.
len=sizeof(struct sockaddr_in);
if((bind(ssock,(struct sockaddr *)&server,len))==-1)
// binding port & IP
{
perror("bind error: ");
exit(-1);
}
if((listen(ssock,5))==-1)
// listening for client
{
perror("listen error: ");
exit(-1);
}
if((csock=accept(ssock,(struct sockaddr *)&client,&len))==-1)
// accepting connection
{
perror("accept error: ");
exit(-1);
}

fptr=fopen("India.txt","a+");

while(1)
{
char rec[15];
char sd[40];
char ans[15];
char and[15];
and[0]='\0';
int fl=0;
recv(csock,&rec,sizeof(rec),0);
//recv(csock,&b,sizeof(b),0);

while((fgets(sd,40,fptr)!=NULL))
{
  printf("%s\n",sd);
  int f=1;
  int i;
  for(i=0;rec[i]!='\0';i++)
  if(rec[i]!=sd[i])
  {
    f=0;
    break;
    }
    
    if(f==1)
    {
      int k=0;
      i++;
      for(i;sd[i]!='\0';i++)
       ans[k++]=sd[i];
       
       ans[k]='\0';
       send(csock,&ans,sizeof(ans),0);
       fl=1;
       break;
       }
       
  }
  
  if(fl==0)
  {
    send(csock,&and,sizeof(and),0);
    char temp[15];
    recv(csock,&temp,sizeof(temp),0);
    
  fputs(rec,fptr);
  fputs("-",fptr);
  fputs(temp,fptr);
  fputs("\n",fptr);
  
  }
 
      
// sending data to client.
//printf("\nsent sum=: %d\n",c);
}

fclose(fptr);
close(ssock);
}

