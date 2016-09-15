// ...

/**
 *	TCP from client side
 *	socket() -> connect() -> read() -> write()
 */

#include "common.h"

void commit_suicide(string message) {
	perror(message);
	exit(7);
}

int main (int argc, char const * argv []) {
	
	sockaddr_in_t server_address;
	
	int sockfd, i;
	socklen_t slen = sizeof(server_address);
	
	char buffer[BUFLEN];
	int ch;
	
	// create a TCP server
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

	printf("1. Request time\n2. Exit\nEnter choice: ");
	scanf(" %d", &ch);

	if (ch != 1) {
		commit_suicide("Quitting...");
		return -6;	
	}
	
	// blocking call; try getting data from the server
	if (read(sockfd, buffer, BUFLEN) < -1) {
		commit_suicide("recvfrom()");
	}
	
	printf("Server said: %s\n", buffer);
	
	close(sockfd);

	return 0;
}