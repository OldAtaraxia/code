#include <semaphore.h>

sem_t s;

int main() {
    sem_init(sem, 1);
    p(s)
}

unsigned rand(unsigned int*nextp) {
    *nextp = *nextp * 1103515245 + 12345;
    return (unsigned)(*nextp/65536) % 32768;
}

char* ctime_ts(const time_t *timep, char* privatep) {
    char* sharedp;

    sem_wait(&mutex);
    sharep = ctime(timep);
    strcpy(privatep, sharep);
    sem_post(&mutex);
    return privatep;
}