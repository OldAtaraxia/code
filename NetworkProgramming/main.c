#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *thread(void *vargp);

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, thread, NULL);
    pthread_join(tid, NULL);
    printf("%d\n", (int)pthread_self());
    exit(0);
}

void* thread(void *vargp) {
    printf("%d\n", (int)pthread_self());
    return NULL;
}