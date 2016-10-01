
#include "common.h"

int main (int argc, char const * argv[] ) {

	int qt;
	MESSAGE_t message;

	if((qt = msgget(1271, IPC_CREAT | IPC_EXCL | 0600)) < 0) { 
		perror("Error in msgget()");
	}

	printf("Message queue created.\n");

	if(msgrcv(qt, &message, sizeof(MESSAGE_t), 0, 0) < 0) {
		perror("Error in msgrcv()");
	}   

	printf("Successfully received: %s\n", message.c);
	
	msgctl(qt, IPC_RMID, NULL);

	return 0;
}
