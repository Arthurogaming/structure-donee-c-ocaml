#include "graphe_matrice_adjacence.h"

#include <stdio.h>

int main(void) {
    GrapheMatriceAdjacence graphe = creer_graphe_matrice_adjacence(4, 0);

    ajouter_arete_graphe_matrice_adjacence(&graphe, 0, 1);
    ajouter_arete_graphe_matrice_adjacence(&graphe, 0, 2);
    ajouter_arete_graphe_matrice_adjacence(&graphe, 2, 3);

    printf("Matrice d'adjacence initiale :\n");
    afficher_graphe_matrice_adjacence(&graphe);

    retirer_arete_graphe_matrice_adjacence(&graphe, 0, 2);
    printf("Apres suppression de l'arete entre 0 et 2 :\n");
    afficher_graphe_matrice_adjacence(&graphe);

    detruire_graphe_matrice_adjacence(&graphe);
    return 0;
}
