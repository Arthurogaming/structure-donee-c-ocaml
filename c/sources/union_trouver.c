#include "union_trouver.h"

#include <stdlib.h>

static int element_est_valide_union_trouver(const UnionTrouver *union_trouver, int element) {
    return union_trouver != NULL
        && union_trouver->parents != NULL
        && union_trouver->rangs != NULL
        && element >= 0
        && (size_t) element < union_trouver->nombre_elements;
}

UnionTrouver creer_union_trouver(size_t nombre_elements) {
    UnionTrouver union_trouver;
    size_t indice;

    union_trouver.parents = NULL;
    union_trouver.rangs = NULL;
    union_trouver.nombre_elements = nombre_elements;

    if (nombre_elements == 0U) {
        return union_trouver;
    }

    union_trouver.parents = malloc(nombre_elements * sizeof(int));
    union_trouver.rangs = calloc(nombre_elements, sizeof(int));

    if (union_trouver.parents == NULL || union_trouver.rangs == NULL) {
        free(union_trouver.parents);
        free(union_trouver.rangs);
        union_trouver.parents = NULL;
        union_trouver.rangs = NULL;
        union_trouver.nombre_elements = 0U;
        return union_trouver;
    }

    for (indice = 0U; indice < nombre_elements; indice++) {
        union_trouver.parents[indice] = (int) indice;
    }

    return union_trouver;
}

void detruire_union_trouver(UnionTrouver *union_trouver) {
    if (union_trouver == NULL) {
        return;
    }

    free(union_trouver->parents);
    free(union_trouver->rangs);
    union_trouver->parents = NULL;
    union_trouver->rangs = NULL;
    union_trouver->nombre_elements = 0U;
}

int trouver_representant_union_trouver(UnionTrouver *union_trouver, int element) {
    if (!element_est_valide_union_trouver(union_trouver, element)) {
        return -1;
    }

    if (union_trouver->parents[element] != element) {
        union_trouver->parents[element] = trouver_representant_union_trouver(union_trouver, union_trouver->parents[element]);
    }

    return union_trouver->parents[element];
}

int unir_ensembles_union_trouver(UnionTrouver *union_trouver, int premier_element, int second_element) {
    int representant_premier;
    int representant_second;

    if (!element_est_valide_union_trouver(union_trouver, premier_element)
        || !element_est_valide_union_trouver(union_trouver, second_element)) {
        return 0;
    }

    representant_premier = trouver_representant_union_trouver(union_trouver, premier_element);
    representant_second = trouver_representant_union_trouver(union_trouver, second_element);

    if (representant_premier == representant_second) {
        return 1;
    }

    if (union_trouver->rangs[representant_premier] < union_trouver->rangs[representant_second]) {
        union_trouver->parents[representant_premier] = representant_second;
    } else if (union_trouver->rangs[representant_premier] > union_trouver->rangs[representant_second]) {
        union_trouver->parents[representant_second] = representant_premier;
    } else {
        union_trouver->parents[representant_second] = representant_premier;
        union_trouver->rangs[representant_premier]++;
    }

    return 1;
}

int sont_dans_le_meme_ensemble_union_trouver(UnionTrouver *union_trouver, int premier_element, int second_element) {
    int representant_premier;
    int representant_second;

    if (!element_est_valide_union_trouver(union_trouver, premier_element)
        || !element_est_valide_union_trouver(union_trouver, second_element)) {
        return 0;
    }

    representant_premier = trouver_representant_union_trouver(union_trouver, premier_element);
    representant_second = trouver_representant_union_trouver(union_trouver, second_element);
    return representant_premier == representant_second;
}
