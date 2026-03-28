#include "arbre_binaire.h"

#include <stdio.h>
#include <stdlib.h>

static NoeudArbreBinaire *creer_noeud_arbre_binaire(int valeur) {
    NoeudArbreBinaire *nouveau_noeud = malloc(sizeof(NoeudArbreBinaire));

    if (nouveau_noeud == NULL) {
        return NULL;
    }

    nouveau_noeud->valeur = valeur;
    nouveau_noeud->gauche = NULL;
    nouveau_noeud->droite = NULL;
    return nouveau_noeud;
}

static void detruire_noeud_arbre_binaire(NoeudArbreBinaire *noeud) {
    if (noeud == NULL) {
        return;
    }

    detruire_noeud_arbre_binaire(noeud->gauche);
    detruire_noeud_arbre_binaire(noeud->droite);
    free(noeud);
}

static size_t taille_noeud_arbre_binaire(const NoeudArbreBinaire *noeud) {
    if (noeud == NULL) {
        return 0U;
    }

    return 1U + taille_noeud_arbre_binaire(noeud->gauche) + taille_noeud_arbre_binaire(noeud->droite);
}

static void parcours_prefixe_noeud_arbre_binaire(const NoeudArbreBinaire *noeud) {
    if (noeud == NULL) {
        return;
    }

    printf("%d ", noeud->valeur);
    parcours_prefixe_noeud_arbre_binaire(noeud->gauche);
    parcours_prefixe_noeud_arbre_binaire(noeud->droite);
}

static void parcours_infixe_noeud_arbre_binaire(const NoeudArbreBinaire *noeud) {
    if (noeud == NULL) {
        return;
    }

    parcours_infixe_noeud_arbre_binaire(noeud->gauche);
    printf("%d ", noeud->valeur);
    parcours_infixe_noeud_arbre_binaire(noeud->droite);
}

static void parcours_suffixe_noeud_arbre_binaire(const NoeudArbreBinaire *noeud) {
    if (noeud == NULL) {
        return;
    }

    parcours_suffixe_noeud_arbre_binaire(noeud->gauche);
    parcours_suffixe_noeud_arbre_binaire(noeud->droite);
    printf("%d ", noeud->valeur);
}

ArbreBinaire creer_arbre_binaire(void) {
    ArbreBinaire arbre;

    arbre.racine = NULL;
    return arbre;
}

void detruire_arbre_binaire(ArbreBinaire *arbre) {
    if (arbre == NULL) {
        return;
    }

    detruire_noeud_arbre_binaire(arbre->racine);
    arbre->racine = NULL;
}

int definir_racine_arbre_binaire(ArbreBinaire *arbre, int valeur) {
    if (arbre == NULL || arbre->racine != NULL) {
        return 0;
    }

    arbre->racine = creer_noeud_arbre_binaire(valeur);
    return arbre->racine != NULL;
}

int ajouter_fils_gauche_arbre_binaire(NoeudArbreBinaire *parent, int valeur) {
    if (parent == NULL || parent->gauche != NULL) {
        return 0;
    }

    parent->gauche = creer_noeud_arbre_binaire(valeur);
    return parent->gauche != NULL;
}

int ajouter_fils_droit_arbre_binaire(NoeudArbreBinaire *parent, int valeur) {
    if (parent == NULL || parent->droite != NULL) {
        return 0;
    }

    parent->droite = creer_noeud_arbre_binaire(valeur);
    return parent->droite != NULL;
}

size_t taille_arbre_binaire(const ArbreBinaire *arbre) {
    if (arbre == NULL) {
        return 0U;
    }

    return taille_noeud_arbre_binaire(arbre->racine);
}

void parcours_prefixe_arbre_binaire(const ArbreBinaire *arbre) {
    if (arbre != NULL) {
        parcours_prefixe_noeud_arbre_binaire(arbre->racine);
    }
    printf("\n");
}

void parcours_infixe_arbre_binaire(const ArbreBinaire *arbre) {
    if (arbre != NULL) {
        parcours_infixe_noeud_arbre_binaire(arbre->racine);
    }
    printf("\n");
}

void parcours_suffixe_arbre_binaire(const ArbreBinaire *arbre) {
    if (arbre != NULL) {
        parcours_suffixe_noeud_arbre_binaire(arbre->racine);
    }
    printf("\n");
}
