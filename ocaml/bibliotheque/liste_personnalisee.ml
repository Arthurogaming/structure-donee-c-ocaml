type liste_personnalisee =
  | Vide
  | Noeud of int * liste_personnalisee

let creer_liste_personnalisee () = Vide

let est_vide_liste_personnalisee liste =
  match liste with
  | Vide -> true
  | Noeud _ -> false

let ajouter_element_en_tete_liste_personnalisee liste valeur =
  Noeud (valeur, liste)

let rec ajouter_element_en_queue_liste_personnalisee liste valeur =
  match liste with
  | Vide -> Noeud (valeur, Vide)
  | Noeud (valeur_courante, suite) ->
      Noeud (valeur_courante, ajouter_element_en_queue_liste_personnalisee suite valeur)

let supprimer_premier_element_liste_personnalisee liste =
  match liste with
  | Vide -> None
  | Noeud (valeur, suite) -> Some (valeur, suite)

let rec longueur_liste_personnalisee liste =
  match liste with
  | Vide -> 0
  | Noeud (_, suite) -> 1 + longueur_liste_personnalisee suite

let rec vers_liste_standard_liste_personnalisee liste =
  match liste with
  | Vide -> []
  | Noeud (valeur, suite) -> valeur :: vers_liste_standard_liste_personnalisee suite

let chaine_de_liste_personnalisee liste =
  let chaines =
    vers_liste_standard_liste_personnalisee liste
    |> List.map string_of_int
  in
  "[" ^ String.concat " ; " chaines ^ "]"
