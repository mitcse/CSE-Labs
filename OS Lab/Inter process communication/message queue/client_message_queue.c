
#include "common.h"

int main (int argc, char const * argv[] ) {

	int qt;
	MESSAGE_t message;

	if((qt = msgget(1271, 0)) < 0) { 
		perror("Error in msgget()");
	}

	printf("Enter the message: ");
	fgets(message.c, SIZE, stdin);
	message.mtype = 1;

	if(msgsnd(qt, &message, sizeof(MESSAGE_t), 0) < 0) {
		perror("Error in msgsnd()");
	}

	printf("Successfully sent.\n");

	return 0;
}
