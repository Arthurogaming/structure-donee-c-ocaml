#ifndef UNION_TROUVER_H
#define UNION_TROUVER_H

#include <stddef.h>

typedef struct {
    int *parents;
    int *rangs;
    size_t nombre_elements;
} UnionTrouver;

UnionTrouver creer_union_trouver(size_t nombre_elements);
void detruire_union_trouver(UnionTrouver *union_trouver);
int trouver_representant_union_trouver(UnionTrouver *union_trouver, int element);
int unir_ensembles_union_trouver(UnionTrouver *union_trouver, int premier_element, int second_element);
int sont_dans_le_meme_ensemble_union_trouver(UnionTrouver *union_trouver, int premier_element, int second_element);

#endif
