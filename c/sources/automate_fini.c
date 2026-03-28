#include "automate_fini.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int trouver_indice_symbole_automate_fini(const AutomateFini *automate, char symbole) {
    int indice;

    if (automate == NULL || automate->alphabet == NULL) {
        return -1;
    }

    for (indice = 0; indice < automate->taille_alphabet; indice++) {
        if (automate->alphabet[indice] == symbole) {
            return indice;
        }
    }

    return -1;
}

AutomateFini creer_automate_fini(int nombre_etats, const char *alphabet, int etat_initial) {
    AutomateFini automate;
    int indice_etat;
    size_t longueur_alphabet;

    automate.nombre_etats = 0;
    automate.taille_alphabet = 0;
    automate.alphabet = NULL;
    automate.transitions = NULL;
    automate.etat_initial = 0;
    automate.etats_finaux = NULL;

    if (nombre_etats <= 0 || alphabet == NULL) {
        return automate;
    }

    longueur_alphabet = strlen(alphabet);
    if (longueur_alphabet == 0U || etat_initial < 0 || etat_initial >= nombre_etats) {
        return automate;
    }

    automate.alphabet = malloc((longueur_alphabet + 1U) * sizeof(char));
    automate.transitions = malloc((size_t) nombre_etats * sizeof(int *));
    automate.etats_finaux = calloc((size_t) nombre_etats, sizeof(int));

    if (automate.alphabet == NULL || automate.transitions == NULL || automate.etats_finaux == NULL) {
        free(automate.alphabet);
        free(automate.transitions);
        free(automate.etats_finaux);
        automate.alphabet = NULL;
        automate.transitions = NULL;
        automate.etats_finaux = NULL;
        return automate;
    }

    strcpy(automate.alphabet, alphabet);
    for (indice_etat = 0; indice_etat < nombre_etats; indice_etat++) {
        int indice_symbole;

        automate.transitions[indice_etat] = malloc(longueur_alphabet * sizeof(int));
        if (automate.transitions[indice_etat] == NULL) {
            int indice_liberation;
            for (indice_liberation = 0; indice_liberation < indice_etat; indice_liberation++) {
                free(automate.transitions[indice_liberation]);
            }
            free(automate.transitions);
            free(automate.alphabet);
            free(automate.etats_finaux);
            automate.transitions = NULL;
            automate.alphabet = NULL;
            automate.etats_finaux = NULL;
            return automate;
        }

        for (indice_symbole = 0; indice_symbole < (int) longueur_alphabet; indice_symbole++) {
            automate.transitions[indice_etat][indice_symbole] = -1;
        }
    }

    automate.nombre_etats = nombre_etats;
    automate.taille_alphabet = (int) longueur_alphabet;
    automate.etat_initial = etat_initial;
    return automate;
}

void detruire_automate_fini(AutomateFini *automate) {
    int indice_etat;

    if (automate == NULL) {
        return;
    }

    if (automate->transitions != NULL) {
        for (indice_etat = 0; indice_etat < automate->nombre_etats; indice_etat++) {
            free(automate->transitions[indice_etat]);
        }
        free(automate->transitions);
    }

    free(automate->alphabet);
    free(automate->etats_finaux);
    automate->nombre_etats = 0;
    automate->taille_alphabet = 0;
    automate->alphabet = NULL;
    automate->transitions = NULL;
    automate->etats_finaux = NULL;
    automate->etat_initial = 0;
}

int definir_transition_automate_fini(AutomateFini *automate, int etat_source, char symbole, int etat_destination) {
    int indice_symbole;

    if (automate == NULL || etat_source < 0 || etat_source >= automate->nombre_etats
        || etat_destination < 0 || etat_destination >= automate->nombre_etats) {
        return 0;
    }

    indice_symbole = trouver_indice_symbole_automate_fini(automate, symbole);
    if (indice_symbole < 0) {
        return 0;
    }

    automate->transitions[etat_source][indice_symbole] = etat_destination;
    return 1;
}

int definir_etat_final_automate_fini(AutomateFini *automate, int etat, int est_final) {
    if (automate == NULL || etat < 0 || etat >= automate->nombre_etats) {
        return 0;
    }

    automate->etats_finaux[etat] = est_final != 0;
    return 1;
}

int mot_est_reconnu_automate_fini(const AutomateFini *automate, const char *mot) {
    const char *caractere_courant;
    int etat_courant;

    if (automate == NULL || mot == NULL || automate->transitions == NULL || automate->etats_finaux == NULL) {
        return 0;
    }

    etat_courant = automate->etat_initial;
    caractere_courant = mot;

    while (*caractere_courant != '\0') {
        int indice_symbole = trouver_indice_symbole_automate_fini(automate, *caractere_courant);

        if (indice_symbole < 0) {
            return 0;
        }

        etat_courant = automate->transitions[etat_courant][indice_symbole];
        if (etat_courant < 0) {
            return 0;
        }

        caractere_courant++;
    }

    return automate->etats_finaux[etat_courant];
}

void afficher_automate_fini(const AutomateFini *automate) {
    int indice_etat;
    int indice_symbole;

    if (automate == NULL || automate->transitions == NULL || automate->alphabet == NULL) {
        printf("Automate non initialise.\n");
        return;
    }

    printf("Etat initial : %d\n", automate->etat_initial);
    printf("Etats finaux : ");
    for (indice_etat = 0; indice_etat < automate->nombre_etats; indice_etat++) {
        if (automate->etats_finaux[indice_etat]) {
            printf("%d ", indice_etat);
        }
    }
    printf("\n");

    for (indice_etat = 0; indice_etat < automate->nombre_etats; indice_etat++) {
        for (indice_symbole = 0; indice_symbole < automate->taille_alphabet; indice_symbole++) {
            if (automate->transitions[indice_etat][indice_symbole] >= 0) {
                printf("%d --%c--> %d\n",
                    indice_etat,
                    automate->alphabet[indice_symbole],
                    automate->transitions[indice_etat][indice_symbole]);
            }
        }
    }
}
