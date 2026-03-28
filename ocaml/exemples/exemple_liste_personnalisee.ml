let () =
  let liste =
    Liste_personnalisee.creer_liste_personnalisee ()
    |> fun liste -> Liste_personnalisee.ajouter_element_en_tete_liste_personnalisee liste 5
    |> fun liste -> Liste_personnalisee.ajouter_element_en_tete_liste_personnalisee liste 3
    |> fun liste -> Liste_personnalisee.ajouter_element_en_queue_liste_personnalisee liste 8
  in
  Printf.printf "Liste initiale : %s\n"
    (Liste_personnalisee.chaine_de_liste_personnalisee liste);
  match Liste_personnalisee.supprimer_premier_element_liste_personnalisee liste with
  | None -> print_endline "La liste est vide."
  | Some (valeur, liste_suivante) ->
      Printf.printf "Premier element supprime : %d\n" valeur;
      Printf.printf "Liste finale : %s\n"
        (Liste_personnalisee.chaine_de_liste_personnalisee liste_suivante)
