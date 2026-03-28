type file_de_priorite = int list

let creer_file_de_priorite () = []

let est_vide_file_de_priorite file_de_priorite =
  file_de_priorite = []

let rec inserer_element_file_de_priorite file_de_priorite valeur =
  match file_de_priorite with
  | [] -> [ valeur ]
  | valeur_courante :: reste when valeur <= valeur_courante ->
      valeur :: file_de_priorite
  | valeur_courante :: reste ->
      valeur_courante :: inserer_element_file_de_priorite reste valeur

let supprimer_element_prioritaire_file_de_priorite file_de_priorite =
  match file_de_priorite with
  | [] -> None
  | valeur :: reste -> Some (valeur, reste)

let obtenir_element_prioritaire_file_de_priorite file_de_priorite =
  match file_de_priorite with
  | [] -> None
  | valeur :: _ -> Some valeur
