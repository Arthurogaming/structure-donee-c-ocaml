#include "graphe_matrice_adjacence.h"

#include <stdio.h>
#include <stdlib.h>

static int sommet_est_valide_graphe_matrice_adjacence(const GrapheMatriceAdjacence *graphe, int sommet) {
    return graphe != NULL && sommet >= 0 && sommet < graphe->nombre_sommets;
}

GrapheMatriceAdjacence creer_graphe_matrice_adjacence(int nombre_sommets, int est_oriente) {
    GrapheMatriceAdjacence graphe;
    int indice;

    graphe.nombre_sommets = 0;
    graphe.est_oriente = est_oriente != 0;
    graphe.matrice_adjacence = NULL;

    if (nombre_sommets <= 0) {
        return graphe;
    }

    graphe.matrice_adjacence = malloc((size_t) nombre_sommets * sizeof(int *));
    if (graphe.matrice_adjacence == NULL) {
        return graphe;
    }

    for (indice = 0; indice < nombre_sommets; indice++) {
        graphe.matrice_adjacence[indice] = calloc((size_t) nombre_sommets, sizeof(int));
        if (graphe.matrice_adjacence[indice] == NULL) {
            int indice_liberation;
            for (indice_liberation = 0; indice_liberation < indice; indice_liberation++) {
                free(graphe.matrice_adjacence[indice_liberation]);
            }
            free(graphe.matrice_adjacence);
            graphe.matrice_adjacence = NULL;
            return graphe;
        }
    }

    graphe.nombre_sommets = nombre_sommets;
    return graphe;
}

void detruire_graphe_matrice_adjacence(GrapheMatriceAdjacence *graphe) {
    int indice;

    if (graphe == NULL || graphe->matrice_adjacence == NULL) {
        return;
    }

    for (indice = 0; indice < graphe->nombre_sommets; indice++) {
        free(graphe->matrice_adjacence[indice]);
    }

    free(graphe->matrice_adjacence);
    graphe->matrice_adjacence = NULL;
    graphe->nombre_sommets = 0;
}

int ajouter_arete_graphe_matrice_adjacence(GrapheMatriceAdjacence *graphe, int sommet_source, int sommet_destination) {
    if (!sommet_est_valide_graphe_matrice_adjacence(graphe, sommet_source)
        || !sommet_est_valide_graphe_matrice_adjacence(graphe, sommet_destination)) {
        return 0;
    }

    graphe->matrice_adjacence[sommet_source][sommet_destination] = 1;
    if (!graphe->est_oriente) {
        graphe->matrice_adjacence[sommet_destination][sommet_source] = 1;
    }

    return 1;
}

int retirer_arete_graphe_matrice_adjacence(GrapheMatriceAdjacence *graphe, int sommet_source, int sommet_destination) {
    if (!sommet_est_valide_graphe_matrice_adjacence(graphe, sommet_source)
        || !sommet_est_valide_graphe_matrice_adjacence(graphe, sommet_destination)) {
        return 0;
    }

    graphe->matrice_adjacence[sommet_source][sommet_destination] = 0;
    if (!graphe->est_oriente) {
        graphe->matrice_adjacence[sommet_destination][sommet_source] = 0;
    }

    return 1;
}

int arete_existe_graphe_matrice_adjacence(const GrapheMatriceAdjacence *graphe, int sommet_source, int sommet_destination) {
    if (!sommet_est_valide_graphe_matrice_adjacence(graphe, sommet_source)
        || !sommet_est_valide_graphe_matrice_adjacence(graphe, sommet_destination)) {
        return 0;
    }

    return graphe->matrice_adjacence[sommet_source][sommet_destination];
}

void afficher_graphe_matrice_adjacence(const GrapheMatriceAdjacence *graphe) {
    int indice_ligne;
    int indice_colonne;

    if (graphe == NULL || graphe->matrice_adjacence == NULL) {
        printf("Graphe non initialise.\n");
        return;
    }

    for (indice_ligne = 0; indice_ligne < graphe->nombre_sommets; indice_ligne++) {
        for (indice_colonne = 0; indice_colonne < graphe->nombre_sommets; indice_colonne++) {
            printf("%d ", graphe->matrice_adjacence[indice_ligne][indice_colonne]);
        }
        printf("\n");
    }
}
