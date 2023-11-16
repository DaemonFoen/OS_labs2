#ifndef __FITOS_QUEUE_H__
#define __FITOS_QUEUE_H__

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct _ListNode {
    char value[1];
    struct _ListNode *next;
    pthread_spinlock_t sync;
} ListNode;

typedef struct _List {
	ListNode *first;
} List;

List* queue_init(int max_count);
void queue_destroy(List *q);
int queue_add(List *q, const char* val);

#endif		// __FITOS_QUEUE_H__
