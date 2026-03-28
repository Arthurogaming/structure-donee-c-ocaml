#ifndef AUTOMATE_FINI_H
#define AUTOMATE_FINI_H

typedef struct {
    int nombre_etats;
    int taille_alphabet;
    char *alphabet;
    int **transitions;
    int etat_initial;
    int *etats_finaux;
} AutomateFini;

AutomateFini creer_automate_fini(int nombre_etats, const char *alphabet, int etat_initial);
void detruire_automate_fini(AutomateFini *automate);
int definir_transition_automate_fini(AutomateFini *automate, int etat_source, char symbole, int etat_destination);
int definir_etat_final_automate_fini(AutomateFini *automate, int etat, int est_final);
int mot_est_reconnu_automate_fini(const AutomateFini *automate, const char *mot);
void afficher_automate_fini(const AutomateFini *automate);

#endif
