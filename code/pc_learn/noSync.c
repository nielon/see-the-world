// producer_consumer.c
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAXITEMS (100000)
#define MAXTHREADS (10)
#define min(a, b) ((a) > (b) ? (b) : (a))

int g_itemnum;
struct
{
  pthread_mutex_t mutex;
    int buff[MAXITEMS];
    int nindex; // next index in the buff
    int nvalue; // next value in the buff
} shared; // shared struct for multi-thread

void* producer(void*);
void* consumer(void*);

int main(void)
{
    int i;
    int threadnum, threadcount[MAXTHREADS];
    pthread_t tid_producer[MAXTHREADS], tid_consumer;

    g_itemnum = MAXITEMS;
    threadnum = MAXTHREADS;
    pthread_setconcurrency(threadnum);

    // start all the producer threads
    for (i = 0; i < threadnum; ++i) {
        threadcount[i] = 0;
        if (0 != pthread_create(&tid_producer[i], NULL, producer, (void*)&threadcount[i])) 
	{
            printf("pthread_create error producer %d\n", i);
            exit(EXIT_FAILURE);
        }
        printf("producer: thread[%lu] created, threadcount[%d] = %d\n", tid_producer[i], i, threadcount[i]);
    }
    // wait for all the producer threads
    for (i = 0; i < threadnum; ++i) 
    {
        if (0 != pthread_join(tid_producer[i], NULL)) {
            printf("pthread_join error producer %d\n", i);
            exit(EXIT_FAILURE);
        }
        printf("producer: thread[%lu] done, threadcount[%d] = %d\n", tid_producer[i], i, threadcount[i]);
    }

    // start consumer thread
    if (0 != pthread_create(&tid_consumer, NULL, consumer, NULL)) {
        printf("pthread_create error consumer\n");
    }
    printf("consumer: thread[%lu] created\n", tid_consumer);
    // wait for the consumer thread
    if (0 != pthread_join(tid_consumer, NULL)) {
        printf("pthread_join error consumer\n");
    }
    printf("consumer: thread[%lu] done\n", tid_consumer);
    exit(EXIT_SUCCESS);
}

void* producer(void *arg)
{
    for (;;) {
      /*pthread_mutex_lock(&shared.mutex);*/
        if (shared.nindex >= g_itemnum) {
	  /*pthread_mutex_unlock(&shared.mutex);*/
            return NULL;
        }
      pthread_mutex_lock(&shared.mutex);
        shared.buff[shared.nindex] = shared.nvalue;
        shared.nindex++;
        shared.nvalue++;
	pthread_mutex_unlock(&shared.mutex);
        *((int*)arg) += 1;
    }
    return NULL;
}

void* consumer(void *arg)
{
    int i;
    for (i = 0; i < g_itemnum; ++i) {
        if (shared.buff[i] != i) {
            printf("error: buff[%d] = %d\n", i, shared.buff[i]);
        }
    }
    return NULL;
}
