#ifndef PILE_H
#define PILE_H

typedef struct CellulePile {
    int valeur;
    struct CellulePile *suivante;
} CellulePile;

typedef struct {
    CellulePile *sommet;
} Pile;

Pile creer_pile(void);
void detruire_pile(Pile *pile);
int est_vide_pile(const Pile *pile);
int empiler_element_pile(Pile *pile, int valeur);
int depiler_element_pile(Pile *pile, int *valeur_depilee);
int obtenir_sommet_pile(const Pile *pile, int *valeur);

#endif
