#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>

#define PORT 2000
#define SIZE 100
int sum[SIZE];

void swap(int *x, int *y)
{
	int temp;
	temp= *x;
	*x=*y;
	*y=temp;
}

int sub(int *arr, int x)
{
	int i=0;
	int j=0;
	int n=sizeof(arr)/sizeof(arr[0]);
	//int sum[n];
	while(i<n && j<n)
	{
	
		if(x>=arr[i])
		{
			x=x-arr[i];
			sum[j]=arr[i];
			if(x==0)
			{
				break;
			}
			j++;
			i++;
		}
		else
		{
			i++;
		}

	}
	
	printf("{ ");
	for(int k=0; k<n; k++)
	{
		printf("%d", sum[k]);
		printf(", ");
	}
	printf("}");
	
	return sum;
}


int main()
{

int sockfd, newsockfd, r;
int b, l, rec, sen;

struct sockaddr_in client, server;
int buff[SIZE];
int ch[1];
//int sum[SIZE];

sockfd=socket(AF_INET, SOCK_STREAM, 0);

if(sockfd==-1)
{
	printf("Error in socket creation.\n");
	exit(0);
}
printf("Socket created.\n");

server.sin_family= AF_INET;
server.sin_addr.s_addr= INADDR_ANY;
server.sin_port= htons(PORT);

socklen_t slen, clen;
slen= sizeof(server);
clen=sizeof(client);

b=bind(sockfd, (struct sockaddr*)&server, slen);
if(b==-1)
{
	printf("Error in binding.\n");
	exit(0);
}
printf("Socket Bound.\n");

l=listen(sockfd, 5);
if(l==-1)
{
	printf("Error in listening.\n");
	exit(0);
}
printf("Listening.\n");


newsockfd= accept(sockfd, NULL, NULL);
if(newsockfd==-1)
{
	printf("Error in accepting.\n");
	exit(0);
}


while(1)
{
	printf("Accepting.\n");
	read(newsockfd, &buff, SIZE);
	read(newsockfd, &ch, 1);
	
	int i, j, n;
	n=sizeof(buff)/sizeof(buff[0]);
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			if(buff[j+1]>buff[j])
				swap(buff[j], buff[j+1]);
		}
	}
	
	int x= ch[0];
	
	printf("The smallest subarray is: ");	
	sub(buff, x);
	write(newsockfd, sum, SIZE);	
}
close(newsockfd);
close(sockfd);
return 0;
}





