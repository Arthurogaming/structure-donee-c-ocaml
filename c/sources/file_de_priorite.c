#include "file_de_priorite.h"

#include <stdlib.h>

static void echanger_valeurs_entieres(int *premiere_valeur, int *seconde_valeur) {
    int valeur_temporaire = *premiere_valeur;

    *premiere_valeur = *seconde_valeur;
    *seconde_valeur = valeur_temporaire;
}

static size_t indice_parent_file_de_priorite(size_t indice_enfant) {
    return (indice_enfant - 1U) / 2U;
}

static size_t indice_fils_gauche_file_de_priorite(size_t indice_parent) {
    return (2U * indice_parent) + 1U;
}

static size_t indice_fils_droit_file_de_priorite(size_t indice_parent) {
    return (2U * indice_parent) + 2U;
}

static void remonter_element_file_de_priorite(FileDePriorite *file_de_priorite, size_t indice_courant) {
    while (indice_courant > 0U) {
        size_t indice_parent = indice_parent_file_de_priorite(indice_courant);

        if (file_de_priorite->donnees[indice_parent] <= file_de_priorite->donnees[indice_courant]) {
            break;
        }

        echanger_valeurs_entieres(&file_de_priorite->donnees[indice_parent], &file_de_priorite->donnees[indice_courant]);
        indice_courant = indice_parent;
    }
}

static void descendre_element_file_de_priorite(FileDePriorite *file_de_priorite, size_t indice_courant) {
    while (1) {
        size_t indice_plus_petit = indice_courant;
        size_t indice_gauche = indice_fils_gauche_file_de_priorite(indice_courant);
        size_t indice_droit = indice_fils_droit_file_de_priorite(indice_courant);

        if (indice_gauche < file_de_priorite->taille
            && file_de_priorite->donnees[indice_gauche] < file_de_priorite->donnees[indice_plus_petit]) {
            indice_plus_petit = indice_gauche;
        }

        if (indice_droit < file_de_priorite->taille
            && file_de_priorite->donnees[indice_droit] < file_de_priorite->donnees[indice_plus_petit]) {
            indice_plus_petit = indice_droit;
        }

        if (indice_plus_petit == indice_courant) {
            break;
        }

        echanger_valeurs_entieres(&file_de_priorite->donnees[indice_courant], &file_de_priorite->donnees[indice_plus_petit]);
        indice_courant = indice_plus_petit;
    }
}

static int augmenter_capacite_file_de_priorite(FileDePriorite *file_de_priorite) {
    int *nouvelles_donnees;
    size_t nouvelle_capacite;

    if (file_de_priorite->capacite == 0U) {
        nouvelle_capacite = 4U;
    } else {
        nouvelle_capacite = 2U * file_de_priorite->capacite;
    }

    nouvelles_donnees = realloc(file_de_priorite->donnees, nouvelle_capacite * sizeof(int));
    if (nouvelles_donnees == NULL) {
        return 0;
    }

    file_de_priorite->donnees = nouvelles_donnees;
    file_de_priorite->capacite = nouvelle_capacite;
    return 1;
}

FileDePriorite creer_file_de_priorite(size_t capacite_initiale) {
    FileDePriorite file_de_priorite;

    file_de_priorite.taille = 0U;
    file_de_priorite.capacite = capacite_initiale == 0U ? 4U : capacite_initiale;
    file_de_priorite.donnees = malloc(file_de_priorite.capacite * sizeof(int));

    if (file_de_priorite.donnees == NULL) {
        file_de_priorite.capacite = 0U;
    }

    return file_de_priorite;
}

void detruire_file_de_priorite(FileDePriorite *file_de_priorite) {
    if (file_de_priorite == NULL) {
        return;
    }

    free(file_de_priorite->donnees);
    file_de_priorite->donnees = NULL;
    file_de_priorite->taille = 0U;
    file_de_priorite->capacite = 0U;
}

int est_vide_file_de_priorite(const FileDePriorite *file_de_priorite) {
    return file_de_priorite == NULL || file_de_priorite->taille == 0U;
}

int inserer_element_file_de_priorite(FileDePriorite *file_de_priorite, int valeur) {
    if (file_de_priorite == NULL) {
        return 0;
    }

    if (file_de_priorite->taille == file_de_priorite->capacite && !augmenter_capacite_file_de_priorite(file_de_priorite)) {
        return 0;
    }

    file_de_priorite->donnees[file_de_priorite->taille] = valeur;
    remonter_element_file_de_priorite(file_de_priorite, file_de_priorite->taille);
    file_de_priorite->taille++;
    return 1;
}

int supprimer_element_prioritaire_file_de_priorite(FileDePriorite *file_de_priorite, int *valeur_supprimee) {
    if (file_de_priorite == NULL || file_de_priorite->taille == 0U) {
        return 0;
    }

    if (valeur_supprimee != NULL) {
        *valeur_supprimee = file_de_priorite->donnees[0];
    }

    file_de_priorite->taille--;
    if (file_de_priorite->taille > 0U) {
        file_de_priorite->donnees[0] = file_de_priorite->donnees[file_de_priorite->taille];
        descendre_element_file_de_priorite(file_de_priorite, 0U);
    }

    return 1;
}

int obtenir_element_prioritaire_file_de_priorite(const FileDePriorite *file_de_priorite, int *valeur) {
    if (file_de_priorite == NULL || file_de_priorite->taille == 0U || valeur == NULL) {
        return 0;
    }

    *valeur = file_de_priorite->donnees[0];
    return 1;
}
