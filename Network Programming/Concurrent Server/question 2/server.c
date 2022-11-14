#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#define SERV_TCP_PORT 5035

int isAnagram(char a[], char b[])
{
	int num1[26]={0};
	int num2[26]={0};
	int i=0;
	
	while(a[i]!='\0')
	{
		num1[a[i]-'a']++;
		i++;
	}
	i=0;
	while(b[i]!='\0')
	{
		num2[b[i]!='\0']++;
		i++;
	}
	
	for(i=0; i<26; i++)
	{
		if(num1[i]!=num2[i])
		return 0;
	}
	return 1;
}



int main(int argc,char**argv)
{
       int sockfd,newsockfd,clength;
       struct sockaddr_in serv_addr,cli_addr;
       char buffer[4096];
       char buffer2[4096];
       char buff[4096];
       bzero(buffer, sizeof(buffer));
       bzero(buffer, sizeof(buffer2));
       bzero(buffer, sizeof(buff));
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
       
       while(1){
	       newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
	       while(1)
	       {
		       printf("\nAccepted");
		       printf("\n");
		       read(newsockfd,buffer,4096);
		       read(newsockfd, buffer2, 4096);
		       int x;
		       x= isAnagram(buffer, buffer2);
		       if(x==1)
		       		strcpy(buff, "Anagram\n");
		       else
		       		strcpy(buff, "Not an anagram\n");
		       		
		       	write(newsockfd, buff, sizeof(buff));
		       /*printf("\nClient message:%s",buffer);
		       write(newsockfd,buffer,4096);
		       printf("\n");*/
		       if(strcmp(buffer,"exit")==10) break;
	       }
	       close(newsockfd);
       }
       close(sockfd);
       return 0;
}
