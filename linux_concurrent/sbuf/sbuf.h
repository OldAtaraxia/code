#include  <semaphore.h>

typedef struct{
    int *buf; // buffer array
    int n; // maximum number of buffer slots
    int front; 
    int rear; // 可用buf的开始和结束
    sem_t mutex; // protects assesses to buf
    sem_t slots; // counts available buffer slots
    sem_t items; // counts available items
} sbuf_t;

void sbuf_init(sbuf_t *sp, int n);
void sbuf_deinit(sbuf_t *sp);
void sbuf_insert(sbuf_t *sp, int item);
int sbuf_remove(sbuf_t *sp);