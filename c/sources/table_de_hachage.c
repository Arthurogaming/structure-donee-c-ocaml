#include "table_de_hachage.h"

#include <stdio.h>
#include <stdlib.h>

static size_t calculer_indice_table_de_hachage(const TableDeHachage *table, int cle) {
    return (size_t) ((unsigned int) cle) % table->capacite;
}

TableDeHachage creer_table_de_hachage(size_t capacite) {
    TableDeHachage table;

    table.capacite = capacite == 0U ? 1U : capacite;
    table.alveoles = calloc(table.capacite, sizeof(NoeudTableDeHachage *));

    if (table.alveoles == NULL) {
        table.capacite = 0U;
    }

    return table;
}

void detruire_table_de_hachage(TableDeHachage *table) {
    size_t indice;

    if (table == NULL || table->alveoles == NULL) {
        return;
    }

    for (indice = 0U; indice < table->capacite; indice++) {
        NoeudTableDeHachage *noeud_courant = table->alveoles[indice];
        while (noeud_courant != NULL) {
            NoeudTableDeHachage *noeud_suivant = noeud_courant->suivant;
            free(noeud_courant);
            noeud_courant = noeud_suivant;
        }
    }

    free(table->alveoles);
    table->alveoles = NULL;
    table->capacite = 0U;
}

int inserer_element_table_de_hachage(TableDeHachage *table, int cle, int valeur) {
    size_t indice;
    NoeudTableDeHachage *noeud_courant;
    NoeudTableDeHachage *nouveau_noeud;

    if (table == NULL || table->alveoles == NULL || table->capacite == 0U) {
        return 0;
    }

    indice = calculer_indice_table_de_hachage(table, cle);
    noeud_courant = table->alveoles[indice];

    while (noeud_courant != NULL) {
        if (noeud_courant->cle == cle) {
            noeud_courant->valeur = valeur;
            return 1;
        }
        noeud_courant = noeud_courant->suivant;
    }

    nouveau_noeud = malloc(sizeof(NoeudTableDeHachage));
    if (nouveau_noeud == NULL) {
        return 0;
    }

    nouveau_noeud->cle = cle;
    nouveau_noeud->valeur = valeur;
    nouveau_noeud->suivant = table->alveoles[indice];
    table->alveoles[indice] = nouveau_noeud;
    return 1;
}

int rechercher_element_table_de_hachage(const TableDeHachage *table, int cle, int *valeur) {
    size_t indice;
    const NoeudTableDeHachage *noeud_courant;

    if (table == NULL || table->alveoles == NULL || table->capacite == 0U) {
        return 0;
    }

    indice = calculer_indice_table_de_hachage(table, cle);
    noeud_courant = table->alveoles[indice];

    while (noeud_courant != NULL) {
        if (noeud_courant->cle == cle) {
            if (valeur != NULL) {
                *valeur = noeud_courant->valeur;
            }
            return 1;
        }
        noeud_courant = noeud_courant->suivant;
    }

    return 0;
}

int supprimer_element_table_de_hachage(TableDeHachage *table, int cle) {
    size_t indice;
    NoeudTableDeHachage *noeud_courant;
    NoeudTableDeHachage *noeud_precedent = NULL;

    if (table == NULL || table->alveoles == NULL || table->capacite == 0U) {
        return 0;
    }

    indice = calculer_indice_table_de_hachage(table, cle);
    noeud_courant = table->alveoles[indice];

    while (noeud_courant != NULL) {
        if (noeud_courant->cle == cle) {
            if (noeud_precedent == NULL) {
                table->alveoles[indice] = noeud_courant->suivant;
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

void afficher_table_de_hachage(const TableDeHachage *table) {
    size_t indice;

    if (table == NULL || table->alveoles == NULL) {
        printf("Table de hachage non initialisee.\n");
        return;
    }

    for (indice = 0U; indice < table->capacite; indice++) {
        const NoeudTableDeHachage *noeud_courant = table->alveoles[indice];
        printf("%zu : ", indice);
        while (noeud_courant != NULL) {
            printf("(%d, %d)", noeud_courant->cle, noeud_courant->valeur);
            if (noeud_courant->suivant != NULL) {
                printf(" -> ");
            }
            noeud_courant = noeud_courant->suivant;
        }
        printf("\n");
    }
}
