#include "pile.h"

#include <stdio.h>

int main(void) {
    Pile pile = creer_pile();
    int valeur;

    empiler_element_pile(&pile, 10);
    empiler_element_pile(&pile, 20);
    empiler_element_pile(&pile, 30);

    if (obtenir_sommet_pile(&pile, &valeur)) {
        printf("Sommet de la pile : %d\n", valeur);
    }

    while (depiler_element_pile(&pile, &valeur)) {
        printf("Element depile : %d\n", valeur);
    }

    detruire_pile(&pile);
    return 0;
}
