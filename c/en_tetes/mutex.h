#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>

typedef struct {
    pthread_mutex_t support;
} Mutex;

int creer_mutex(Mutex *mutex);
int detruire_mutex(Mutex *mutex);
int verrouiller_mutex(Mutex *mutex);
int deverrouiller_mutex(Mutex *mutex);

#endif
