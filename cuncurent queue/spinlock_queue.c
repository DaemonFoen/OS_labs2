#include <pthread.h>
#include "queue.h"

int pthread1_it = 0;
int pthread2_it = 0;
int pthread3_it = 0;
volatile int pthread4_it = 0;

void *seekAscendingPair(void *arg) {
    List *list = (List *) arg;

    while (1) {
        ListNode *node = list->first;
        while (node->next != NULL) {
            pthread_spin_lock(&node->sync);
            if (node->next != NULL) {
                pthread_spin_lock(&node->next->sync);
            } else {
                pthread_spin_unlock(&node->sync);
                break;
            }
            int pair_count = 0;
            if (strlen(node->value) < strlen(node->next->value)) {
                pair_count++;
            }
            pthread_spin_unlock(&node->next->sync);
            pthread_spin_unlock(&node->sync);
            node = node->next;
        }
        pthread1_it++;
        printf("ascending thread %d\n", pthread1_it);
        fflush(stdout);
    }
    return NULL;
}

void *seekDescendingPair(void *arg) {
    List *list = (List *) arg;

    while (1) {
        ListNode *node = list->first;
        while (node != NULL && node->next != NULL) {
            pthread_spin_lock(&node->sync);
            if (node->next != NULL) {
                pthread_spin_lock(&node->next->sync);
            } else {
                pthread_spin_unlock(&node->sync);
                break;
            }
            int pair_count = 0;
            if (strlen(node->value) > strlen(node->next->value)) {
                pair_count++;
            }
            pthread_spin_unlock(&node->next->sync);
            pthread_spin_unlock(&node->sync);
            node = node->next;
        }
        pthread2_it++;
        printf("descending thread %d\n", pthread2_it);
        fflush(stdout);
    }
    return NULL;
}

void *seekEqualPair(void *arg) {
    List *list = (List *) arg;

    while (1) {
        ListNode *node = list->first;
        while (node->next != NULL) {
            pthread_spin_lock(&node->sync);
            if (node->next != NULL) {
                pthread_spin_lock(&node->next->sync);
            } else {
                pthread_spin_unlock(&node->sync);
                break;
            }
            int pair_count = 0;
            if (strlen(node->value) == strlen(node->next->value)) {
                pair_count++;
            }
            pthread_spin_unlock(&node->next->sync);
            pthread_spin_unlock(&node->sync);
            node = node->next;
        }
        pthread3_it++;
        printf("equal thread %d\n", pthread3_it);
        fflush(stdout);
    }
    return NULL;
}

void *swapRandomElements(void *arg) {
    List *list = (List *) arg;
    while (1) {
        ListNode *it_node = list->first;
        while (it_node->next != NULL) {
            ListNode *node = it_node;
            pthread_spin_lock(&node->sync);
            if (node->next != NULL) {
                pthread_spin_lock(&node->next->sync);
            } else {
                pthread_spin_unlock(&node->sync);
                break;
            }

            if (node->next->next != NULL) {
                pthread_spin_lock(&node->next->next->sync);
            } else {
                pthread_spin_unlock(&node->sync);
                pthread_spin_unlock(&node->next->sync);
                break;
            }

            ListNode *tmp = node->next;
            node->next = tmp->next;
            tmp->next = node->next->next;
            node->next->next = tmp;

            it_node = it_node->next;
            pthread_spin_unlock(&node->next->next->sync);
            pthread_spin_unlock(&node->next->sync);
            pthread_spin_unlock(&node->sync);
            pthread4_it++;
            printf("swap thread %d\n", pthread4_it);
            fflush(stdout);
        }
    }
    return NULL;
}


int main() {
    List *list = queue_init(100);
    pthread_t pthread_1, pthread_2, pthread_3, pthread_4, pthread_5, pthread_6;
    int err;
    err = pthread_create(&pthread_1, NULL, seekAscendingPair, list);
    if (err != 0) {
        printf("thread create error");
        exit(1);
    }
    err = pthread_create(&pthread_2, NULL, seekDescendingPair, list);
    if (err != 0) {
        printf("thread create error");
        exit(1);
    }
    err = pthread_create(&pthread_3, NULL, seekEqualPair, list);
    if (err != 0) {
        printf("thread create error");
        exit(1);
    }
    err = pthread_create(&pthread_4, NULL, swapRandomElements, list);
    if (err != 0) {
        printf("thread create error");
        exit(1);
    }

    err = pthread_create(&pthread_5, NULL, swapRandomElements, list);
    if (err != 0) {
        printf("thread create error");
        exit(1);
    }

    err = pthread_create(&pthread_6, NULL, swapRandomElements, list);
    if (err != 0) {
        printf("thread create error");
        exit(1);
    }
    pthread_join(pthread_6, NULL);

    queue_destroy(list);
    return 0;
}