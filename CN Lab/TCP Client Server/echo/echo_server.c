// ...

/**
 *	TCP server side:
 *	socket() -> bind() -> listen() -> accept() -> read() -> write()
 */

#include "common.h"

void commit_suicide(string message) {
	perror(message);
	exit(7);
}

int main (int argc, char const * argv []) {
	
	sockaddr_in_t server_address, client_address;

	int sockfd, nsckfd = -1, i;
	socklen_t clen = sizeof(server_address);
	char buffer[BUFLEN];
	int received_length;

	// create a TCP Server
	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		commit_suicide("socket()");
	}
	// zero out the structure
	memset((char *)&server_address, 0, clen);

	// set family, address and port
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind socket to port
	if (bind(sockfd, (sockaddr_p_t)&server_address, clen) < 0) {
		commit_suicide("bind()");
	}

	// listen
	if (listen(sockfd, 6) < 0) {
		commit_suicide("listen()");
	}

	while (YES) {
		printf("Server [%s:%d] waiting...\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

		// reset memory buffer
		memset(buffer, '\0', BUFLEN);

		// blocking call; try to get some data from the client?
		if (nsckfd < 0) {
			if ((nsckfd = accept(sockfd, (sockaddr_p_t)&client_address, &clen)) < 0) {
				commit_suicide("accept()");
			}
		}

		// read into buffer
		if ((received_length = read(nsckfd, buffer, BUFLEN)) < 0) {
			commit_suicide("read()");
		}

		printf("Client [%s:%d] said: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);

		// reply to client with the same data, cause echo server.
		if (write(nsckfd, buffer, BUFLEN) < 0) {
			commit_suicide("write()");
		}

	}

	close(nsckfd);
	close(sockfd);

	return 0;
}