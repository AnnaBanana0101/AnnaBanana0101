#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 2000
#define SIZE 100

int main()
{
	int sockfd, c;
	struct sockaddr_in client, server;
	int buff[SIZE];
	int ch[1];
	
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd==-1)
	{
		printf("Socket creation error.\n");
		exit(0);
	}
	printf("Socket connected.\n");
	
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(PORT);
	
	socklen_t slen; 
	slen=sizeof(server);
	
	c=connect(sockfd, (struct sockaddr*)&server, slen);
	if(c==-1)
	{
		printf("Socket connection error.\n");
		exit(0);
	}
	printf("Connection established.\n");
	while(1)
	{
		printf("Enter the array of numbers:\n");
		
		for(int i=0; i<SIZE; i++)
			scanf("%d", buff[i]);
		
		int x;
		
		printf("Enter the target element:\n");
		scanf("%d", &x);
		ch[0]=x;
		printf("Sending to the server:\n");
		write(sockfd, buff, SIZE);
		write(sockfd, ch, 1);
		
		read(sockfd, &buff, SIZE);
		printf("The smallest subarray is: \n");
		int n= sizeof(buff)/sizeof(buff[0]);
		printf("{ ");
		for(int i=0; i<n; i++)
		{
			printf("%d", buff[i]);
			printf(", ");
		}
		printf("}");		
	}
	close(sockfd);
	return 0;	
}
