#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 2

void getNextAlphabet (char * alp) {
	char *next = (char *)calloc(2, sizeof(char));
	next[1] = '\0';
	if (*alp == 'Z')
		next[0] = 'a';
	else if (*alp == 'z')
		next[0] = 'A';
	else
		next[0] = *alp + 1;
	*alp = *next;
}

int main (int argc, const char * argv []) {

	int segment_id = shmget(IPC_PRIVATE, SIZE, S_IRUSR | S_IWUSR);

	char *shared_memory = (char *)shmat(segment_id, NULL, 0);
	*shared_memory = '\0';

	pid_t pid;

	int i;

	*shared_memory = 'A';

	for (i = 0; i < 52; ++i) {

		pid = fork();

		if (pid == 0) {

			while (*shared_memory == '\0');

			getNextAlphabet(shared_memory);

			exit(0);

		} else {

			printf("%s -> ", shared_memory);
			
			wait(NULL);

			printf("%s\n", shared_memory);

		}

	}

	shmdt(shared_memory);

}


/** 
Sample output:

A -> B
B -> C
C -> D
D -> E
E -> F
F -> G
G -> H
H -> I
I -> J
J -> K
K -> L
L -> M
M -> N
N -> O
O -> P
P -> Q
Q -> R
R -> S
S -> T
T -> U
U -> V
V -> W
W -> X
X -> Y
Y -> Z
Z -> a
a -> b
b -> c
c -> d
d -> e
e -> f
f -> g
g -> h
h -> i
i -> j
j -> k
k -> l
l -> m
m -> n
n -> o
o -> p
p -> q
q -> r
r -> s
s -> t
t -> u
u -> v
v -> w
w -> x
x -> y
y -> z
z -> A

*/