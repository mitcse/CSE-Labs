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

	char filename[1023];

	int *fst = (int *)malloc(sizeof(int));
	char output[BUFLEN];
	
	int received_length;
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

		memset(filename, '\0', 1023);

		// blocking call; try to get some data from the client?
		if (nsckfd < 0) {
			if ((nsckfd = accept(sockfd, (sockaddr_p_t)&client_address, &clen)) < 0) {
				commit_suicide("accept()");
			}
		}

		if ((pid == fork()) == 0) {

			// read into filename
			if ((received_length = read(nsckfd, filename, 1023)) < 0) {
				commit_suicide("read()");
			}

			printf("Client [%s:%d] requested file: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), filename);
			if (access(filename, F_OK) != -1) {

				*fst = 1;
				// send status to the client
				if (write(nsckfd, fst, sizeof(int)) < 0) {
					commit_suicide("write()");
				}
				printf("File present, preparing for sending.\n");

				FILE *deadfile;
				deadfile = fopen(filename, "r");

				fseek(deadfile, 0, SEEK_END);
				size_t flen = ftell(deadfile);
				fseek(deadfile, 0, SEEK_SET);
				fread(output, sizeof(char), flen, deadfile);

				// send file data to the client.
				if (write(nsckfd, output, BUFLEN) < 0) {
					commit_suicide("write()");
				}

				fclose(deadfile);
			} else {
				*fst = 0;
				// send status to the client
				if (write(nsckfd, fst, sizeof(int)) < 0) {
					commit_suicide("write()");
				}
				printf("File not present, exiting.\n");
			}

			close(nsckfd);
			exit(0);

		} else if (pid < 0) {
			commit_suicide("fork()");
			return -2;
		} else {
			close(nsckfd);
			return -1;
		}

	}

	close(sockfd);

	return 0;
}