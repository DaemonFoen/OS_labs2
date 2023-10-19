#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <sched.h>

#include "queue.h"

#define RED "\033[41m"
#define NOCOLOR "\033[0m"

pthread_cond_t condition_variable;
pthread_mutex_t mutex;
volatile int condition = 0;

void set_cpu(int n) {
	int err;
	cpu_set_t cpuset;
	pthread_t tid = pthread_self();

	CPU_ZERO(&cpuset);
	CPU_SET(n, &cpuset);

    //Привязка потока к конкретным ядрам процессора
	err = pthread_setaffinity_np(tid, sizeof(cpu_set_t), &cpuset);
	if (err) {
		printf("set_cpu: pthread_setaffinity failed for cpu %d\n", n);
		return;
	}

	printf("set_cpu: set cpu %d\n", n);
}

void *reader(void *arg) {
	int expected = 0;
	queue_t *q = (queue_t *)arg;
	printf("reader [%d %d %d]\n", getpid(), getppid(), gettid());
    fflush(stdout);
	set_cpu(1);


	while (1) {
		int val = -1;
        pthread_mutex_lock(&mutex);
        while (condition == 0) {
            pthread_cond_wait(&condition_variable, &mutex);
        }
		int ok = queue_get(q, &val);
		if (!ok){
            pthread_mutex_unlock(&mutex);
            continue;
        }

		if (expected != val){
            printf(RED"ERROR: get value is %d but expected - %d" NOCOLOR "\n", val, expected);
            fflush(stdout);
        }
		expected = val + 1;
        condition = 0;
        pthread_cond_signal(&condition_variable);
        pthread_mutex_unlock(&mutex);
    }

	return NULL;
}

void *writer(void *arg) {
	int i = 0;
	queue_t *q = (queue_t *)arg;
	printf("writer [%d %d %d]\n", getpid(), getppid(), gettid());
    fflush(stdout);

	set_cpu(2);

	while (1) {
        pthread_mutex_lock(&mutex);
        while (condition == 1) {
            pthread_cond_wait(&condition_variable, &mutex);
        }

		int ok = queue_add(q, i);
		if (!ok){
            pthread_mutex_unlock(&mutex);
            continue;
        }
		i++;
        condition = 1;
        pthread_cond_signal(&condition_variable);
        pthread_mutex_unlock(&mutex);
	}

	return NULL;
}

int main() {
	pthread_t tid;
	queue_t *q;
	int err;

    pthread_cond_init(&condition_variable, NULL);
    pthread_mutex_init(&mutex, NULL);

	printf("main [%d %d %d]\n", getpid(), getppid(), gettid());
    fflush(stdout);

	q = queue_init(10000);

	err = pthread_create(&tid, NULL, reader, q);
	if (err) {
		printf("main: pthread_create() failed: %s\n", strerror(err));
        fflush(stdout);
		return -1;
	}

    //Указание процессору переключится на другой поток
    sched_yield();

    err = pthread_create(&tid, NULL, writer, q);
    if (err) {
        printf("main: pthread_create() failed: %s\n", strerror(err));
        fflush(stdout);
        return -1;
    }


	pthread_exit(NULL);
	return 0;
}
