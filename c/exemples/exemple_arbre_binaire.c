#include "arbre_binaire.h"

#include <stdio.h>

int main(void) {
    ArbreBinaire arbre = creer_arbre_binaire();

    definir_racine_arbre_binaire(&arbre, 8);
    ajouter_fils_gauche_arbre_binaire(arbre.racine, 3);
    ajouter_fils_droit_arbre_binaire(arbre.racine, 10);
    ajouter_fils_gauche_arbre_binaire(arbre.racine->gauche, 1);
    ajouter_fils_droit_arbre_binaire(arbre.racine->gauche, 6);

    printf("Parcours prefixe : ");
    parcours_prefixe_arbre_binaire(&arbre);
    printf("Parcours infixe : ");
    parcours_infixe_arbre_binaire(&arbre);
    printf("Parcours suffixe : ");
    parcours_suffixe_arbre_binaire(&arbre);
    printf("Taille de l'arbre : %zu\n", taille_arbre_binaire(&arbre));

    detruire_arbre_binaire(&arbre);
    return 0;
}
