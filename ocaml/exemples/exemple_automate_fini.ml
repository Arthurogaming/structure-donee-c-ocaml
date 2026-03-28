let chaine_de_caracteres alphabet =
  let caracteres = List.map (String.make 1) alphabet in
  "[" ^ String.concat " ; " caracteres ^ "]"

let chaine_de_liste_entiere valeurs =
  "[" ^ String.concat " ; " (List.map string_of_int valeurs) ^ "]"

let () =
  let automate = Automate_fini.creer_automate_fini 3 [ 'a'; 'b' ] 0 in
  Automate_fini.definir_transition_automate_fini automate 0 'a' 1;
  Automate_fini.definir_transition_automate_fini automate 0 'b' 0;
  Automate_fini.definir_transition_automate_fini automate 1 'a' 1;
  Automate_fini.definir_transition_automate_fini automate 1 'b' 2;
  Automate_fini.definir_transition_automate_fini automate 2 'a' 1;
  Automate_fini.definir_transition_automate_fini automate 2 'b' 0;
  Automate_fini.definir_etat_final_automate_fini automate 2 true;
  Printf.printf "Alphabet : %s\n"
    (chaine_de_caracteres (Automate_fini.alphabet_automate_fini automate));
  Printf.printf "Etats finaux : %s\n"
    (chaine_de_liste_entiere (Automate_fini.etats_finaux_automate_fini automate));
  Printf.printf "Le mot aaab est reconnu : %b\n"
    (Automate_fini.mot_est_reconnu_automate_fini automate "aaab");
  Printf.printf "Le mot abba est reconnu : %b\n"
    (Automate_fini.mot_est_reconnu_automate_fini automate "abba")
