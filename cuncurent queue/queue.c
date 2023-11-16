#define _GNU_SOURCE

#include <pthread.h>

#include "queue.h"

char* generateRandomString(int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char* randomString = (char*)malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; ++i) {
        int index = rand() % (sizeof(charset) - 1);
        randomString[i] = charset[index];
    }

    randomString[length] = '\0';
    return randomString;
}

List *queue_init(int max_count) {

    List *q = malloc(sizeof(List));
    if (!q) {
        printf("Cannot allocate memory for a queue\n");
        abort();
    }

    for (int i = 0; i < max_count; i++) {
        char* str = (char*) malloc(sizeof (char ));
        str[0] = (char)i;
        queue_add(q, str);
    }

    return q;
}

void queue_destroy(List *q) {
    ListNode *node = q->first;
    ListNode *tmp = NULL;
    while (node != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    free(q);
}



int queue_add(List *q, const char* val) {
    ListNode *new = malloc(sizeof(ListNode));
    if (!new) {
        printf("Cannot allocate memory for new node\n");
        abort();
    }
    if (q->first != NULL){
        ListNode *listNode = q->first;
        while (listNode->next != NULL){
            listNode = listNode->next;
        }
        listNode->next = new;
    }else{
        q->first = new;
    }
    pthread_spinlock_t spinlock;
    pthread_spin_init(&spinlock,0);
    new->sync = spinlock;
    strcpy(new->value,val);
    new->next = NULL;
    return 1;
}
