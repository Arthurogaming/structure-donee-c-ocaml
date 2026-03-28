#ifndef GRAPHE_LISTE_ADJACENCE_H
#define GRAPHE_LISTE_ADJACENCE_H

typedef struct NoeudListeAdjacence {
    int sommet;
    struct NoeudListeAdjacence *suivant;
} NoeudListeAdjacence;

typedef struct {
    int nombre_sommets;
    int est_oriente;
    NoeudListeAdjacence **listes_adjacence;
} GrapheListeAdjacence;

GrapheListeAdjacence creer_graphe_liste_adjacence(int nombre_sommets, int est_oriente);
void detruire_graphe_liste_adjacence(GrapheListeAdjacence *graphe);
int ajouter_arete_graphe_liste_adjacence(GrapheListeAdjacence *graphe, int sommet_source, int sommet_destination);
int retirer_arete_graphe_liste_adjacence(GrapheListeAdjacence *graphe, int sommet_source, int sommet_destination);
int arete_existe_graphe_liste_adjacence(const GrapheListeAdjacence *graphe, int sommet_source, int sommet_destination);
void afficher_graphe_liste_adjacence(const GrapheListeAdjacence *graphe);

#endif
