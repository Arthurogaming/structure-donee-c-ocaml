#ifndef TABLE_DE_HACHAGE_H
#define TABLE_DE_HACHAGE_H

#include <stddef.h>

typedef struct NoeudTableDeHachage {
    int cle;
    int valeur;
    struct NoeudTableDeHachage *suivant;
} NoeudTableDeHachage;

typedef struct {
    size_t capacite;
    NoeudTableDeHachage **alveoles;
} TableDeHachage;

TableDeHachage creer_table_de_hachage(size_t capacite);
void detruire_table_de_hachage(TableDeHachage *table);
int inserer_element_table_de_hachage(TableDeHachage *table, int cle, int valeur);
int rechercher_element_table_de_hachage(const TableDeHachage *table, int cle, int *valeur);
int supprimer_element_table_de_hachage(TableDeHachage *table, int cle);
void afficher_table_de_hachage(const TableDeHachage *table);

#endif
