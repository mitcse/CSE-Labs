// ...

/**
 *	UDP from client side
 *	socket() -> sendto()/recvfrom()
 */

#include "common.h"

#define SERVER "127.0.0.1"

void commit_suicide(string message) {
	perror(message);
	exit(7);
}

int main (int argc, char const * argv []) {
	
	sockaddr_in_t client_address;
	
	int sockfd, i;
	socklen_t slen = sizeof(client_address);
	
	thing_p_t buffer = (thing_p_t)malloc(sizeof(thing_t));
	
	// create a UDP server
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
		commit_suicide("bind()");
	}
	// zero out the structure
	memset((char *)&client_address, 0, slen);
	
	// set family and port
	client_address.sin_family = AF_INET;
	client_address.sin_port = htons(PORT);
	
	// get address
	if (inet_aton(SERVER, &client_address.sin_addr) == 0) {
		commit_suicide("inet_aton()");
	}
	
	while (YES) {
		printf(" Enter the stuff to do: ");
		scanf(" %lf %c %lf", &buffer->a, &buffer->op, &buffer->b);
		
		// try sending some data to the server
		if (sendto(sockfd, buffer, BUFLEN, 0, (sockaddr_p_t)&client_address, slen) == -1) {
			commit_suicide("sendto()");
		}
		
		buffer = (thing_p_t)malloc(sizeof(thing_t));
		
		// blocking call; try getting data from the server
		if (recvfrom(sockfd, buffer, BUFLEN, 0, (sockaddr_p_t)&client_address, &slen) == -1) {
			commit_suicide("recvfrom()");
		}
		
		printf("Server said: %.2lf %c %.2lf = %.2lf\n", buffer->a, buffer->op, buffer->b, buffer->r);
	}
	
	close(sockfd);

	return 0;
}