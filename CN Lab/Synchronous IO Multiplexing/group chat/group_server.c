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

	int sockfd, nsckfd = -1, i, j;
	socklen_t clen = sizeof(server_address);

	char *buffer = (char *)malloc(BUFLEN * sizeof(char));

	int pid;

	fd_set master, rfds;
	int fdmax;
	struct timeval tv;
	int retval, rlen;

	FD_ZERO(&master);
	FD_ZERO(&rfds);

	tv.tv_sec = 5; // Wait for 5 seconds
	tv.tv_usec = 0;

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
	if (listen(sockfd, 1000) < 0) {
		commit_suicide("listen()");
	}

	FD_SET(sockfd, &master);
	fdmax = sockfd;

	while (YES) {

		rfds = master;

		// Select among the connected sockets.
		if (select(fdmax + 1, &rfds, NULL, NULL, NULL) == -1) {
			commit_suicide("select()");
		} else {
			printf("Server [%s:%d] waiting...\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));
		}

		// Loop though all the sockets.
		for (i = 0; i <= fdmax; ++i) {

			if (FD_ISSET(i, &rfds)) {
				
				if (i == sockfd) {

					if ((nsckfd = accept(sockfd, (sockaddr_p_t)&client_address, &clen)) == -1) {
						commit_suicide("accept()");
					} else {
						printf("Server accepting...\n");
						FD_SET(nsckfd, &master);
						if (nsckfd > fdmax)
							fdmax = nsckfd;
						printf("New connection [%s] on socket [%d].\n", inet_ntoa(client_address.sin_addr), nsckfd);
					}

				} else {

					if ((rlen = recv(i, buffer, BUFLEN, 0)) <= 0) {
						
						if (rlen == 0) {
							printf("Client on socket %d hung up.\n", i);
						} else {
							commit_suicide("recv()");
						}
						close(i);
						FD_CLR(i, &master);

					} else {

						for (j = 0; j <= fdmax; ++j) {

							if (FD_ISSET(j, &master)) {
								
								// destination != sender, we don't want to echo back message to the sender.
								if (j != i && j != sockfd) {

									printf("[%d]: %s.\n", j, buffer);

									if (send(j, buffer, BUFLEN, 0) < 0) {
										commit_suicide("send()");
									}
									
								}
								
							}
						}
					}
				}
			}
		}
	}

	close(sockfd);

	return 0;
}