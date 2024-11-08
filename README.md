# COMP340-Assignment4-300211868

## Summary
This project uses a logical clock and shared memory to mimic an operating system's process scheduling component. The `oss` process mimics the operating system and uses a multi-level feedback queue to manage user processes that are spawned at random intervals.


## Documents
- `oss.c`: Main logic for OS simulation.
- `user.c`: User processes were simulated.
The PCB structure for process management is found in `process_control_block.h`.
The shared memory setup is defined in `shared_memory.h`.
The message queue built for process communication is defined in `message_queue.h`.
- `utils.h`: Constants and utility functions.
- `Makefile`: Cleans and compiles the work.

## Gathering
The project may be compiled by running: ```bash make ```

## Implementation
Launch the OSS simulator by typing ```bash./oss ```
According to the project specifications, `oss` automatically creates user processes.

## Cleaning
To tidy up executables and object files: ```bash make clean ```

## No outstanding issues
None

## Version Control Log
Check the repository commit history for details on changes made.

## Troubleshooting
Ensure shared memory and message queues are properly removed upon termination.

## Notes
Logs are stored in the `logs/` directory for analysis of simulation operation.
