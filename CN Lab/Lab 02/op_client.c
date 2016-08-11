// ...

#include "common.h"

int main (int argc, char const * argv []) {
	
	int server_sockfd, client_sockfd;
	int server_len, client_len;

	struct sockaddr_in server_address, client_address;

	THING_p_t thing = (THING_p_t)malloc(sizeof(THING_t));

	server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&server_address, sizeof(server_address));

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(33442);

	server_len = sizeof(server_address);

	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

	while (YES) {

		printf("Enter a and b: ");
		scanf(" %lf %lf", thing->a, thing->b);
		printf("     Enter op: ");
		scanf(" %c", thing->op);

		client_len = sizeof(client_address);

		sendto(server_sockfd, (void *)thing, sizeof(THING_t), 0, (struct sockaddr *)&server_address, client_len);

		double *res;
		recvfrom(server_sockfd, res, sizeof(double), 0, NULL, NULL);

		printf(" Server said: \"%lf\"\n", *res);

	}

	return 0;
}