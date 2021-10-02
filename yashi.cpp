nclude<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<string>
#include<cstdlib>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
using namespace std;

int main()
{
		int server_socket;
			server_socket=socket(AF_INET,SOCK_STREAM,0);

				struct sockaddr_in server_address;
					server_address.sin_family = AF_INET;
						server_address.sin_port = htons(10000);
							server_address.sin_addr.s_addr = INADDR_ANY;
								bind(server_socket,(struct sockaddr*)&server_address,sizeof(struct sockaddr_in));
									listen(server_socket,10);
										int client_socket;
											client_socket = accept(server_socket,NULL,NULL);
												printf("this is the server site");
													while(1)
															{
																	       char s[100],q[100];

																	       		recv(client_socket,s,sizeof(s),0);
																			               printf("the ip address obtained is");
																				                      printf("%s",s);
																						      		if(strlen(s)==22)
																											{
																															for(int i=0;i<=4;i++)
																																				q[i]=s[i];
																																		for(int i=5;i<=8;i++)
																																							q[i]='0';
																																					for(int i=9;i<=14;i++)
																																										q[i]=s[i-3];
																																								for(int i=15;i<=28;i++)
																																												{
																																																	if(i==19 || i==24)
																																																							q[i]=':';
																																																					else
																																																											q[i]='0';
																																																								}
																																											for(int i=29;i<=38;i++)
																																																q[i]=s[i-17];
																																													}
																										else
																													{
																																	for(int i=0;i<=5;i++)
																																						q[i]=s[i];
																																				for(int i=6;i<=11;i++)
																																									q[i]=s[i+3];
																																							for(int i=12;i<=21;i++)
																																												q[i]=s[i+17];

																																									}
																												send(client_socket,q,sizeof(q),0);
																														s[22]='\0';
																																q[22]='\0';
																																	}
														close(server_socket);
															return 0;
}
