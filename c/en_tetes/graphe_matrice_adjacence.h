#ifndef GRAPHE_MATRICE_ADJACENCE_H
#define GRAPHE_MATRICE_ADJACENCE_H

typedef struct {
    int nombre_sommets;
    int est_oriente;
    int **matrice_adjacence;
} GrapheMatriceAdjacence;

GrapheMatriceAdjacence creer_graphe_matrice_adjacence(int nombre_sommets, int est_oriente);
void detruire_graphe_matrice_adjacence(GrapheMatriceAdjacence *graphe);
int ajouter_arete_graphe_matrice_adjacence(GrapheMatriceAdjacence *graphe, int sommet_source, int sommet_destination);
int retirer_arete_graphe_matrice_adjacence(GrapheMatriceAdjacence *graphe, int sommet_source, int sommet_destination);
int arete_existe_graphe_matrice_adjacence(const GrapheMatriceAdjacence *graphe, int sommet_source, int sommet_destination);
void afficher_graphe_matrice_adjacence(const GrapheMatriceAdjacence *graphe);

#endif
