#ifndef SYSTEM_MEMORY_H
#define SYSTEM_MEMORY_H

#include <sys/shm.h>
#include <stdint.h>
#include "process_control_block.h"

// Shared memory keys as an enumeration for better organization
enum SharedMemoryKeys {
    PROCESS_TABLE_KEY = 0x1234,    // Key for process management table
    SYSTEM_CLOCK_KEY = 0x5678      // Key for system clock
};

// Time units for clarity
#define NANOS_PER_SECOND 1000000000U

// System clock structure with enhanced precision
typedef struct SystemTime {
    uint32_t seconds;              // System time in seconds
    uint32_t nanoseconds;          // Nanosecond precision (0-999999999)
    
    // Additional helper methods could be declared here
    // These would be implemented in a .c file
} SystemTime;

// Helper function declarations
#ifdef __cplusplus
extern "C" {
#endif

// Initialize shared memory segment
void* init_shared_memory(key_t key, size_t size);

// Attach to existing shared memory
void* attach_shared_memory(key_t key);

// Detach and cleanup shared memory
void cleanup_shared_memory(void* ptr, key_t key);

// Time manipulation functions
void increment_system_time(SystemTime* time, uint32_t nano_increment);
uint64_t get_total_nanoseconds(const SystemTime* time);
void normalize_system_time(SystemTime* time);

#ifdef __cplusplus
}
#endif

#endif
