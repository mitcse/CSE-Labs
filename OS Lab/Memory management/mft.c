// Multiprogramming memory simulation with a fixed number of tasks

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

	int block_size;;
	printf("Enter block size: ");
	scanf(" %d", &block_size);

	int n;
	printf("Enter number of processes: ");
	scanf(" %d", &n);

	process_p_t processes[n];

	int i;
	int memory_used = 0;
	int memory_available = total_memory;
	int blocks_available = total_memory/block_size;
	int total_internal_fragmentation = 0;

	for (i = 0; i < n; ++i) {
		processes[i] = initProcess(i);	
	}

	printf("-----------------------------\n");
	printf("Total memory available: %d\n", total_memory);
	printf("Blocks available in memory = %d\n", blocks_available);
	printf("Total memory available in blocks: %d * %d = %d\n", blocks_available, block_size, blocks_available * block_size);

	printf("PROCESS |    ALLOCATED\t| MEMORY_ALLOC\t| INTERNAL_FRAGMENTATION\n");

	for (i = 0; i < n; ++i) {
		process_p_t proc = processes[i];
		if (proc->memory_required < block_size && blocks_available > 0) {
			blocks_available--;
			proc->allocated = YES;
			proc->internal_fragmentation = block_size - proc->memory_required;
			total_internal_fragmentation += proc->internal_fragmentation;
			memory_available -= block_size;
			memory_used += block_size;
			printf("   %d\t|\tYES\t|\t%d\t|\t%d\n", proc->pid, proc->memory_required, proc->internal_fragmentation);
		} else {
			printf("   %d\t|\tNO\t|\t---\t|\t---\n", proc->pid);
		}
		if (blocks_available == 0) {
			printf("Memory is full, remaining processes cannot be accomodated.\n");
			break;
		}
	}

	printf("\nTotal memory allocated = %d\nTotal external fragmentation = %d\nTotal internal fragmentation = %d\n", memory_used, memory_available, total_internal_fragmentation);

	return 0;

}