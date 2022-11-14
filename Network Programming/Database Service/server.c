#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#define SERV_TCP_PORT 5035


struct Books
{
	char title[50];
	char author[50];
	int ID;
};

int main(int argc,char**argv)
{

       int sockfd,newsockfd,clength;
       int size, sa, st, si;
       struct Books book[100];
       struct sockaddr_in serv_addr,cli_addr;
       char buffer[4096];
       int opt[1];
       char title[50];
       char auth[50];
       int ID[1];
       opt[0]=0;
       ID[0]=0;
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
       newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
       size=sizeof(buffer);
       st=sizeof(title);
       sa=sizeof(auth);
       si=sizeof(ID);
       
       while(1){
	       printf("\nAccepted");
	       printf("\n");
	       read(newsockfd,opt,sizeof(opt));
	       printf("\nOption:%d",opt[0]);
	       
	       int x;
	       x=opt[0];
	       int n=sizeof(book)/sizeof(book[0]);
	       int z=-1;
	       switch(x)
	       {
	       		case 1: 
		       		printf("\nInsert book info:\n");
		       		strcpy(buffer, "Insert: ");
		       		write(newsockfd, buffer, size);
		       		
		       		read(newsockfd, title, &st);
		       		read(newsockfd, auth, &sa);
		       		read(newsockfd, ID, &si);
		       		
		       		strcpy(book[z++].title, title);
		       		strcpy(book[z].author, auth);
		       		book[z].ID=ID[0];
		       		
		       		strcpy(buffer, "Enterered details.");
		       		write(newsockfd, buffer, size);
		       		break;
		       		
	       		case 2:
	       			strcpy(buffer, "Enter book title: ");
	       			write(newsockfd, buffer, size);
	       			printf("\nDeleting book\n");
	       			read(newsockfd, buffer, &size);
	       			for(int i=0; i<n; i++)
	       			{
	       				if(strcmp(book[i].title, buffer)==0)
	       				{
	       					for(int j=i; j<n;j++)
	       					{
		       					strcpy(book[i].title,book[i+1].title);
		       					strcpy(book[i].author,book[i+1].author);
		       					book[i].ID=book[i+1].ID;
	       					}
	       					n--;
	       					break;
	       				}
	       			}
	       			printf("\nDeleted\n");
	       			strcpy(buffer, "Deleted");
	       			write(newsockfd, buffer, size);
	       			break;
	       			
	       		case 3:
	       			strcpy(buffer, "Enter the book title: ");
	       			write(newsockfd, buffer, size);
	       			printf("\nDisplaying book info:\n");
	       			read(newsockfd, buffer, &size);
	       			for(int i=0; i<n; i++)
	       			{
	       				if(strcmp(book[i].title, buffer)==0)
	       				{
	       					strcpy(title, book[i].title);
	       					strcpy(auth, book[i].author);
	       					ID[0]=book[i].ID;
	       					break;
	       				}
	       			}
	       			write(newsockfd, title, st);
	       			write(newsockfd, auth, sa);
	       			write(newsockfd, ID, si);
	       			break;
	       			
	       		case 4:
	       			strcpy(buffer, "Enter the book title: ");
	       			write(newsockfd, buffer, size);
	       			printf("\nSearching:\n");
	       			read(newsockfd, buffer, &size);
	       			int flag=0;
	       			for(int i=0; i<n; i++)
	       			{
	       				if(strcmp(book[i].title, buffer)==0)
	       				{
	       					strcpy(title, book[i].title);
	       					strcpy(auth, book[i].author);
	       					ID[0]=book[i].ID;
	       					flag=1;
	       					break;
	       				}
	       			}
	       			if(flag==1)
	       			{
	       			
		       			strcpy(buffer, "Book found.");
		       			write(newsockfd, buffer, size);
		       			write(newsockfd, title, st);
		       			write(newsockfd, auth, sa);
		       			write(newsockfd, ID, si);
	       			}
	       			else
	       			{
	       				strcpy(buffer, "Book found.");
	       				write(newsockfd, buffer, size);
	       			}
	       			break;
	       		
	       		case 5:
	       		        printf("Exiting.");
	       		        strcpy(buffer, "Exit, Thank you.");
		       		write(newsockfd, buffer, size);
	       			break;	
	       }
       }
       close(sockfd);
       return 0;
}
