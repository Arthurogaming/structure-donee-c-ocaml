#ifndef FILE_DE_PRIORITE_H
#define FILE_DE_PRIORITE_H

#include <stddef.h>

typedef struct {
    int *donnees;
    size_t taille;
    size_t capacite;
} FileDePriorite;

FileDePriorite creer_file_de_priorite(size_t capacite_initiale);
void detruire_file_de_priorite(FileDePriorite *file_de_priorite);
int est_vide_file_de_priorite(const FileDePriorite *file_de_priorite);
int inserer_element_file_de_priorite(FileDePriorite *file_de_priorite, int valeur);
int supprimer_element_prioritaire_file_de_priorite(FileDePriorite *file_de_priorite, int *valeur_supprimee);
int obtenir_element_prioritaire_file_de_priorite(const FileDePriorite *file_de_priorite, int *valeur);

#endif
