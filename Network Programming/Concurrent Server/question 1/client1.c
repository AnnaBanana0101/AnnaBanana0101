#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035

int sockfd,size;
       struct sockaddr_in serv_addr;
       struct hostent *server;
       char buffer[4096];
       int opt[1];
       int x;
       
 void Insert()
 {
 	printf("%s", buffer);
		       		printf("\nTitle: ");
		       		scanf("%s", buffer);
		       		write(sockfd, buffer, size);
		       		
		       		printf("\nAuthor: ");
		       		scanf("%s", buffer);
		       		write(sockfd, buffer, size);
		       		
		       		printf("\nID: ");
		       		scanf("%d", opt);
		       		write(sockfd, opt, sizeof(opt)*sizeof(int));
 }
 
 void Delete()
 {
 	printf("%s", buffer);
		       		scanf("%s", buffer);
		       		write(sockfd, buffer, size);
 }
 
 void Display()
 {
 	printf("%s", buffer);
	       			scanf("%s", buffer);
		       		write(sockfd, buffer, size);
 }
 
 void Search()
 
{
	printf("%s", buffer);
	       			scanf("%s", buffer);
		       		write(sockfd, buffer, size);
}

void Exit()
{
	printf("%s", buffer);
}
       
       
       
int main(int argc,char*argv[])
{
       
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nReady for sending...");
       connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       size=sizeof(buffer);
       while(1){
	       printf("\nEnter the option:\n");
	       printf("1.Insert\n");
	       printf("2.Delete\n");
	       printf("3.Display\n");
	       printf("4.Search\n");
	       printf("5.Exit\n");
	       
	       scanf("%d", &x);
	       opt[0]=x;
	       write(sockfd,opt, sizeof(opt)*sizeof(int));
	       read(sockfd, buffer, &size);
	       
	       
	       if(x==1)
	       {
	       		Insert();
	       		break;
	       }
	       else if(x==2)
	       {
	       		Delete();
	       		break;
	       }
	       else if(x==3)
	       {
	       		Display();
	       		break;
	       }
	       else if(x==4)
	       {
	       		Search();
	       		break;
	       }
	       else if(x==5)
	       {
	       		Exit();
	       		break;
	       }
	       /*switch(x)
	       {
	       		case 1:
		       		printf("%s", buffer);
		       		printf("\nTitle: ");
		       		scanf("%s", buffer);
		       		write(sockfd, buffer, size);
		       		
		       		printf("\nAuthor: ");
		       		scanf("%s", buffer);
		       		write(sockfd, buffer, size);
		       		
		       		printf("\nID: ");
		       		scanf("%d", opt);
		       		write(sockfd, opt, sizeof(opt)*sizeof(int));
		       		break;
	       		case 2:
	       			printf("%s", buffer);
		       		scanf("%s", buffer);
		       		write(sockfd, buffer, size);
		       		break;
	       			
	       		case 3:
	       			printf("%s", buffer);
	       			scanf("%s", buffer);
		       		write(sockfd, buffer, size);
		       		break;
	       		
	       		case 4:
	       			printf("%s", buffer);
	       			scanf("%s", buffer);
		       		write(sockfd, buffer, size);
		       		break;
	       		
	       		case 5:
	       			printf("%s", buffer);
	       			break;
	       }*/
	       
	       
	       
	       //printf("Serverecho:%s",buffer);
	       //printf("\n");
	       //if(strcmp(buffer,"exit")==10) break;
	       
	       
	       //if(x==5)
	       //break;
       }
       close(sockfd);
       return 0;
}
