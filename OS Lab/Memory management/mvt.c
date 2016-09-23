// Multiprogramming memory simulation with a variable number of tasks

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum { NO, YES } BOOL;

typedef struct process {
	int pid; // Process ID
	int memory_required;
	BOOL allocated;
	int internal_fragmentation;
} process_t, *process_p_t;

process_p_t initProcess (int pid) {
	process_p_t process = (process_p_t)malloc(sizeof(process_t));
	process->pid = pid+1;
	printf("Enter memory required for process %d: ", pid+1);
	scanf(" %d", &process->memory_required);
	process->allocated = NO;
	process->internal_fragmentation = 0.f;
	return process;
}

int main (int argc, const char * argv []) {

	int total_memory;
	printf("Enter total available memory: ");
	scanf(" %d", &total_memory);

	process_p_t processes[100];

	int i = 0;
	int memory_used = 0;
	int memory_available = total_memory;

	char mander;

	do {
		processes[i] = initProcess(i);	
		process_p_t proc = processes[i];

		if (memory_available > proc->memory_required) {
			memory_available -= proc->memory_required;
			memory_used += proc->memory_required;
			proc->allocated = YES;
			printf("Memory allocated for process %d\n", i+1);
		} else {
			printf("Not enough memory (%d) for process %d.\n", memory_available, i+1);
		}

		i += 1;

		printf("Continue (y/n): ");
		scanf(" %c", &mander);

	} while (mander == 'y');

	printf("-----------------------------\n");
	printf("Total memory available: %d\n", total_memory);

	printf("PROCESS |\tALLOCATED |\tMEMORY_ALLOCATED\n");
	i = 0;
	do {
		process_p_t proc = processes[i];
		if (proc == NULL) break;
		if (proc->allocated) {
			printf("%d\t|\tYES\t|\t%d\n", proc->pid, proc->memory_required);
		} else {
			printf("%d\t|\tNO\t|\t---\n", proc->pid);
		}
		i++;
	} while (YES);
	printf("\nTotal memory allocated = %d\nTotal external fragmentation = %d\n", memory_used, memory_available);

	return 0;

}