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

	char *buffer = (char *)malloc(BUFLEN * sizeof(char));

	int pid;

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
		if ((nsckfd = accept(sockfd, (sockaddr_p_t)&client_address, &clen)) < 0) {
			commit_suicide("accept()");
		}

		if ((pid = fork()) == 0) {

			close(sockfd);

			printf("Client [%s:%d] requested time.\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
			
			// Get the time string
			time_t tme = time(NULL);
			buffer = ctime(&tme);

			if (write(nsckfd, buffer, BUFLEN) < 0) {
				commit_suicide("write()");
			}

			close(nsckfd);
			exit(0);

		} else if (pid < 0) {
			commit_suicide("fork()");
		} else {
			close(nsckfd);
		}

	}

	close(sockfd);

	return 0;
}