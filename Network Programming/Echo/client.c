#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/stat.h>

main()
{

int s, r, rec, sen, x;
int sa;
socklen_t len;

printf("Enter the port number:\n");
scanf("%d", &x);

struct sockaddr_in server, client;
char buff[50];

s=socket(AF_INET, SOCK_DGRAM, 0);

if(s==-1)
{
printf("Socket creation error.");
exit(0);
}

printf("Socket created.\n");

server.sin_family=AF_INET;
server.sin_port=htons(x);
server.sin_addr.s_addr=inet_addr("127.0.0.1");
sa=sizeof(server);
len=sizeof(server);

while(1)
{
printf("\n\n");
printf("Type Message: ");
scanf("%s", buff);
sen= sendto(s, buff, sizeof(buff), 0, (struct sockaddr*)&server, len);

if(sen==-1)
{
printf("Sending error.");
close(s);
exit(0);
}
printf("Message sent\n");

if(!strcmp(buff, "stop"))
break;

rec=recvfrom(s, buff, sizeof(buff), 0, (struct sockaddr*)&server, &sa);

if(rec==-1)
{
printf("Receiving error.");
close(s);
exit(0);
}

printf("Message received\n");
printf("The message: %s", buff);

if(!strcmp(buff, "stop"))
break;
}

close(s);
}
