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

	int sockfd, port = 6080;
	char buf[100];
	struct sockaddr_in serv;
	
	if((sockfd=socket(AF_INET,SOCK_DGRAM,0))<0){
		printf("\nConnection Failed!!!");
		exit(0);
	}
	
	bzero(&serv,sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_port=htons(port);
	
	printf("\nConnected !!");
	printf("\nEnter the message to Server: ");
	scanf("%s",buf);
	
	sendto(sockfd, buf, sizeof(buf), 0 , (struct sockaddr*)&serv, sizeof(serv));
	printf("\nMessage Sent Successfully !!\n");
	close(sockfd);
	return 0;
}
