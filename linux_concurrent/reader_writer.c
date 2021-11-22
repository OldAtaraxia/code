#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int readcnt = 0;
sem_t mutex, w; // both initially = 1

void reader(void) {
    while(1) {
        sem_wait(&mutex);
        readcnt++;
        if (readcnt == 1)
            sem_wait(&w);
        sem_post(&mutex);

        printf("Reader\n");
        sleep(1);

        sem_wait(&mutex);
        readcnt--;
        if (readcnt == 0)
            sem_post(&w);
        sem_post(&mutex);
    }
    
}

void writer(void) {
    while(1) {
        sem_wait(&w);
        printf("Writer\n");
        sleep(1);
        sem_post(&w);
    }
}