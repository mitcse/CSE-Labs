// ...

#include "common.h"

int main (int argc, char const * argv []) {
	
	int server_sockfd;
	int server_len, client_len;

	struct sockaddr_in server_address, client_address;

	THING_p_t buffer = (THING_p_t)malloc(sizeof(THING_t));

	server_len = sizeof(server_address);
	server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&server_address, server_len);

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(46343);

	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	while (YES) {

		int n;
		printf("Server waiting...\n");

		client_len = sizeof(client_address);
		recvfrom(server_sockfd, buffer, sizeof(THING_t), 0, (struct sockaddr *)&client_address, client_len);

		double *res = (double *)malloc(sizeof(double));
		double a = buffer->a, b = buffer->b;
		char op = buffer->op;

		if (op == '+') {
			*res = a + b;
		} else if (op == '-') {
			*res = a - b;
		} else if (op == '*') {
			*res = a * b;
		} else if (op == '/') {
			*res = a * b;
		}

		sendto(server_sockfd, res, sizeof(double), 0, (struct sockaddr *)&client_address, client_len);

	}

	return 0;
}