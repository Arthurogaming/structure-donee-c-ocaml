#ifndef ARBRE_BINAIRE_DE_RECHERCHE_H
#define ARBRE_BINAIRE_DE_RECHERCHE_H

typedef struct NoeudArbreBinaireDeRecherche {
    int valeur;
    struct NoeudArbreBinaireDeRecherche *gauche;
    struct NoeudArbreBinaireDeRecherche *droite;
} NoeudArbreBinaireDeRecherche;

typedef struct {
    NoeudArbreBinaireDeRecherche *racine;
} ArbreBinaireDeRecherche;

ArbreBinaireDeRecherche creer_arbre_binaire_de_recherche(void);
void detruire_arbre_binaire_de_recherche(ArbreBinaireDeRecherche *arbre);
int inserer_element_arbre_binaire_de_recherche(ArbreBinaireDeRecherche *arbre, int valeur);
int rechercher_element_arbre_binaire_de_recherche(const ArbreBinaireDeRecherche *arbre, int valeur);
int supprimer_element_arbre_binaire_de_recherche(ArbreBinaireDeRecherche *arbre, int valeur);
void parcours_prefixe_arbre_binaire_de_recherche(const ArbreBinaireDeRecherche *arbre);
void parcours_infixe_arbre_binaire_de_recherche(const ArbreBinaireDeRecherche *arbre);
void parcours_suffixe_arbre_binaire_de_recherche(const ArbreBinaireDeRecherche *arbre);

#endif
