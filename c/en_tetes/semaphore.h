#ifndef SEMAPHORE_STRUCTURE_H
#define SEMAPHORE_STRUCTURE_H

#include <semaphore.h>

typedef struct {
    sem_t support;
} Semaphore;

int creer_semaphore(Semaphore *semaphore, unsigned int valeur_initiale);
int detruire_semaphore(Semaphore *semaphore);
int attendre_semaphore(Semaphore *semaphore);
int signaler_semaphore(Semaphore *semaphore);

#endif
