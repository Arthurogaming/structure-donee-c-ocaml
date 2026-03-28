#include "graphe_liste_adjacence.h"

#include <stdio.h>

int main(void) {
    GrapheListeAdjacence graphe = creer_graphe_liste_adjacence(4, 1);

    ajouter_arete_graphe_liste_adjacence(&graphe, 0, 1);
    ajouter_arete_graphe_liste_adjacence(&graphe, 0, 2);
    ajouter_arete_graphe_liste_adjacence(&graphe, 2, 3);

    printf("Listes d'adjacence initiales :\n");
    afficher_graphe_liste_adjacence(&graphe);

    printf("L'arete 0 -> 2 existe : %s\n",
        arete_existe_graphe_liste_adjacence(&graphe, 0, 2) ? "oui" : "non");

    retirer_arete_graphe_liste_adjacence(&graphe, 0, 2);
    printf("Apres suppression de l'arete 0 -> 2 :\n");
    afficher_graphe_liste_adjacence(&graphe);

    detruire_graphe_liste_adjacence(&graphe);
    return 0;
}
