// ...

#include "common.h"

int main (int argc, char const * argv []) {
	
	int server_sockfd, client_sockfd;
	int server_len, client_len;

	struct sockaddr_in server_address, client_address;

	string buffer = (string)malloc(140 * sizeof(char));

	server_len = sizeof(server_address);
	server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&server_address, server_len);

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(46343);

	// client_len = sizeof(client_address);
	// client_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	// bzero(&client_address, client_len);

	// client_address.sin_family = AF_INET;
	// client_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	// client_address.sin_port = htons(33442);

	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	// bind(client_sockfd, (struct sockaddr *)&client_address, client_len);

	while (YES) {

		int n;
		printf("Server waiting...\n");

		client_len = sizeof(client_address);
		recvfrom(server_sockfd, buffer, MAX_LEN, 0, (struct sockaddr *)&client_address, client_len);
		printf("Client said: \"%s\"\n", buffer);

		sendto(server_sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&client_address, client_len);

	}

	return 0;
}