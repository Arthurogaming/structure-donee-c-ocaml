#include "arbre_binaire_de_recherche.h"

#include <stdio.h>

int main(void) {
    ArbreBinaireDeRecherche arbre = creer_arbre_binaire_de_recherche();

    inserer_element_arbre_binaire_de_recherche(&arbre, 7);
    inserer_element_arbre_binaire_de_recherche(&arbre, 4);
    inserer_element_arbre_binaire_de_recherche(&arbre, 9);
    inserer_element_arbre_binaire_de_recherche(&arbre, 2);
    inserer_element_arbre_binaire_de_recherche(&arbre, 6);

    printf("Parcours infixe initial : ");
    parcours_infixe_arbre_binaire_de_recherche(&arbre);

    if (rechercher_element_arbre_binaire_de_recherche(&arbre, 6)) {
        printf("La valeur 6 est presente.\n");
    }

    supprimer_element_arbre_binaire_de_recherche(&arbre, 4);
    printf("Parcours infixe apres suppression de 4 : ");
    parcours_infixe_arbre_binaire_de_recherche(&arbre);

    detruire_arbre_binaire_de_recherche(&arbre);
    return 0;
}
