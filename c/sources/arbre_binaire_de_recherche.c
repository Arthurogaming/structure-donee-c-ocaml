#include "arbre_binaire_de_recherche.h"

#include <stdio.h>
#include <stdlib.h>

static NoeudArbreBinaireDeRecherche *creer_noeud_arbre_binaire_de_recherche(int valeur) {
    NoeudArbreBinaireDeRecherche *nouveau_noeud = malloc(sizeof(NoeudArbreBinaireDeRecherche));

    if (nouveau_noeud == NULL) {
        return NULL;
    }

    nouveau_noeud->valeur = valeur;
    nouveau_noeud->gauche = NULL;
    nouveau_noeud->droite = NULL;
    return nouveau_noeud;
}

static void detruire_noeud_arbre_binaire_de_recherche(NoeudArbreBinaireDeRecherche *noeud) {
    if (noeud == NULL) {
        return;
    }

    detruire_noeud_arbre_binaire_de_recherche(noeud->gauche);
    detruire_noeud_arbre_binaire_de_recherche(noeud->droite);
    free(noeud);
}

static NoeudArbreBinaireDeRecherche *inserer_noeud_arbre_binaire_de_recherche(
    NoeudArbreBinaireDeRecherche *noeud,
    int valeur,
    int *insertion_reussie
) {
    if (noeud == NULL) {
        *insertion_reussie = 1;
        return creer_noeud_arbre_binaire_de_recherche(valeur);
    }

    if (valeur < noeud->valeur) {
        noeud->gauche = inserer_noeud_arbre_binaire_de_recherche(noeud->gauche, valeur, insertion_reussie);
    } else if (valeur > noeud->valeur) {
        noeud->droite = inserer_noeud_arbre_binaire_de_recherche(noeud->droite, valeur, insertion_reussie);
    } else {
        *insertion_reussie = 1;
    }

    return noeud;
}

static int rechercher_noeud_arbre_binaire_de_recherche(const NoeudArbreBinaireDeRecherche *noeud, int valeur) {
    if (noeud == NULL) {
        return 0;
    }

    if (valeur == noeud->valeur) {
        return 1;
    }

    if (valeur < noeud->valeur) {
        return rechercher_noeud_arbre_binaire_de_recherche(noeud->gauche, valeur);
    }

    return rechercher_noeud_arbre_binaire_de_recherche(noeud->droite, valeur);
}

static NoeudArbreBinaireDeRecherche *trouver_minimum_arbre_binaire_de_recherche(NoeudArbreBinaireDeRecherche *noeud) {
    NoeudArbreBinaireDeRecherche *noeud_courant = noeud;

    while (noeud_courant != NULL && noeud_courant->gauche != NULL) {
        noeud_courant = noeud_courant->gauche;
    }

    return noeud_courant;
}

static NoeudArbreBinaireDeRecherche *supprimer_noeud_arbre_binaire_de_recherche(
    NoeudArbreBinaireDeRecherche *noeud,
    int valeur,
    int *suppression_reussie
) {
    if (noeud == NULL) {
        return NULL;
    }

    if (valeur < noeud->valeur) {
        noeud->gauche = supprimer_noeud_arbre_binaire_de_recherche(noeud->gauche, valeur, suppression_reussie);
        return noeud;
    }

    if (valeur > noeud->valeur) {
        noeud->droite = supprimer_noeud_arbre_binaire_de_recherche(noeud->droite, valeur, suppression_reussie);
        return noeud;
    }

    *suppression_reussie = 1;

    if (noeud->gauche == NULL) {
        NoeudArbreBinaireDeRecherche *fils_droit = noeud->droite;
        free(noeud);
        return fils_droit;
    }

    if (noeud->droite == NULL) {
        NoeudArbreBinaireDeRecherche *fils_gauche = noeud->gauche;
        free(noeud);
        return fils_gauche;
    }

    {
        NoeudArbreBinaireDeRecherche *successeur = trouver_minimum_arbre_binaire_de_recherche(noeud->droite);
        noeud->valeur = successeur->valeur;
        noeud->droite = supprimer_noeud_arbre_binaire_de_recherche(noeud->droite, successeur->valeur, suppression_reussie);
    }

    return noeud;
}

