#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#define SERV_TCP_PORT 5035
int main(int argc,char**argv)
{
       int sockfd,newsockfd,clength;
       struct sockaddr_in serv_addr,cli_addr;
       char buffer[4096];
       int l;
       //char cli_addr[4096];
       pid_t pid;
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=INADDR_ANY;
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nStart");
       bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       printf("\nListening...");
       printf("\n");
       l=listen(sockfd,2);
       if(l==-1)
       {
       	printf("Terminate session.\n");
       	exit(0);
       }
       
       clength=sizeof(cli_addr);
       
       FILE *fp;
       
       while(1){
	       newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
	       printf("\nAccepted");
	       printf("\n");
	       if(pid==fork()==0)
	       {
	       		close(sockfd);
	       		read(newsockfd,buffer,4096);
	       		printf("Accepting connection from Client with socket address %s:%d", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
	       		fp=fopen("doc.txt", "w+");
	       		fwrite(buffer, 1, sizeof(buffer), fp);
	       }
	       else
	       {
	       		
	       		fgets(buffer, sizeof(buffer), fp);
	       		printf("%c", buffer);
	       		write(newsockfd, buffer, 4096);
	       }
	       
	       
	       /*printf("\nClient message:%s",buffer);
	       write(newsockfd,buffer,4096);
	       printf("\n");
	       if(strcmp(buffer,"exit")==10) break;*/
       }
       close(sockfd);
       return 0;
}
