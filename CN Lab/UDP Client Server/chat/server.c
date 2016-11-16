#include "common.h"

char buffer[BUFLEN];

void commit_suicide (char * message) {
	printf("Error: %s\n", message);
	exit(6);
}

int main (int argc, const char * argv []) {

	sockaddr_in_t server_addr, client_addr;

	int sockfd;
	socklen_t slen, rlen;

	slen = sizeof(server_addr);

	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sockfd == -1) {
		commit_suicide("socket");
	}

	memset((char *)&server_addr, 0, slen);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockfd, (sockaddr_p_t)&server_addr, slen) == -1) {
		commit_suicide("bind");
	}

	printf("Server started at %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(PORT));

	memset(buffer, '\0', BUFLEN);

	while (YES) {

		rlen = recvfrom(sockfd, buffer, BUFLEN, 0, (sockaddr_p_t)&client_addr, &slen);

		if (rlen == -1) {

		} else {
			printf("<< %s\n", buffer);
		}

		memset(buffer, '\0', BUFLEN);

		printf(">> ");
		fgets(buffer, BUFLEN, stdin);

		sendto(sockfd, buffer, BUFLEN, 0, (sockaddr_p_t)&client_addr, slen);

	}

}