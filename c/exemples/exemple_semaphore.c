#include "semaphore.h"

#include <stdio.h>

int main(void) {
    Semaphore semaphore;

    if (creer_semaphore(&semaphore, 1U) != 0) {
        printf("Echec lors de la creation du semaphore.\n");
        return 1;
    }

    printf("Attente sur le semaphore.\n");
    attendre_semaphore(&semaphore);
    printf("Section protegee atteinte.\n");
    signaler_semaphore(&semaphore);
    printf("Signal sur le semaphore.\n");

    detruire_semaphore(&semaphore);
    return 0;
}
