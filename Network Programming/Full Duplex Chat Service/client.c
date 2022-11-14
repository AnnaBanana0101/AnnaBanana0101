#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>


int main()
{
int s, ns, x;
struct sockaddr_in client, server;

char buff[4096];
printf("Enter the port number: \n");
scanf("%d", &x);

s=socket(AF_INET, SOCK_STREAM, 0);
server.sin_family=AF_INET;
server.sin_addr.s_addr= inet_addr("127.0.0.1");
server.sin_port= htons(x);

printf("Ready for sending\n");
connect(s,(struct sockaddr*)&server, sizeof(server));
pid_t pid, ppid;
pid=fork();
while(1)
{
if(pid==0)
{
printf("Enter the message: \n");
printf("Client: ");
scanf("%s", buff);
printf("\n");
write(s, buff, sizeof(buff));
if(!strcmp(buff, "BYE"))
break;
}

else
{
read(s, buff, sizeof(buff));
printf("\nServer Message: ");
//scanf("%s",buff);
printf("%s", buff);
printf("\n");
if(!strcmp(buff, "BYE"))
break;
}
}
close(s);
}
