#include "file_de_priorite.h"

#include <stdio.h>

int main(void) {
    FileDePriorite file_de_priorite = creer_file_de_priorite(4U);
    int valeur;

    inserer_element_file_de_priorite(&file_de_priorite, 7);
    inserer_element_file_de_priorite(&file_de_priorite, 2);
    inserer_element_file_de_priorite(&file_de_priorite, 9);
    inserer_element_file_de_priorite(&file_de_priorite, 4);

    if (obtenir_element_prioritaire_file_de_priorite(&file_de_priorite, &valeur)) {
        printf("Element prioritaire initial : %d\n", valeur);
    }

    while (supprimer_element_prioritaire_file_de_priorite(&file_de_priorite, &valeur)) {
        printf("Element retire : %d\n", valeur);
    }

    detruire_file_de_priorite(&file_de_priorite);
    return 0;
}
