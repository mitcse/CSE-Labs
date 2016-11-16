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

	char buffer[BUFLEN];
	char buxxer[BUFLEN];
	char filename[FLEN];

	memset(buffer, '\0', BUFLEN);

	if (read(sockfd, buffer, BUFLEN) < -1) {
		commit_suicide("recvfrom()");
	}
	
	printf("Server file list: \n");
	puts(buffer);

	printf("Enter filename: ");
	scanf(" %s", filename);

	// try sending some data to the server
	if (write(sockfd, filename, FLEN) < -1) {
		commit_suicide("write()");
	}

	if (read(sockfd, buxxer, BUFLEN) < -1) {
		commit_suicide("recvfrom()");
	}

	sleep(1);

	printf("Output: \n");
	puts(buxxer);
	
	close(sockfd);

	return 0;
}