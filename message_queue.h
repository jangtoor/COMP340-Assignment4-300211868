#ifndef MESSAGE_QUEUE_H
#define MESSAGE_QUEUE_H

#include <sys/msg.h>

#define MESSAGE_KEY 0x9876

typedef struct {
    long type;
    int slice_duration;
    int process_id;
} Msg;

#endif
