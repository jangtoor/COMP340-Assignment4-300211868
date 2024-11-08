#ifndef PROCESS_DESCRIPTOR_H
#define PROCESS_DESCRIPTOR_H

// Process states as enumeration for better type safety and readability
typedef enum ProcessState {
    PROCESS_READY = 0,      // Process is ready to execute
    PROCESS_BLOCKED = 1,    // Process is waiting for resource/event
    PROCESS_TERMINATED = 2  // Process has completed execution
} ProcessState;

// Priority levels for process scheduling
typedef enum PriorityLevel {
    PRIORITY_HIGH = 1,
    PRIORITY_MEDIUM = 2,
    PRIORITY_LOW = 3
} PriorityLevel;

// Structure to track process metrics
typedef struct ProcessMetrics {
    unsigned int total_execution_time;  // Total CPU time used
    unsigned int last_cpu_burst;        // Duration of last CPU usage
} ProcessMetrics;

// Main process descriptor structure
typedef struct ProcessDescriptor {
    int process_id;                     // Unique process identifier
    ProcessState state;                 // Current process state
    PriorityLevel priority;            // Process priority level
    int multilevel_queue_position;      // Current queue level in multilevel feedback queue
    ProcessMetrics metrics;            // Process execution metrics
    
    // Additional helpful fields
    unsigned int creation_timestamp;    // When the process was created
    unsigned int last_state_change;     // Last time the process state changed
} ProcessDescriptor;

// Helper functions declarations
void initialize_process(ProcessDescriptor* process);
const char* get_state_string(ProcessState state);
void update_process_metrics(ProcessDescriptor* process, unsigned int cpu_time);

#endif
