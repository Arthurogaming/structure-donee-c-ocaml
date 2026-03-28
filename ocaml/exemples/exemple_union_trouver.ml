let chaine_de_liste_entiere valeurs =
  "[" ^ String.concat " ; " (List.map string_of_int valeurs) ^ "]"

let () =
  let union_trouver = Union_trouver.creer_union_trouver 6 in
  Union_trouver.unir_ensembles_union_trouver union_trouver 0 1;
  Union_trouver.unir_ensembles_union_trouver union_trouver 1 2;
  Union_trouver.unir_ensembles_union_trouver union_trouver 3 4;
  Printf.printf "Representant de 2 : %d\n"
    (Union_trouver.trouver_representant_union_trouver union_trouver 2);
  Printf.printf "0 et 2 sont dans le meme ensemble : %b\n"
    (Union_trouver.sont_dans_le_meme_ensemble_union_trouver union_trouver 0 2);
  Printf.printf "Parents internes : %s\n"
    (chaine_de_liste_entiere (Union_trouver.parents_union_trouver union_trouver))
