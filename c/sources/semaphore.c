#include "semaphore.h"

int creer_semaphore(Semaphore *semaphore, unsigned int valeur_initiale) {
    if (semaphore == NULL) {
        return -1;
    }

    return sem_init(&semaphore->support, 0, valeur_initiale);
}

int detruire_semaphore(Semaphore *semaphore) {
    if (semaphore == NULL) {
        return -1;
    }

    return sem_destroy(&semaphore->support);
}

int attendre_semaphore(Semaphore *semaphore) {
    if (semaphore == NULL) {
        return -1;
    }

    return sem_wait(&semaphore->support);
}

int signaler_semaphore(Semaphore *semaphore) {
    if (semaphore == NULL) {
        return -1;
    }

    return sem_post(&semaphore->support);
}
