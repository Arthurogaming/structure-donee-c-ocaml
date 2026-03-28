#include "file.h"

#include <stdlib.h>

File creer_file(void) {
    File file;

    file.tete = NULL;
    file.queue = NULL;
    return file;
}

void detruire_file(File *file) {
    if (file == NULL) {
        return;
    }

    while (file->tete != NULL) {
        CelluleFile *ancienne_cellule = file->tete;
        file->tete = ancienne_cellule->suivante;
        free(ancienne_cellule);
    }

    file->queue = NULL;
}

int est_vide_file(const File *file) {
    return file == NULL || file->tete == NULL;
}

int enfiler_element_file(File *file, int valeur) {
    CelluleFile *nouvelle_cellule;

    if (file == NULL) {
        return 0;
    }

    nouvelle_cellule = malloc(sizeof(CelluleFile));
    if (nouvelle_cellule == NULL) {
        return 0;
    }

    nouvelle_cellule->valeur = valeur;
    nouvelle_cellule->suivante = NULL;

    if (file->queue == NULL) {
        file->tete = nouvelle_cellule;
        file->queue = nouvelle_cellule;
        return 1;
    }

    file->queue->suivante = nouvelle_cellule;
    file->queue = nouvelle_cellule;
    return 1;
}

int defiler_element_file(File *file, int *valeur_defilee) {
    CelluleFile *ancienne_tete;

    if (file == NULL || file->tete == NULL) {
        return 0;
    }

    ancienne_tete = file->tete;
    file->tete = ancienne_tete->suivante;
    if (file->tete == NULL) {
        file->queue = NULL;
    }

    if (valeur_defilee != NULL) {
        *valeur_defilee = ancienne_tete->valeur;
    }

    free(ancienne_tete);
    return 1;
}

int obtenir_tete_file(const File *file, int *valeur) {
    if (file == NULL || file->tete == NULL || valeur == NULL) {
        return 0;
    }

    *valeur = file->tete->valeur;
    return 1;
}
