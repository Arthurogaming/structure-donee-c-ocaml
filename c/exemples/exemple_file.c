#include "file.h"

#include <stdio.h>

int main(void) {
    File file = creer_file();
    int valeur;

    enfiler_element_file(&file, 4);
    enfiler_element_file(&file, 9);
    enfiler_element_file(&file, 12);

    if (obtenir_tete_file(&file, &valeur)) {
        printf("Tete de la file : %d\n", valeur);
    }

    while (defiler_element_file(&file, &valeur)) {
        printf("Element defile : %d\n", valeur);
    }

    detruire_file(&file);
    return 0;
}
