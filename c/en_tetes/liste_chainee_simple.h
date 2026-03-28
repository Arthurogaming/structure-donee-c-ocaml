#ifndef LISTE_CHAINEE_SIMPLE_H
#define LISTE_CHAINEE_SIMPLE_H

#include <stddef.h>

typedef struct NoeudListeChaineeSimple {
    int valeur;
    struct NoeudListeChaineeSimple *suivant;
} NoeudListeChaineeSimple;

typedef struct {
    NoeudListeChaineeSimple *tete;
} ListeChaineeSimple;

ListeChaineeSimple creer_liste_chainee_simple(void);
void detruire_liste_chainee_simple(ListeChaineeSimple *liste);
int est_vide_liste_chainee_simple(const ListeChaineeSimple *liste);
int inserer_element_en_tete_liste_chainee_simple(ListeChaineeSimple *liste, int valeur);
int inserer_element_en_queue_liste_chainee_simple(ListeChaineeSimple *liste, int valeur);
int supprimer_premier_element_liste_chainee_simple(ListeChaineeSimple *liste, int *valeur_supprimee);
size_t longueur_liste_chainee_simple(const ListeChaineeSimple *liste);
void afficher_liste_chainee_simple(const ListeChaineeSimple *liste);

#endif
