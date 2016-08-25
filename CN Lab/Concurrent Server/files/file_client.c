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
	
	int *fst = (int *)malloc(sizeof(int));
	char output[BUFLEN];

	char filename[1023];
	
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

	memset(output, '\0', BUFLEN);

	printf("Enter filename: ");
	scanf(" %s", filename);
	
	// try sending some data to the server
	if (write(sockfd, filename, BUFLEN) < -1) {
		commit_suicide("write()");
	}
	
	// Get the file status from the server
	if (read(sockfd, fst, sizeof(int)) < -1) {
		commit_suicide("recvfrom()");
	}

	if (*fst == 1) {
		printf("File found on the server; contents:\n\n");
		if (read(sockfd, output, BUFLEN) < -1) {
			commit_suicide("recvfrom()");
		}
		printf("Server said: %s\n", output);
	} else {
		printf("File not found the server :(\n");
	}

	
	close(sockfd);

	return 0;
}