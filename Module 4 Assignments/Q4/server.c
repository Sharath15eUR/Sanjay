#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(){

	int sockfd, sockclient, port=8080, len = 80;
	struct sockaddr_in serv, cliaddr;
	socklen_t clientlen;
        if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
		printf("\nServer cannot open Socket!!");
		exit(0);
	}

	bzero(&serv,sizeof(serv));
	serv.sin_family=AF_INET;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(port);

	if((bind(sockfd, (struct sockaddr*)&serv, sizeof(serv)))<0)
	{
		printf("\nServer bind failed!!");
		exit(0);
	}

	listen(sockfd,5);

	if((sockclient=accept(sockfd, (struct sockaddr*)&cliaddr, &clientlen))<0){
		printf("\nClient is bad");
		exit(0);
	}

	char buf[len];
	char str[10];
	bzero(buf,len);
	int n = read(sockclient,buf,100);
	printf("\nMessage from client is: %s ", buf);
	printf("\nEnter msg to client: ");
	scanf("%s", str);
	strcpy(buf,str);
	write(sockclient, buf, 100);
	return 0;
}
