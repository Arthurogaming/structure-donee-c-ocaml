#include "mutex.h"

int creer_mutex(Mutex *mutex) {
    if (mutex == NULL) {
        return -1;
    }

    return pthread_mutex_init(&mutex->support, NULL);
}

int detruire_mutex(Mutex *mutex) {
    if (mutex == NULL) {
        return -1;
    }

    return pthread_mutex_destroy(&mutex->support);
}

int verrouiller_mutex(Mutex *mutex) {
    if (mutex == NULL) {
        return -1;
    }

    return pthread_mutex_lock(&mutex->support);
}

int deverrouiller_mutex(Mutex *mutex) {
    if (mutex == NULL) {
        return -1;
    }

    return pthread_mutex_unlock(&mutex->support);
}
