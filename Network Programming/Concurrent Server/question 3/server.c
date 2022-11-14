#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#define SERV_TCP_PORT 5035

struct route
{
	int avail;
	int booked;
};



int main(int argc,char**argv)
{
       int sockfd,newsockfd,clength;
       
       struct route destA;
       struct route destB;
       destA.avail= 20;
       destA.booked=15;
       destB.avail=15;
       destB.booked=10;
      
       struct sockaddr_in serv_addr,cli_addr;
       char buffer[4096];
       int no[1];
       int s_no=sizeof(no)*sizeof(int);
       int size=sizeof(buffer);
      
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=INADDR_ANY;
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nStart");
       bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       printf("\nListening...");
       printf("\n");
       listen(sockfd,5);
       clength=sizeof(cli_addr);
       
       pid_t pid;
       
       while(1){
	       newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
	       printf("\nAccepted");
	       printf("\n");
	       if(pid=fork()==0)
	       {
		       close(sockfd);
		       while(1)
		       {
			       printf("Accepted connection with socket address %s:%d", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
			       read(newsockfd,buffer,4096);
			       printf("\nRoute:%s",buffer);
			       read(newsockfd, no, s_no);
			       int x;
			       x=no[0];
			       printf("Number of tickets to be booked: %d",x);
			     
			       if(strcmp(buffer, 'A')==0)
			       {
			       		if(x>destA.avail)
			       		{
			       			strcpy(buffer, "Unavailable");
			       			break;
			       		}
			       		destA.avail= destA.avail-x;
			       		destA.booked= destA.booked+x;
			       		strcpy(buffer, "Seats booked.");
			       }
			       else if(strcmp(buffer, 'B')==0)
			       {
			       		if(x>destB.avail)
			       		{
			       			strcpy(buffer, "Unavailable");
			       			break;
			       		}
			       		destB.avail= destB.avail-x;
			       		destB.booked= destB.booked+x;
			       		strcpy(buffer, "Seats booked.");
			       }
			       write(newsockfd,buffer,4096);
			       printf("\n");
			       if(strcmp(buffer,"exit")==10) break;
		       }
	       }
       }
       close(sockfd);
       return 0;
}
