#include "union_trouver.h"

#include <stdio.h>

int main(void) {
    UnionTrouver union_trouver = creer_union_trouver(6U);

    unir_ensembles_union_trouver(&union_trouver, 0, 1);
    unir_ensembles_union_trouver(&union_trouver, 1, 2);
    unir_ensembles_union_trouver(&union_trouver, 3, 4);

    printf("Representant de 2 : %d\n", trouver_representant_union_trouver(&union_trouver, 2));
    printf("Representant de 4 : %d\n", trouver_representant_union_trouver(&union_trouver, 4));
    printf("0 et 2 sont dans le meme ensemble : %s\n",
        sont_dans_le_meme_ensemble_union_trouver(&union_trouver, 0, 2) ? "oui" : "non");
    printf("2 et 5 sont dans le meme ensemble : %s\n",
        sont_dans_le_meme_ensemble_union_trouver(&union_trouver, 2, 5) ? "oui" : "non");

    detruire_union_trouver(&union_trouver);
    return 0;
}
