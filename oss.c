#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <signal.h>
#include "process_control_block.h"
#include "shared_memory.h"
#include "message_queue.h"
#include "utils.h"

// Structure definitions
typedef struct {
    unsigned int seconds;
    unsigned int nanoseconds;
} SystemClock;

typedef struct {
    int pid;
    unsigned int cpu_time;
    unsigned int burst_time;
    int priority_level;
    int queue_position;
    enum { PROCESS_READY = 1 } state;
} ProcessDescriptor;

// Function to initialize process descriptor
void init_process_descriptor(ProcessDescriptor* pd) {
    pd->pid = -1;
    pd->cpu_time = 0;
    pd->burst_time = 0;
    pd->priority_level = -1;
    pd->queue_position = 1;
    pd->state = PROCESS_READY;
}

// Function to setup shared memory
void* create_shared_memory(key_t key, size_t size) {
    int shm_id = shmget(key, size, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("Shared memory creation failed");
        exit(1);
    }
    return shmat(shm_id, NULL, 0);
}

// Function to cleanup shared memory
void cleanup_shared_memory(void* ptr, int shm_id) {
    shmdt(ptr);
    shmctl(shm_id, IPC_RMID, NULL);
}

int main() {
    printf("Initializing Operating System Simulator\n");
    
    // Create system clock in shared memory
    int clock_shm_id = shmget(CLOCK_SHM_KEY, sizeof(SystemClock), IPC_CREAT | 0666);
    SystemClock* system_clock = (SystemClock*)create_shared_memory(CLOCK_SHM_KEY, sizeof(SystemClock));
    
    // Initialize system clock
    system_clock->seconds = 0;
    system_clock->nanoseconds = 0;
    
    // Create process table in shared memory
    const int MAX_PROCESSES = 18;
    int process_table_shm_id = shmget(SHM_KEY, MAX_PROCESSES * sizeof(ProcessDescriptor), IPC_CREAT | 0666);
    ProcessDescriptor* process_table = (ProcessDescriptor*)create_shared_memory(SHM_KEY, MAX_PROCESSES * sizeof(ProcessDescriptor));
    
    // Initialize process table
    for (int i = 0; i < MAX_PROCESSES; i++) {
        init_process_descriptor(&process_table[i]);
    }
    
    // Cleanup
    cleanup_shared_memory(system_clock, clock_shm_id);
    cleanup_shared_memory(process_table, process_table_shm_id);
    
    printf("Operating System Simulator shutdown complete\n");
    return 0;
}
