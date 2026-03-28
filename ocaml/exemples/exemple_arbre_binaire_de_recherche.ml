let chaine_de_liste_entiere valeurs =
  "[" ^ String.concat " ; " (List.map string_of_int valeurs) ^ "]"

let () =
  let arbre =
    Arbre_binaire_de_recherche.creer_arbre_binaire_de_recherche_vide ()
    |> fun arbre -> Arbre_binaire_de_recherche.inserer_element_arbre_binaire_de_recherche arbre 7
    |> fun arbre -> Arbre_binaire_de_recherche.inserer_element_arbre_binaire_de_recherche arbre 4
    |> fun arbre -> Arbre_binaire_de_recherche.inserer_element_arbre_binaire_de_recherche arbre 9
    |> fun arbre -> Arbre_binaire_de_recherche.inserer_element_arbre_binaire_de_recherche arbre 2
    |> fun arbre -> Arbre_binaire_de_recherche.inserer_element_arbre_binaire_de_recherche arbre 6
  in
  Printf.printf "Parcours infixe initial : %s\n"
    (chaine_de_liste_entiere
       (Arbre_binaire_de_recherche.parcours_infixe_arbre_binaire_de_recherche arbre));
  Printf.printf "La valeur 6 est presente : %b\n"
    (Arbre_binaire_de_recherche.rechercher_element_arbre_binaire_de_recherche arbre 6);
  let arbre_sans_quatre =
    Arbre_binaire_de_recherche.supprimer_element_arbre_binaire_de_recherche arbre 4
  in
  Printf.printf "Parcours infixe apres suppression : %s\n"
    (chaine_de_liste_entiere
       (Arbre_binaire_de_recherche.parcours_infixe_arbre_binaire_de_recherche arbre_sans_quatre))
