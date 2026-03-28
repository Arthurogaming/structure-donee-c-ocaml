#include "pile.h"

#include <stdlib.h>

Pile creer_pile(void) {
    Pile pile;

    pile.sommet = NULL;
    return pile;
}

void detruire_pile(Pile *pile) {
    if (pile == NULL) {
        return;
    }

    while (pile->sommet != NULL) {
        CellulePile *ancienne_cellule = pile->sommet;
        pile->sommet = ancienne_cellule->suivante;
        free(ancienne_cellule);
    }
}

int est_vide_pile(const Pile *pile) {
    return pile == NULL || pile->sommet == NULL;
}

int empiler_element_pile(Pile *pile, int valeur) {
    CellulePile *nouvelle_cellule;

    if (pile == NULL) {
        return 0;
    }

    nouvelle_cellule = malloc(sizeof(CellulePile));
    if (nouvelle_cellule == NULL) {
        return 0;
    }

    nouvelle_cellule->valeur = valeur;
    nouvelle_cellule->suivante = pile->sommet;
    pile->sommet = nouvelle_cellule;
    return 1;
}

int depiler_element_pile(Pile *pile, int *valeur_depilee) {
    CellulePile *ancienne_cellule;

    if (pile == NULL || pile->sommet == NULL) {
        return 0;
    }

    ancienne_cellule = pile->sommet;
    pile->sommet = ancienne_cellule->suivante;

    if (valeur_depilee != NULL) {
        *valeur_depilee = ancienne_cellule->valeur;
    }

    free(ancienne_cellule);
    return 1;
}

int obtenir_sommet_pile(const Pile *pile, int *valeur) {
    if (pile == NULL || pile->sommet == NULL || valeur == NULL) {
        return 0;
    }

    *valeur = pile->sommet->valeur;
    return 1;
}
