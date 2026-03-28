#include "table_de_hachage.h"

#include <stdio.h>

int main(void) {
    TableDeHachage table = creer_table_de_hachage(5U);
    int valeur;

    inserer_element_table_de_hachage(&table, 1, 100);
    inserer_element_table_de_hachage(&table, 6, 600);
    inserer_element_table_de_hachage(&table, 11, 1100);

    printf("Contenu de la table :\n");
    afficher_table_de_hachage(&table);

    if (rechercher_element_table_de_hachage(&table, 6, &valeur)) {
        printf("Valeur associee a la cle 6 : %d\n", valeur);
    }

    supprimer_element_table_de_hachage(&table, 1);
    printf("Apres suppression de la cle 1 :\n");
    afficher_table_de_hachage(&table);

    detruire_table_de_hachage(&table);
    return 0;
}
