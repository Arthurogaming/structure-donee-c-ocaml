#include "automate_fini.h"

#include <stdio.h>

int main(void) {
    AutomateFini automate = creer_automate_fini(3, "ab", 0);

    definir_transition_automate_fini(&automate, 0, 'a', 1);
    definir_transition_automate_fini(&automate, 0, 'b', 0);
    definir_transition_automate_fini(&automate, 1, 'a', 1);
    definir_transition_automate_fini(&automate, 1, 'b', 2);
    definir_transition_automate_fini(&automate, 2, 'a', 1);
    definir_transition_automate_fini(&automate, 2, 'b', 0);
    definir_etat_final_automate_fini(&automate, 2, 1);

    printf("Description de l'automate :\n");
    afficher_automate_fini(&automate);
    printf("Le mot aaab est reconnu : %s\n", mot_est_reconnu_automate_fini(&automate, "aaab") ? "oui" : "non");
    printf("Le mot abba est reconnu : %s\n", mot_est_reconnu_automate_fini(&automate, "abba") ? "oui" : "non");

    detruire_automate_fini(&automate);
    return 0;
}
