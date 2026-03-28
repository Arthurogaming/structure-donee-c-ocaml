let chaine_de_liste_entiere valeurs =
  "[" ^ String.concat " ; " (List.map string_of_int valeurs) ^ "]"

let () =
  let arbre =
    Arbre_binaire.creer_noeud_arbre_binaire
      8
      (Arbre_binaire.creer_noeud_arbre_binaire
         3
         (Arbre_binaire.creer_noeud_arbre_binaire 1 Arbre_binaire.Vide Arbre_binaire.Vide)
         (Arbre_binaire.creer_noeud_arbre_binaire 6 Arbre_binaire.Vide Arbre_binaire.Vide))
      (Arbre_binaire.creer_noeud_arbre_binaire 10 Arbre_binaire.Vide Arbre_binaire.Vide)
  in
  Printf.printf "Parcours prefixe : %s\n"
    (chaine_de_liste_entiere (Arbre_binaire.parcours_prefixe_arbre_binaire arbre));
  Printf.printf "Parcours infixe : %s\n"
    (chaine_de_liste_entiere (Arbre_binaire.parcours_infixe_arbre_binaire arbre));
  Printf.printf "Parcours suffixe : %s\n"
    (chaine_de_liste_entiere (Arbre_binaire.parcours_suffixe_arbre_binaire arbre));
  Printf.printf "Taille de l'arbre : %d\n" (Arbre_binaire.taille_arbre_binaire arbre)
