#include "mutex.h"

#include <stdio.h>

int main(void) {
    Mutex mutex;

    if (creer_mutex(&mutex) != 0) {
        printf("Echec lors de la creation du mutex.\n");
        return 1;
    }

    printf("Verrouillage du mutex.\n");
    verrouiller_mutex(&mutex);
    printf("Section critique simple.\n");
    deverrouiller_mutex(&mutex);
    printf("Deverrouillage du mutex.\n");

    detruire_mutex(&mutex);
    return 0;
}
