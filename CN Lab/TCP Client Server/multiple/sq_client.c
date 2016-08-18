// ...

/**
 *	TCP from client side
 *	socket() -> connect() -> read() -> write()
 */

#include "common.h"

#define SERVER "127.0.0.1"

void commit_suicide(string message) {
	perror(message);
	exit(7);
}

int main (int argc, char const * argv []) {
	
	sockaddr_in_t server_address;
	
	int sockfd, i;
	socklen_t slen = sizeof(server_address);
	
	int *input = (int *)malloc(BUFLEN);
	int *output = (int *)malloc(BUFLEN);
	int *pid = (int *)malloc(BUFLEN);
	
	// create a UDP server
	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		commit_suicide("socket()");
	}
	// zero out the structure
	memset((char *)&server_address, 0, slen);
	
	// set family and port
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = inet_addr(SERVER);
	
	// get address
	if (connect(sockfd, (sockaddr_p_t)&server_address, slen) < 0) {
		commit_suicide("connect()");
	}

	printf("Enter the number: ");
	scanf(" %d", input);
	
	// try sending some data to the server
	if (write(sockfd, input, BUFLEN) < -1) {
		commit_suicide("write()");
	}

	sleep(1);
	
	// blocking call; try getting data from the server
	if (read(sockfd, output, BUFLEN) < -1) {
		commit_suicide("recvfrom()");
	}
	// blocking call; try getting data from the server
	if (read(sockfd, pid, BUFLEN) < -1) {
		commit_suicide("recvfrom()");
	}
	
	printf("Server [%s:%d] said: %d * %d = %d\n", inet_ntoa(server_address.sin_addr), *pid, *input, *input, *output);
	
	close(sockfd);

	return 0;
}