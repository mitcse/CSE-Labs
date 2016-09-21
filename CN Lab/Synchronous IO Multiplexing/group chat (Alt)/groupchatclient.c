#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

int main() {
		int sd, status;
		struct sockaddr_in address;
		sd = socket(AF_INET, SOCK_STREAM,0);
		address.sin_family = AF_INET;
		address.sin_addr.s_addr = inet_addr("127.0.0.1");
		address.sin_port = htons(19999);
		char buf[25];
		connect(sd, (struct sockaddr*) &address, sizeof(address));
		int pid;
		pid = fork();
		if(pid == 0) {
			while(1) {
				printf("The client sent : \n");
				gets(buf);
				send(sd, buf, sizeof(buf), 0);
			}
		}
		else {
			while(1) {
				if(recv(sd, buf, sizeof(buf), 0) != -1) {
					printf("The server sent : \n");
					puts(buf);
				}
			}
		}
		return 0;
}
