#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <arpa/inet.h>

int main() {
	
	int sockfd, n, port = 8080;
	struct sockaddr_in serv;
	char buf[100],msg[100];

	 if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0){
                printf("\nServer cannot open Socket!!");
                exit(0);
        }

        bzero(&serv,sizeof(serv));
        serv.sin_family=AF_INET;
        serv.sin_port=htons(port);

	if(connect(sockfd, (struct sockaddr*)&serv, sizeof(serv))<0)
	{
		  printf("\nConnection failed!!");
                exit(0);
        }
	
	printf("\nConnected");
	printf("\nEnter the msg to server: ");
	scanf("%s",buf);
	write(sockfd,buf,100);
	n = read(sockfd,msg,100);
	printf("\nMessage from server is: %s \n", msg);
	return 0;

}
