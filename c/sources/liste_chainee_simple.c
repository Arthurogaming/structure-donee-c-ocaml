#include "liste_chainee_simple.h"

#include <stdio.h>
#include <stdlib.h>

static NoeudListeChaineeSimple *creer_noeud_liste_chainee_simple(int valeur) {
    NoeudListeChaineeSimple *nouveau_noeud = malloc(sizeof(NoeudListeChaineeSimple));

    if (nouveau_noeud == NULL) {
        return NULL;
    }

    nouveau_noeud->valeur = valeur;
    nouveau_noeud->suivant = NULL;
    return nouveau_noeud;
}

ListeChaineeSimple creer_liste_chainee_simple(void) {
    ListeChaineeSimple liste;

    liste.tete = NULL;
    return liste;
}

void detruire_liste_chainee_simple(ListeChaineeSimple *liste) {
    NoeudListeChaineeSimple *noeud_courant;

    if (liste == NULL) {
        return;
    }

    noeud_courant = liste->tete;
    while (noeud_courant != NULL) {
        NoeudListeChaineeSimple *noeud_suivant = noeud_courant->suivant;
        free(noeud_courant);
        noeud_courant = noeud_suivant;
    }

    liste->tete = NULL;
}

int est_vide_liste_chainee_simple(const ListeChaineeSimple *liste) {
    return liste == NULL || liste->tete == NULL;
}

int inserer_element_en_tete_liste_chainee_simple(ListeChaineeSimple *liste, int valeur) {
    NoeudListeChaineeSimple *nouveau_noeud;

    if (liste == NULL) {
        return 0;
    }

    nouveau_noeud = creer_noeud_liste_chainee_simple(valeur);
    if (nouveau_noeud == NULL) {
        return 0;
    }

    nouveau_noeud->suivant = liste->tete;
    liste->tete = nouveau_noeud;
    return 1;
}

int inserer_element_en_queue_liste_chainee_simple(ListeChaineeSimple *liste, int valeur) {
    NoeudListeChaineeSimple *nouveau_noeud;
    NoeudListeChaineeSimple *noeud_courant;

    if (liste == NULL) {
        return 0;
    }

    nouveau_noeud = creer_noeud_liste_chainee_simple(valeur);
    if (nouveau_noeud == NULL) {
        return 0;
    }

    if (liste->tete == NULL) {
        liste->tete = nouveau_noeud;
        return 1;
    }

    noeud_courant = liste->tete;
    while (noeud_courant->suivant != NULL) {
        noeud_courant = noeud_courant->suivant;
    }

    noeud_courant->suivant = nouveau_noeud;
    return 1;
}

int supprimer_premier_element_liste_chainee_simple(ListeChaineeSimple *liste, int *valeur_supprimee) {
    NoeudListeChaineeSimple *ancien_premier_noeud;

    if (liste == NULL || liste->tete == NULL) {
        return 0;
    }

    ancien_premier_noeud = liste->tete;
    liste->tete = ancien_premier_noeud->suivant;

    if (valeur_supprimee != NULL) {
        *valeur_supprimee = ancien_premier_noeud->valeur;
    }

    free(ancien_premier_noeud);
    return 1;
}

size_t longueur_liste_chainee_simple(const ListeChaineeSimple *liste) {
    size_t longueur = 0;
    const NoeudListeChaineeSimple *noeud_courant;

    if (liste == NULL) {
        return 0;
    }

    noeud_courant = liste->tete;
    while (noeud_courant != NULL) {
        longueur++;
        noeud_courant = noeud_courant->suivant;
    }

    return longueur;
}

void afficher_liste_chainee_simple(const ListeChaineeSimple *liste) {
    const NoeudListeChaineeSimple *noeud_courant;

    printf("[");
    if (liste != NULL) {
        noeud_courant = liste->tete;
        while (noeud_courant != NULL) {
            printf("%d", noeud_courant->valeur);
            if (noeud_courant->suivant != NULL) {
                printf(" -> ");
            }
            noeud_courant = noeud_courant->suivant;
        }
    }
    printf("]\n");
}
