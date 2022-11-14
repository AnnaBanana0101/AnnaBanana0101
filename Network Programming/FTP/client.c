#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netdb.h>
#define PORT 2000

int main()
{
int s, r, w;

struct sockaddr_in client, server;
char buff[1024];
char buffer[4096];

strcpy(buff, "");
strcpy(buffer, "");

socklen_t clen, slen;

s=socket(AF_INET, SOCK_STREAM, 0);
server.sin_family=AF_INET;
server.sin_addr.s_addr=inet_addr("127.0.0.1");
server.sin_port=htons(PORT);
clen=sizeof(client);
slen=sizeof(server);

connect(s, (struct sockaddr*)&server, slen);
printf("Socket connected.\n");

while(1)
{
printf("Enter the filename:\n");
scanf("%s", buff);

/*w=write(s, buff, 1024);
if(w==-1)
printf("Write error");*/
send(s, buff, sizeof(buff), 0);

printf("Contents of the file:\n");

/*r=read(s, buffer, 4096);
if(r==-1)
printf("Read error");*/
recv(s, buffer, sizeof(buffer), 0);

printf("%s", buffer);

if(!strcmp(buff, "End"))
break;
}
close(s);
}
