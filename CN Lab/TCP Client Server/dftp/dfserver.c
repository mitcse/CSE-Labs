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

	pid_t pid;

	int received_length;

	// create a UDP Server
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

	char buffer[BUFLEN];
	char buxxer[BUFLEN];

	while (YES) {
		
		printf("Server [%s:%d] waiting...\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

		// reset memory buffer
		memset(buffer, '\0', BUFLEN);

		// blocking call; try to get some data from the client?
		if ((nsckfd = accept(sockfd, (sockaddr_p_t)&client_address, &clen)) < 0) {
			commit_suicide("accept()");
		}

		pid = fork();
		if (pid == 0) {

			close(sockfd);

			system("ls -A1 files/ | grep .c > lsoutput.txt");

			FILE *lsoutput = fopen("lsoutput.txt", "r");
			fseek(lsoutput, 0, SEEK_END);
			size_t len = ftell(lsoutput);
			fseek(lsoutput, 0, SEEK_SET);
			fread(buffer, sizeof(char), len, lsoutput);

			if (write(nsckfd, buffer, BUFLEN) < 0) {
				commit_suicide("write()");
			}

			char fname[FLEN];
			memset(fname, '\0', FLEN);

			// read into buffer
			if ((received_length = read(nsckfd, fname, FLEN)) < 0) {
				commit_suicide("read()"); // Some error here?
			}

			char command[FLEN];
			memset(command, '\0', FLEN);
			snprintf(command, FLEN, "gcc -o tmp.o files/%s", fname);
			printf("Executing \'%s\'\n", command);

			system(command);

			system("./tmp.o > temp.txt");

			memset(buffer, '\0', BUFLEN);

			FILE *output = fopen("temp.txt", "r");
			fseek(output, 0, SEEK_END);
			len = ftell(output);
			fseek(output, 0, SEEK_SET);
			fread(buxxer, sizeof(char), len, output);

			printf("File output: ");
			puts(buxxer);

			// reply to client with the same data, cause echo server.
			if (write(nsckfd, buxxer, BUFLEN) < 0) {
				commit_suicide("rep: write()");
			}

			close(nsckfd);
			exit(0);

		} else if (pid < 0) {
			commit_suicide("fork()");
		} else {
			close(nsckfd);
		}

	}

	close(nsckfd);
	close(sockfd);

	return 0;
}