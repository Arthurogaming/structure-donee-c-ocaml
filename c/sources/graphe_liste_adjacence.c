#include "graphe_liste_adjacence.h"

#include <stdio.h>
#include <stdlib.h>

static int sommet_est_valide_graphe_liste_adjacence(const GrapheListeAdjacence *graphe, int sommet) {
    return graphe != NULL && sommet >= 0 && sommet < graphe->nombre_sommets;
}

static int arete_existe_dans_liste_adjacence(const NoeudListeAdjacence *liste, int sommet_destination) {
    const NoeudListeAdjacence *noeud_courant = liste;

    while (noeud_courant != NULL) {
        if (noeud_courant->sommet == sommet_destination) {
            return 1;
        }
        noeud_courant = noeud_courant->suivant;
    }

    return 0;
}

static int ajouter_arete_dans_liste_adjacence(NoeudListeAdjacence **liste, int sommet_destination) {
    NoeudListeAdjacence *nouveau_noeud;

    if (liste == NULL) {
        return 0;
    }

    if (arete_existe_dans_liste_adjacence(*liste, sommet_destination)) {
        return 1;
    }

    nouveau_noeud = malloc(sizeof(NoeudListeAdjacence));
    if (nouveau_noeud == NULL) {
        return 0;
    }

    nouveau_noeud->sommet = sommet_destination;
    nouveau_noeud->suivant = *liste;
    *liste = nouveau_noeud;
    return 1;
}

static int retirer_arete_dans_liste_adjacence(NoeudListeAdjacence **liste, int sommet_destination) {
    NoeudListeAdjacence *noeud_courant;
    NoeudListeAdjacence *noeud_precedent = NULL;

    if (liste == NULL) {
        return 0;
    }

    noeud_courant = *liste;
    while (noeud_courant != NULL) {
        if (noeud_courant->sommet == sommet_destination) {
            if (noeud_precedent == NULL) {
                *liste = noeud_courant->suivant;
            } else {
                noeud_precedent->suivant = noeud_courant->suivant;
            }

            free(noeud_courant);
            return 1;
        }

        noeud_precedent = noeud_courant;
        noeud_courant = noeud_courant->suivant;
    }

    return 0;
}

GrapheListeAdjacence creer_graphe_liste_adjacence(int nombre_sommets, int est_oriente) {
    GrapheListeAdjacence graphe;

    graphe.nombre_sommets = 0;
    graphe.est_oriente = est_oriente != 0;
    graphe.listes_adjacence = NULL;

    if (nombre_sommets <= 0) {
        return graphe;
    }

    graphe.listes_adjacence = calloc((size_t) nombre_sommets, sizeof(NoeudListeAdjacence *));
    if (graphe.listes_adjacence == NULL) {
        return graphe;
    }

    graphe.nombre_sommets = nombre_sommets;
    return graphe;
}

void detruire_graphe_liste_adjacence(GrapheListeAdjacence *graphe) {
    int indice;

    if (graphe == NULL || graphe->listes_adjacence == NULL) {
        return;
    }

    for (indice = 0; indice < graphe->nombre_sommets; indice++) {
        NoeudListeAdjacence *noeud_courant = graphe->listes_adjacence[indice];
        while (noeud_courant != NULL) {
            NoeudListeAdjacence *noeud_suivant = noeud_courant->suivant;
            free(noeud_courant);
            noeud_courant = noeud_suivant;
        }
    }

    free(graphe->listes_adjacence);
    graphe->listes_adjacence = NULL;
    graphe->nombre_sommets = 0;
}

int ajouter_arete_graphe_liste_adjacence(GrapheListeAdjacence *graphe, int sommet_source, int sommet_destination) {
    if (!sommet_est_valide_graphe_liste_adjacence(graphe, sommet_source)
        || !sommet_est_valide_graphe_liste_adjacence(graphe, sommet_destination)) {
        return 0;
    }

    if (!ajouter_arete_dans_liste_adjacence(&graphe->listes_adjacence[sommet_source], sommet_destination)) {
        return 0;
    }

    if (!graphe->est_oriente
        && !ajouter_arete_dans_liste_adjacence(&graphe->listes_adjacence[sommet_destination], sommet_source)) {
        retirer_arete_dans_liste_adjacence(&graphe->listes_adjacence[sommet_source], sommet_destination);
        return 0;
    }

    return 1;
}

int retirer_arete_graphe_liste_adjacence(GrapheListeAdjacence *graphe, int sommet_source, int sommet_destination) {
    int suppression_reussie;

    if (!sommet_est_valide_graphe_liste_adjacence(graphe, sommet_source)
        || !sommet_est_valide_graphe_liste_adjacence(graphe, sommet_destination)) {
        return 0;
    }

    suppression_reussie = retirer_arete_dans_liste_adjacence(&graphe->listes_adjacence[sommet_source], sommet_destination);
    if (!graphe->est_oriente) {
        retirer_arete_dans_liste_adjacence(&graphe->listes_adjacence[sommet_destination], sommet_source);
    }

    return suppression_reussie;
}

int arete_existe_graphe_liste_adjacence(const GrapheListeAdjacence *graphe, int sommet_source, int sommet_destination) {
    if (!sommet_est_valide_graphe_liste_adjacence(graphe, sommet_source)
        || !sommet_est_valide_graphe_liste_adjacence(graphe, sommet_destination)) {
        return 0;
    }

    return arete_existe_dans_liste_adjacence(graphe->listes_adjacence[sommet_source], sommet_destination);
}

void afficher_graphe_liste_adjacence(const GrapheListeAdjacence *graphe) {
    int indice;

    if (graphe == NULL || graphe->listes_adjacence == NULL) {
        printf("Graphe non initialise.\n");
        return;
    }

    for (indice = 0; indice < graphe->nombre_sommets; indice++) {
        const NoeudListeAdjacence *noeud_courant = graphe->listes_adjacence[indice];
        printf("%d : ", indice);
        while (noeud_courant != NULL) {
            printf("%d", noeud_courant->sommet);
            if (noeud_courant->suivant != NULL) {
                printf(" -> ");
            }
            noeud_courant = noeud_courant->suivant;
        }
        printf("\n");
    }
}
