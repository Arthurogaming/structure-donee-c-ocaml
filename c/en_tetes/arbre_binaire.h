#ifndef ARBRE_BINAIRE_H
#define ARBRE_BINAIRE_H

#include <stddef.h>

typedef struct NoeudArbreBinaire {
    int valeur;
    struct NoeudArbreBinaire *gauche;
    struct NoeudArbreBinaire *droite;
} NoeudArbreBinaire;

typedef struct {
    NoeudArbreBinaire *racine;
} ArbreBinaire;

ArbreBinaire creer_arbre_binaire(void);
void detruire_arbre_binaire(ArbreBinaire *arbre);
int definir_racine_arbre_binaire(ArbreBinaire *arbre, int valeur);
int ajouter_fils_gauche_arbre_binaire(NoeudArbreBinaire *parent, int valeur);
int ajouter_fils_droit_arbre_binaire(NoeudArbreBinaire *parent, int valeur);
size_t taille_arbre_binaire(const ArbreBinaire *arbre);
void parcours_prefixe_arbre_binaire(const ArbreBinaire *arbre);
void parcours_infixe_arbre_binaire(const ArbreBinaire *arbre);
void parcours_suffixe_arbre_binaire(const ArbreBinaire *arbre);

#endif