static void parcours_prefixe_noeud_arbre_binaire_de_recherche(const NoeudArbreBinaireDeRecherche *noeud) {
    if (noeud == NULL) {
        return;
    }

    printf("%d ", noeud->valeur);
    parcours_prefixe_noeud_arbre_binaire_de_recherche(noeud->gauche);
    parcours_prefixe_noeud_arbre_binaire_de_recherche(noeud->droite);
}

static void parcours_infixe_noeud_arbre_binaire_de_recherche(const NoeudArbreBinaireDeRecherche *noeud) {
    if (noeud == NULL) {
        return;
    }

    parcours_infixe_noeud_arbre_binaire_de_recherche(noeud->gauche);
    printf("%d ", noeud->valeur);
    parcours_infixe_noeud_arbre_binaire_de_recherche(noeud->droite);
}

static void parcours_suffixe_noeud_arbre_binaire_de_recherche(const NoeudArbreBinaireDeRecherche *noeud) {
    if (noeud == NULL) {
        return;
    }

    parcours_suffixe_noeud_arbre_binaire_de_recherche(noeud->gauche);
    parcours_suffixe_noeud_arbre_binaire_de_recherche(noeud->droite);
    printf("%d ", noeud->valeur);
}

ArbreBinaireDeRecherche creer_arbre_binaire_de_recherche(void) {
    ArbreBinaireDeRecherche arbre;

    arbre.racine = NULL;
    return arbre;
}

void detruire_arbre_binaire_de_recherche(ArbreBinaireDeRecherche *arbre) {
    if (arbre == NULL) {
        return;
    }

    detruire_noeud_arbre_binaire_de_recherche(arbre->racine);
    arbre->racine = NULL;
}

int inserer_element_arbre_binaire_de_recherche(ArbreBinaireDeRecherche *arbre, int valeur) {
    int insertion_reussie = 0;

    if (arbre == NULL) {
        return 0;
    }

    arbre->racine = inserer_noeud_arbre_binaire_de_recherche(arbre->racine, valeur, &insertion_reussie);
    return insertion_reussie;
}

int rechercher_element_arbre_binaire_de_recherche(const ArbreBinaireDeRecherche *arbre, int valeur) {
    if (arbre == NULL) {
        return 0;
    }

    return rechercher_noeud_arbre_binaire_de_recherche(arbre->racine, valeur);
}

int supprimer_element_arbre_binaire_de_recherche(ArbreBinaireDeRecherche *arbre, int valeur) {
    int suppression_reussie = 0;

    if (arbre == NULL) {
        return 0;
    }

    arbre->racine = supprimer_noeud_arbre_binaire_de_recherche(arbre->racine, valeur, &suppression_reussie);
    return suppression_reussie;
}

void parcours_prefixe_arbre_binaire_de_recherche(const ArbreBinaireDeRecherche *arbre) {
    if (arbre != NULL) {
        parcours_prefixe_noeud_arbre_binaire_de_recherche(arbre->racine);
    }
    printf("\n");
}

void parcours_infixe_arbre_binaire_de_recherche(const ArbreBinaireDeRecherche *arbre) {
    if (arbre != NULL) {
        parcours_infixe_noeud_arbre_binaire_de_recherche(arbre->racine);
    }
    printf("\n");
}

void parcours_suffixe_arbre_binaire_de_recherche(const ArbreBinaireDeRecherche *arbre) {
    if (arbre != NULL) {
        parcours_suffixe_noeud_arbre_binaire_de_recherche(arbre->racine);
    }
    printf("\n");
}
