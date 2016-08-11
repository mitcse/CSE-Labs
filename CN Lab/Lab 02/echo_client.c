// ...

#include "common.h"

int main (int argc, char const * argv []) {
	
	int server_sockfd, client_sockfd;
	int server_len, client_len;

	struct sockaddr_in server_address, client_address;
	int result;

	string sentline = (string)malloc(140 * sizeof(char));
	string revcline = (string)malloc(140 * sizeof(char));

	server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&server_address, sizeof(server_address));

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(33442);

	server_len = sizeof(server_address);

	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	while (YES) {

		printf("Enter message: ");
		scanf(" %s", sentline);

		client_len = sizeof(client_address);

		sendto(server_sockfd, sentline, MAX_LEN, 0, (struct sockaddr *)&server_address, client_len);

		int n;
		n = recvfrom(server_sockfd, revcline, MAX_LEN, 0, NULL, NULL);
		*(revcline + n) = 0;

		printf(" Server said: \"%s\"\n", revcline);

	}

	return 0;
}