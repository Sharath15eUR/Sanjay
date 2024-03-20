#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main(){

	int sockfd, sockclient, port=6080;
	struct sockaddr_in serv, cliaddr;
	socklen_t clientlen;
	char buf[100];
	
	if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0)
	{
		printf("\nServer Can't open socket");
		exit(0);
	}
	
	bzero(&serv,sizeof(serv));
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(port);
	
	if(bind(sockfd, (struct sockaddr*)&serv, sizeof(serv))<0)
	{
		printf("Server Bind Failed !!");
		exit(0);
	}
	
	int len = sizeof(cliaddr);
	recvfrom(sockfd,buf, sizeof(buf), 0, (struct sockaddr*)&cliaddr, &len);
	printf("\nMessage from Client is: %s \n", buf);
	close(sockfd);
	return 0;
}
