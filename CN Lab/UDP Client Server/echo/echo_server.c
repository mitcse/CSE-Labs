// ...

/**
 *	UDP server side:
 *	socket() -> bind() -> recvfrom() -> sendto()
 */

#include "common.h"

void commit_suicide(string message) {
	perror(message);
	exit(7);
}

int main (int argc, char const * argv []) {
	
	sockaddr_in_t server_address, client_address;

	int sockfd, i;
	socklen_t server_len = sizeof(server_address), received_length;
	char buffer[BUFLEN];

	// create a UDP Server
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
		commit_suicide("socket()");
	}
	// zero out the structure
	memset((char *)&server_address, 0, server_len);

	// set family, address and port
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);

	// bind socket to port
	if (bind(sockfd, (sockaddr_p_t)&server_address, server_len) == -1) {
		commit_suicide("bind()");
	}

	while (YES) {
		printf("Server waiting...\n");

		// blocking call; try to get some data from the client?
		if ((received_length = recvfrom(sockfd, buffer, BUFLEN, 0, (sockaddr_p_t)&client_address, &server_len)) == -1) {
			commit_suicide("recvfrom()");
		}
		printf("Client [%s:%d] said: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);
		
		memset(buffer, '\0', BUFLEN); // reset memory buffer

		// reply to client with the same data, cause echo server.
		if (sendto(sockfd, buffer, received_length, 0, (sockaddr_p_t)&client_address, server_len) == -1) {
			commit_suicide("sendto()");
		}
	}

	close(sockfd);
	return 0;
}