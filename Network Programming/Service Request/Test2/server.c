#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>

void swap(int *x, int *y)
{

int temp=*x;
*x=*y;
*y=temp;
}

int main()
{

int s, r, rec, sen, x;
int ca;
int n;

printf("Enter the port number:\n");
scanf("%d", &x);

socklen_t len;

struct sockaddr_in server, client;
int buff[50];

//socket creation
s= socket(AF_INET, SOCK_DGRAM, 0);
if(s==-1)
{
printf("Error in socket creation.");
exit(0);
}

printf("Socket created.");

server.sin_family=AF_INET; //family IP
server.sin_port= htons(x);//port number of the server
server.sin_addr.s_addr=htonl(INADDR_ANY);//IP address of the server assigned by kernel
len=sizeof(client);
ca=sizeof(client);

r=bind(s, (struct sockaddr*)&server, sizeof(server));//binding the server to a port number and IP address

if(r==-1)
{
printf("Binding error.\n");
exit(0);
}

printf("Socket binded.\n");


rec=recvfrom(s, buff, sizeof(buff), 0, (struct sockaddr*)&client, &ca);
if(rec==-1)
{
printf("Recieving error.\n");
close(s);
exit(0);
}
printf("Message recieved.\n");
for(int i=0; i<sizeof(buff); i++)
{
printf(buff[i]);
printf("\n");
}

n= sizeof(buff);

for(int i=0; i<n; i++)
{
for(int j=0; j<n-i-1; j++)
{
if(buff[j+1]>buff[j])
swap(j, j+1);
}
}
//if(!strcmp(buff, "stop"))
//break;

printf("\n\n");
printf("Type Message: ");
scanf("%s", buff);

sen= sendto(s, buff, sizeof(buff), 0, (struct sockaddr*)&client, len);

if(sen==-1)
{
printf("Sending error.");
close(s);
exit(0);
}
printf("Message sent\n");

//if(!strcmp(buff, "stop"))
//break;

close(s);
}

