#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
int main()
{
int sock;
// client socket discriptor
int a,b,c,i;

unsigned int len;
char ch[3]="no";
char ch1[3];
struct sockaddr_in client;
if((sock=socket(AF_INET,SOCK_STREAM,0))==-1)
// client socket is created.
{
perror("socket: ");
exit(-1);
}
client.sin_family=AF_INET;
client.sin_port=htons(10000);
// initializing socket parameters
client.sin_addr.s_addr=INADDR_ANY;
bzero(&client.sin_zero,0);
// appending 8 byte zeroes to 'struct sockaddr_in', to make it equal in size with 'struct sockaddr'.
len=sizeof(struct sockaddr_in);
if((connect(sock,(struct sockaddr *)&client,len))==-1)
//connecting to client
{
perror("connect: ");
exit(-1);
}
while(1)
{
char s[15];
char r[15];
printf("enter the state name:\n");
scanf("%s",&s);
send(sock,&s,sizeof(s),0);
//send(sock,&b,sizeof(b),0);
// sending data back to client.
recv(sock,&r,sizeof(r),0);
// receiving data from client

if(r[0]=='\0')
{
char t[15];
  printf("enter the capital name:\n");
  scanf("%s",&t);
  send(sock,&t,sizeof(t),0);
 }
 
 else
 {

printf("capital is %s\n",r);
}
printf("\nTo exit...press 'no'\n");
scanf("%s",ch1);
if((i=strcmp(ch,ch1))==0)
{
close(sock);
exit(0);
}
}
}
