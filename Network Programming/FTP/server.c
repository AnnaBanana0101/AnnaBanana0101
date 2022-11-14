#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#define PORT 2000
int main()
{
int s, ns, recb;

struct sockaddr_in server, client;
char buff[1024];
char buffer[4096];

strcpy(buff, "");
strcpy(buffer, "");

s=socket(AF_INET, SOCK_STREAM, 0);
printf("Socket created.\n");
server.sin_family= AF_INET;
server.sin_addr.s_addr=INADDR_ANY;
server.sin_port=htons(PORT);

socklen_t slen, clen;

slen=sizeof(server);
clen=sizeof(client); 

bind(s, (struct sockaddr*)&server, &slen);
printf("Socket bound.\n");
listen(s,5);
printf("Listening\n");

ns=accept(s, (struct sockaddr*)&client,&clen);
printf("Accepting\n");
while(1){

/*read(ns, buff, 1024);
printf("%s", buff);*/

recb=recv(ns, buff, sizeof(buff), 0);
if(recb==-1)
printf("Rec error\n");
FILE *fp;
fp=fopen(buff, "r");

if(fp==NULL)
printf("The file doesn't exist\n");
else
printf("The file exists.\n");

while(fgets(buffer, sizeof(buffer), fp)!=NULL)
printf("%s", buffer);

fclose(fp);

//write(ns, buffer, 4096);
}
close(ns);
close(s);
}
