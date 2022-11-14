#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main()
{
int s, r, ns, rec, sen, x, a=0;

struct sockaddr_in server, client;
char buff[4096];
printf("Port number:\n");
scanf("%d", &x);

s= socket(AF_INET, SOCK_STREAM, 0);
server.sin_family=AF_INET;
server.sin_addr.s_addr=INADDR_ANY;
server.sin_port=htons(x);

printf("Start\n");
bind(s, (struct sockaddr*)&server, sizeof(server));
printf("Listening\n");
listen(s, 5);
ns=accept(s, (struct sockaddr*)&client, sizeof(client));

pid_t pid, ppid;
pid=fork();

while(1)
{
if(pid==0)
{
printf("Accepting\n");

read(ns, buff, 4096);
printf("Client Message: ");
printf("%s", buff);
printf("\n");
if(!strcmp(buff, "BYE"));
break;
}
else
{
//printf("Accepting\n");
printf("Type Server Message: \n");
scanf("%s", buff);
printf("\n");
write(ns, buff, 4096);
if(!strcmp(buff, "BYE"))
{break;}
}
}
close(ns);
close(s);
}

