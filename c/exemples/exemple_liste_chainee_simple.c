#include "liste_chainee_simple.h"

#include <stdio.h>

int main(void) {
    ListeChaineeSimple liste = creer_liste_chainee_simple();
    int valeur_supprimee;

    inserer_element_en_tete_liste_chainee_simple(&liste, 5);
    inserer_element_en_tete_liste_chainee_simple(&liste, 3);
    inserer_element_en_queue_liste_chainee_simple(&liste, 8);

    printf("Liste initiale : ");
    afficher_liste_chainee_simple(&liste);

    if (supprimer_premier_element_liste_chainee_simple(&liste, &valeur_supprimee)) {
        printf("Premier element supprime : %d\n", valeur_supprimee);
    }

    printf("Longueur finale : %zu\n", longueur_liste_chainee_simple(&liste));
    printf("Liste finale : ");
    afficher_liste_chainee_simple(&liste);

    detruire_liste_chainee_simple(&liste);
    return 0;
}
